#include "Includes/Window.h"
#include "Includes/EngineLogger.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <queue>

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
	sf::RectangleShape rect{ sf::Vector2f(1920,1080) };
	rect.setFillColor(sf::Color(0, 26, 51));
	window.draw(rect);
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

void Window::ToggleFullscreen() {
	isFullscreen = !isFullscreen;
	Recreate();
}

void Window::Resize(sf::Vector2u size) {
	windowSize = size; 
	window.setSize(windowSize);
	ChangeView();
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
	auto style = isFullscreen ? sf::Style::Fullscreen : sf::Style::Close | sf::Style::Resize;
	window.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle, style);
	ChangeView();
}
void Window::Destroy() {
	EngineLogger::Log(EngineLogger::LOG_INFO, "Destroying Window");
	window.close();
}

void Window::ChangeView() {
	if (windowView == nullptr) windowView = std::make_unique<sf::View>(window.getView());
	sf::View view(*windowView);
	float windowRatio = windowSize.x / static_cast<float>(windowSize.y);
	float viewRatio = view.getSize().x / static_cast<float>(view.getSize().y);
	float sizeX, sizeY, posX, posY;

	if (windowRatio > viewRatio) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.f;
		sizeY = 1;
		posY = 0;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.f;
		sizeX = 1;
		posX = 0;
	}
	view.setViewport(sf::FloatRect(sf::FloatRect(posX, posY, sizeX, sizeY)));
	window.setView(view);
}

void Window::Recreate() {
	Destroy();
	Create();
}
