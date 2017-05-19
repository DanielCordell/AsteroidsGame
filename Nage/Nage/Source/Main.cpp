#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Startup Initialised");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
				}
				break;
			default: 
				break;
			}
		}


		window.clear(sf::Color::Black);
		window.display();
	}
}