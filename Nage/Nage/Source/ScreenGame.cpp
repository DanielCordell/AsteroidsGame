#include "Includes/ScreenGame.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"

ScreenGame::ScreenGame(Engine& eng) : IScreen(eng, false), player(eng.GetWindow().GetSize(),eng) {
	auto windowSize = engine.GetWindow().GetSize();
	Init();
}

void ScreenGame::Init() {
}

void ScreenGame::Cleanup() {
	gui->removeAllWidgets();
	gui.release();
}

void ScreenGame::HandleEvents() {
	sf::Event event;
	bool doesPop = false;
	Window& window = engine.GetWindow();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) doesPop = true;
		}
		if (event.type == sf::Event::Closed) doesPop = true;

		if (gui)
			gui->handleEvent(event);
	}
	if (doesPop) engine.PopScreen();
}

void ScreenGame::Update() {
	player.Update();
}

void ScreenGame::Draw() {
	auto& window = engine.GetWindow();
	window.Draw(player);
}
