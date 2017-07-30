#include "Includes/ScreenMainMenu.h"
#include "Includes/Window.h"
#include "Includes/Engine.h"

void ScreenMainMenu::Init() {
	tgui::Theme::Ptr theme = tgui::Theme::create("Resources/babyblue.txt");
	auto screenSize = engine.GetWindow().GetSize();
	std::cout << screenSize.x << " " << screenSize.y << "\n";
	const tgui::Layout2d buttonSize(280 / 1920.f * screenSize.x, 100 / 1080.f * screenSize.y);

	//Label for Description
	tgui::Label::Ptr label = theme->load("Label");
	label->hide();
	label->setTextSize(40 / 1920 * screenSize.x);
	label->setAutoSize(true);
	label->setPosition(screenSize.x / 2.f - bindWidth(label)/2.f, screenSize.y / 16.f * 14.f);
	gui->add(label, "label");

	//Creating the Play Button
	tgui::Button::Ptr play = theme->load("Button");
	play->setSize(buttonSize);
	play->setPosition(.1f * screenSize.x, .2f * screenSize.y);
	play->setText("Play");
	play->setTextSize(60 / 1920 * screenSize.x);
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
	settings->setTextSize(60 / 1920 * screenSize.x);
	settings->setPosition(.1f * screenSize.x, .32f * screenSize.y > 108 ? .32f * screenSize.y : 108.f);
	settings->setText("Settings");
	gui->add(settings, "settings");

	//Creating the Quit Button
	tgui::Button::Ptr quit = theme->load("Button");
	quit->setSize(buttonSize);
	quit->setTextSize(60 / 1920 * screenSize.x);
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
		if (event.type == sf::Event::Resized) {
			window.Resize(sf::Vector2u(event.size.width, event.size.height));
			gui->setView(window.GetView());
		}
		if (gui) gui->handleEvent(event);
	}
}

void ScreenMainMenu::Update() {
}

void ScreenMainMenu::Draw()  {
	gui->draw();
}


