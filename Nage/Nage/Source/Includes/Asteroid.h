#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"

class Asteroid : public Entity {
public:
	enum AsteroidType {
		none,
		small = 170,
		medium = 150,
		large = 100,
	};
	const AsteroidType type;

	Asteroid(AsteroidType type, sf::Texture& texture);
	Asteroid(AsteroidType type, sf::Texture& texture, sf::Vector2f position);
	void Update();
};
