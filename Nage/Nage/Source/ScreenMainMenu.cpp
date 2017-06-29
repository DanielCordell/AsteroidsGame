#include "Includes/ScreenMainMenu.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"

void ScreenMainMenu::Init() {
	tgui::Theme::Ptr theme = tgui::Theme::create("D:/Daniels PC/Documents/Source/AsteroidsGame/Nage/TGUI-0.7/widgets/BabyBlue.txt");
	auto screenSize = engine.GetWindow().GetSize();
	const tgui::Layout2d buttonSize(280, 100);

	//Label for Description
	tgui::Label::Ptr label = theme->load("Label");
	label->hide();
	label->setTextSize(40);
	label->setAutoSize(true);
	label->setPosition(screenSize.x / 2.f - bindWidth(label)/2.f, screenSize.y / 16.f * 14.f);
	gui->add(label, "label");

	//Creating the Play Button
	tgui::Button::Ptr play = theme->load("Button");
	play->setSize(buttonSize);
	play->setPosition(.1f * screenSize.x, .2f * screenSize.y);
	play->setText("Play");
	play->setTextSize(60);
	play->connect("pressed", [&]()
	{
		engine.PushScreen(GAME);
	});
	play->connect("mouseentered", [](tgui::Label::Ptr& l)
	{
		l->setText("Get Ready!");
		l->show();

	}, label);
	play->connect("mouseLeft", [](tgui::Label::Ptr& l)
	{
		l->hide();
	}, label);
	gui->add(play, "play");

	//Creating the Settings Button
	tgui::Button::Ptr settings = theme->load("Button");
	settings->setSize(buttonSize);
	settings->setTextSize(60);
	settings->setPosition(.1f * screenSize.x, .32f * screenSize.y > 108 ? .32f * screenSize.y : 108.f);
	settings->setText("Settings");
	gui->add(settings, "settings");

	//Creating the Quit Button
	tgui::Button::Ptr quit = theme->load("Button");
	quit->setSize(buttonSize);
	quit->setTextSize(60);
	quit->setPosition(.1f * screenSize.x, .32f * screenSize.y > 108 ? .44f * screenSize.y : 108.f);
	quit->setText("Quit");

	quit->connect("mouseentered", [](tgui::Label::Ptr& l)
	{
		l->setText("Are You Sure?");
		l->show();

	},label);
	quit->connect("mouseLeft", [](tgui::Label::Ptr& l)
	{
		l->hide();
	},label);
	quit->connect("pressed", &Window::Done, &engine.GetWindow());
	gui->add(quit, "quit");
}

void ScreenMainMenu::Cleanup() {
	gui->removeAllWidgets();
	gui = nullptr;
}


void ScreenMainMenu::HandleEvents() {
	sf::Event event;
	Window& window = engine.GetWindow();
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) window.Done();
		}
		if (event.type == sf::Event::Closed) window.Done();
		
		if (gui) gui->handleEvent(event);
	}
}

void ScreenMainMenu::Update() {
}

void ScreenMainMenu::Draw()  {
	Window& window = engine.GetWindow();
	gui->draw();
}


