#include "Includes/ScreenMainMenu.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"

#include "SFML/Window/Event.hpp"

void ScreenMainMenu::Init() {
	tgui::Theme::Ptr theme = tgui::Theme::create("D:/Daniels PC/Documents/Source/AsteroidsGame/Nage/TGUI-0.7/widgets/BabyBlue.txt");
	tgui::Button::Ptr button = theme->load("Button");
	button->setSize(200, 60);
	button->setTextSize(0);
	button->setPosition(600, 600);
	button->setText("SANIC");
	button->connect("pressed", [&]()
	{
		if (!isPlaying) engine.MusicManager.Get(IDMusic::one).play();
		else			engine.MusicManager.Get(IDMusic::one).pause();
		isPlaying = !isPlaying;
	});

	gui.add(button);
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
		if (event.type == sf::Event::Closed) window.Done();
		gui.handleEvent(event);
	}
}

void ScreenMainMenu::Update() {
	
}

void ScreenMainMenu::Draw()  {
	Window& window = engine.getWindow();
	gui.draw();
}


