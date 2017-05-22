#include "Includes/Window.h"
#include "Includes/EngineLogger.h"

Window::Window(const std::string title, const sf::Vector2u size) {
	Setup(title, size);
}
Window::~Window() {
	Destroy();
}

void Window::DrawStart() {
	window.clear(sf::Color::Black);
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
	isFullscreen = false; //TODO: Settings file
	isDone = false;
	Create();
}
void Window::Create() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Creating Window");
	auto style = isFullscreen ? sf::Style::Fullscreen : sf::Style::Resize | sf::Style::Close;
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

void Window::changeView(int width, int height)
{
	EngineLogger::Log(EngineLogger::LOG_INFO, "Adjusting View");
	sf::View view = window.getView();
	float windowRatio = width / height;
	float viewRatio = view.getSize().x / view.getSize().y;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	if (windowRatio < viewRatio) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
	}
	window.setView(sf::View({ posX, posY, sizeX, sizeY }));
}