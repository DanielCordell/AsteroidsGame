#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
#include "Includes/Engine.h"
#include <windows.h>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Startup Initialised");

	Engine engine;
	engine.Init(engine);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default: 
				break;
			}
		}
		sf::Sprite sprite;
		sprite.setTexture(engine.TexManager.Get(IDTexture::one));
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}
}
