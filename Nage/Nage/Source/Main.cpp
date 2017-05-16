#include <iostream>
#include "Includes/EngineLogger.h"
#include "SFML/Graphics.hpp"

int main() {
	sf::RectangleShape rect(sf::Vector2f(50,40));

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");

	EngineLogger::Log(EngineLogger::LogLevel::LOG_INFO, "Renderer successfully initialised.");

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

		window.clear(sf::Color::Black);
		window.draw(rect);
		window.display();

	}
}