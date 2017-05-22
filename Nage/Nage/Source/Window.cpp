#include "Includes/Window.h"
#include "Includes/EngineLogger.h"

Window::Window(const std::string title, const sf::Vector2u size) {
	Setup(title, size);
}
Window::~Window() {
	Destroy();
}

void Window::DrawStart() {
	window.clear();
}
void Window::DrawEnd() {
	window.display();
}
void Window::Draw(sf::Drawable& drawable) {
	window.draw(drawable);
}

void Window::Draw(sf::Drawable& drawable, sf::RenderStates& states) {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Drawing Object");
	window.draw(drawable, states);
}

void Window::Setup(const std::string& title, const sf::Vector2u& size) {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Initialising Window");
	windowTitle = title;
	windowSize = size;
	isFullscreen = true; //TODO: Settings file
	isDone = false;
	Create();
}
void Window::Create() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Creating Window");
	auto style = isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle, style);
}
void Window::Destroy() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Destroying Window");
	window.close();
}

void Window::Recreate() {
	Destroy();
	Create();
}
