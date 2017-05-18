#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
#include "Includes/IResourceManager.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Startup Initialised");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Testing TextureManager");
	IResourceManager<sf::Texture, IDTexture> TexManager;
	TexManager.Load(IDTexture::one,"Resources/test.png");



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
		window.display();

	}
}