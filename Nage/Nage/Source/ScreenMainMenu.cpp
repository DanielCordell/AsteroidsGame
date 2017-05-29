#include "Includes/ScreenMainMenu.h"
#include <SFML/Window/Event.hpp>
#include "Includes/Window.h"
#include "Includes/Engine.h"

void ScreenMainMenu::Init() {
	sprite.setTexture(engine.TexManager.Get(IDTexture::one));
	sprite.setScale(10, 10);

	shape.setSize({200,200});
	shape.setFillColor(sf::Color::Green);

}

void ScreenMainMenu::Cleanup() {
	
}


void ScreenMainMenu::HandleEvents() {
	bool movementChanged = false;
	sf::Event event;
	Window& window = engine.getWindow();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.Done();
	}
}

void ScreenMainMenu::Update() {
	bool isMoving = false;
	sf::Vector2f movement(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { movement.y -= 5 * speedmult; isMoving = true; }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {movement.y += 5 * speedmult; isMoving = true;}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { movement.x -= 5 * speedmult; isMoving = true; }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { movement.x += 5 * speedmult; isMoving = true; }
	else isMoving = false;
	shape.move(movement);

	if (isMoving) {
		tempTime += tempClock.restart();
		if (tempTime.asSeconds() > 1) {
			speedmult = 3;
			shape.setFillColor(sf::Color::Blue);
			auto status = engine.MusicManager.Get(IDMusic::one).getStatus();
			if (status == sf::SoundSource::Stopped || status == sf::SoundSource::Paused) engine.MusicManager.Get(IDMusic::one).play();
		}
	}
	else {
		shape.setFillColor(sf::Color::Green);
		tempClock.restart();
		tempTime = sf::Time::Zero;
		engine.MusicManager.Get(IDMusic::one).pause();
		speedmult = 1;
	}
}

void ScreenMainMenu::Draw()  {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Drawing Objects");
	Window& window = engine.getWindow();
	window.Draw(sprite);
	window.Draw(shape);

}


