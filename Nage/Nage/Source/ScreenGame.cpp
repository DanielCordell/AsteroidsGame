#include "Includes/ScreenGame.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"
#include "Includes/DiceRoller.h"

ScreenGame::ScreenGame(Engine& eng) : IScreen(eng, false), player(eng.GetWindow().GetSize(),eng), bulletHandler(eng),
	shoot(eng.SoundManager.Get(IDSound::SHOOT))
{
	auto windowSize = engine.GetWindow().GetSize();
	Init();
}

void ScreenGame::Init() {
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

		if (gui) gui->handleEvent(event);
	}
}

void ScreenGame::Update() {
	player.Update();
	bulletHandler.Update();
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && shoot.getStatus() != shoot.Playing) { //TODO change to shot timer
		int pitchMult = DiceRoller::RollSum(1, 5);
		shoot.setPitch(pitchMult * 0.1f + 0.7f);
		shoot.play();
		bulletHandler.CreateBullet(player.GetPosition(), Bullet::normal, player.GetAngle());
	}
}

void ScreenGame::Draw() {
	auto& window = engine.GetWindow();
	window.Draw(player);
	window.Draw(bulletHandler);
}
