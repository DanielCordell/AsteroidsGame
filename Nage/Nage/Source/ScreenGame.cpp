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
			if (event.key.code == sf::Keyboard::Escape) window.Done();
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

	player.Update(clock.restart());
	if (!gameOver) {
			score += asteroidHandler.HandleCollision(bulletHandler);
			if (asteroidHandler.HandleCollision(player)) {
				lives -= 1;
				explode.play();
				player.Break();
			}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && shoot.getStatus() != shoot.Playing) { //TODO change to shot timer
			int pitchMult = DiceRoller::RollSum(1, 5);
			shoot.setPitch(pitchMult * 0.1f + 0.7f);
			shoot.play();
			bulletHandler.CreateBullet(player.GetPosition(), 10, player.GetAngle());
		}
	}
	starfield.move({ 3,4 });

	scoreboard.setString("Score: " + std::to_string(score) + "\nLives: " + std::to_string(lives));

}

void ScreenGame::Draw() {
	auto& window = engine.GetWindow();
	window.Draw(scoreboard);
	window.Draw(starfield);
	window.Draw(asteroidHandler);
	window.Draw(player);
	window.Draw(bulletHandler);
}
