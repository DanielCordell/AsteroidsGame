#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Entity : public sf::Drawable {
protected:
	sf::Sprite		sprite;
	sf::Vector2f	vel;
	int				angle; // In Degrees
	sf::Vector2u	windowSize;
public:
	void WrapAround();
};