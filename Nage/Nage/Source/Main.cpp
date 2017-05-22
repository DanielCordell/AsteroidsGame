#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
#include "Includes/Engine.h"

int main() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Startup Initialised");

	sf::Vector2u size = { sf::VideoMode::getFullscreenModes()[0].width, sf::VideoMode::getFullscreenModes()[0].height }; //TODO: Load from Settings
	Engine engine("Title",size); //TODO: THIS STUFF
	engine.Init(engine);

	sf::Clock clock;
	while (!engine.getWindow().IsDone()) {
		sf::Time time(clock.getElapsedTime());
		engine.Events(engine, time);
		engine.Update(engine, time);
		engine.Draw(engine, time);
		}
	EngineLogger::Log(EngineLogger::LOG_INFO, "Goodbye!");
}

