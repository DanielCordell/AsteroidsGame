#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
#include "Includes/Engine.h"

int main() {
	try {
		EngineLogger::Log(EngineLogger::LOG_INFO, "Startup Initialised");
		auto videomode = sf::VideoMode::getDesktopMode();
		sf::Vector2u size = { videomode.width, videomode.height };
		Engine engine("Title", size); 
		engine.Init(engine);
		sf::Clock clock;
		sf::Time elapsedTime;
		float frameTime = 1.0f / 60.0f;
		while (!engine.GetWindow().IsDone()) {
			elapsedTime += clock.restart();
			engine.Events(engine);
			bool shouldUpdate = elapsedTime.asSeconds() >= frameTime;
			if (shouldUpdate) {
				engine.Update(engine);
				engine.Draw(engine);
				elapsedTime = sf::Time::Zero;
			}
		}
		engine.Cleanup();
		EngineLogger::Log(EngineLogger::LOG_INFO, "Goodbye!");
	}
	catch(tgui::Exception e) {
		std::cout << e.what();
		system("pause");
	}
	return 0;
}


