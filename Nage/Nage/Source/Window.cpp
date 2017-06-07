#include "Includes/Window.h"
#include "Includes/EngineLogger.h"

Window::Window(const std::string title, const sf::Vector2u size) {
	Setup(title, size);
	drawStarted = false;
}
Window::~Window() {
	Destroy();
}

void Window::DrawStart() {
	if (drawStarted) EngineLogger::Log(EngineLogger::LOG_ERROR, "Draw has already started (DrawEnd not called)");
	else drawStarted = true;
	window.clear(sf::Color::Black);
}
void Window::DrawEnd() {
	if (!drawStarted) EngineLogger::Log(EngineLogger::LOG_ERROR, "Draw has not started (DrawStart not called)");
	else drawStarted = false;
	window.display();
}
void Window::Draw(sf::Drawable& drawable) {
	window.draw(drawable);
}

void Window::Draw(sf::Drawable& drawable, sf::RenderStates& states) {
	window.draw(drawable, states);
}

void Window::Setup(const std::string& title, const sf::Vector2u& size) {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Initialising Window");
	windowTitle = title;
	windowSize = size;
	isFullscreen = false; //TODO: Settings file
	isDone = false;
	Create();
}
void Window::Create() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Creating Window");
	auto style = isFullscreen ? sf::Style::Fullscreen : sf::Style::Close | sf::Style::Titlebar;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle, style);
	//changeView(windowSize.x, windowSize.y);
}
void Window::Destroy() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Destroying Window");
	window.close();
}

void Window::Recreate() {
	Destroy();
	Create();
}
