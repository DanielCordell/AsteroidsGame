#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
#include "Includes/Engine.h"
#include "Includes/DiceRoller.h"

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
		window.display();
	}
}
