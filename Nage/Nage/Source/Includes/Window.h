#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"


class Window {
public:
	Window(const std::string title, const sf::Vector2u size);
	~Window();

	void DrawStart(); // Clear Window
	void DrawEnd(); // Update Window

	//Draw to window
	void Draw(sf::Drawable& drawable);
	void Draw(sf::Drawable& drawable, sf::RenderStates& states); 

	// Needs to call Recreate() for settings to take effect
	void ToggleFullscreen() { isFullscreen = !isFullscreen; }
	// Needs to call Recreate() for settings to take effect
	void Resize(sf::Vector2u& size) { windowSize = size; }

	void Done() { isDone = true; }

	//Standard Pollevent Function
	bool pollEvent(sf::Event& event) { return window.pollEvent(event); }
	

	const bool IsDone() const { return isDone; }
	const bool IsFullscreen() const { return isFullscreen; }
	const sf::Vector2u GetSize() const { return window.getSize(); }


	void Recreate(); // Destroys THEN Creates the window

	operator sf::RenderWindow&() { return window; }
private:
	// Window Initialisation (should only be called at the start)
	void Setup(const std::string& title, const sf::Vector2u& size); 

	void Create(); // Creates the window
	void Destroy(); // Destroys the window

	sf::RenderWindow	window;
	sf::Vector2u		windowSize;
	std::string			windowTitle;

	bool isFullscreen;
	bool isDone;
	bool drawStarted;
};
