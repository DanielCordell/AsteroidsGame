#include "Includes/ScreenMainMenu.h"
#include <SFML/Window/Event.hpp>
#include "Includes/Window.h"
#include "Includes/Engine.h"

void ScreenMainMenu::Init() {
	sprite.setTexture(engine.TexManager.Get(IDTexture::one));
	sprite.setScale(10, 10);

	shape.setSize({500,500});
	shape.setFillColor(sf::Color::Green);

}

void ScreenMainMenu::Cleanup() {
	
}


void ScreenMainMenu::HandleEvents() {
	sf::Event event;
	Window& window = engine.getWindow();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			sf::Vector2f movement(0, 0);
			switch (event.key.code) {
			case sf::Keyboard::W:
				movement.x += 2;
				break;
			case sf::Keyboard::S:
				movement.x -= 2;
				break;
			case sf::Keyboard::A:
				movement.y -= 2;
				break;
			case sf::Keyboard::D:
				movement.y += 2;
				break;
			default:
				break;
			}
			sprite.move(movement);
		}
		else if (event.type == sf::Event::Closed) window.Done();
	}
}

void ScreenMainMenu::Update() {
	
}

void ScreenMainMenu::Draw()  {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Drawing Objects");
	Window& window = engine.getWindow();
	window.Draw(sprite);
	window.Draw(shape);

}


