#pragma once
#include <string>

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


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

	const bool IsDone() const { return isDone; }
	const bool IsFullscreen() const { return isFullscreen; }

	void Rereate(); // Destroys THEN Creates the window

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
};
