#include "Includes/ScreenMainMenu.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"

#include "SFML/Window/Event.hpp"

void ScreenMainMenu::Init() {

}

void ScreenMainMenu::Cleanup() {
	
}


void ScreenMainMenu::HandleEvents() {
	sf::Event event;
	Window& window = engine.getWindow();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) window.Done();
		}
	}
}

void ScreenMainMenu::Update() {
	
}

void ScreenMainMenu::Draw()  {
	Window& window = engine.getWindow();

}


