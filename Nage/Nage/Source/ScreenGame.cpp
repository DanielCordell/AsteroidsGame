#include "Includes/ScreenGame.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"
#include "Includes/DiceRoller.h"

ScreenGame::ScreenGame(Engine& eng) : IScreen(eng, false), player({ 1920,1080 }, eng), bulletHandler(eng),
asteroidHandler(eng.TexManager.Get(IDTexture::ASTEROID_LARGE), eng.TexManager.Get(IDTexture::ASTEROID_NORMAL), eng.TexManager.Get(IDTexture::ASTEROID_TINY)), 
starfield(sf::Vector2f( 1920, 1080 ), 400, sf::Color::White),
explode(eng.SoundManager.Get(IDSound::EXPLODE)),
shoot(eng.SoundManager.Get(IDSound::SHOOT))
{
	Init();
	scoreboard.setFont(eng.FontManager.Get(IDFont::one));
	shotTimer = sf::Time::Zero;
}

void ScreenGame::Init() {
	score = 0;
	lives = 3;
	scoreboard.setPosition(10, 10);
	scoreboard.setFillColor(sf::Color::White);
}

void ScreenGame::Cleanup() {
	gui->removeAllWidgets();
	gui.release();
}

void ScreenGame::HandleEvents() {
	sf::Event event;
	Window& window = engine.GetWindow();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) engine.PopScreen();
		}
		if (event.type == sf::Event::Closed) window.Done();
		if (event.type == sf::Event::Resized) 
			window.Resize(sf::Vector2u(event.size.width, event.size.height));
		if (gui) gui->handleEvent(event);
	}
}

void ScreenGame::Update() {
	bulletHandler.Update();
	asteroidHandler.Update();
	bool gameOver = lives <= 0;
	if (!gameOver) {
		player.Update(clock.getElapsedTime());
		int prevScore = score;
		bool doExplode = false;
		score += asteroidHandler.HandleCollision(bulletHandler);
		if (score != prevScore) doExplode = true;
		if (asteroidHandler.HandleCollision(player)) {
			lives -= 1;
			doExplode = true;
			player.Hit();
		}
		if (doExplode) {
			int pitchMult = DiceRoller::RollSum(1, 5);
			explode.setPitch(pitchMult * 0.2f + 0.7f);
			explode.play();
		}
		shotTimer += clock.getElapsedTime();
		if (!player.IsRespawning() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shotTimer.asMilliseconds() > 200) {
			int pitchMult = DiceRoller::RollSum(1, 5);
			shoot.setPitch(pitchMult * 0.1f + 0.7f);
			shoot.play();
			bulletHandler.CreateBullet(player.GetPosition(), 10, player.GetAngle());
			shotTimer = sf::Time::Zero;
		}
		scoreboard.setString("Score: " + std::to_string(score) + "\nLives: " + std::to_string(lives));
		clock.restart();
	}
	else {
		scoreboard.setCharacterSize(60);
		scoreboard.setString("Game Over!\nFinal Score: " + std::to_string(score));
		if (clock.getElapsedTime().asSeconds() > 3.f) {
			engine.PopScreen();
		}
	}
	starfield.move({ 3,4 });
}

void ScreenGame::Draw() {
	auto& window = engine.GetWindow();
	window.Draw(starfield);
	window.Draw(asteroidHandler);
	window.Draw(player);
	window.Draw(bulletHandler);
	window.Draw(scoreboard);
}
