#pragma once

#include "SFML/Graphics/Sprite.hpp"

#include "Engine.h"
#include "Entity.h"

class Bullet : public Entity {
private:
	sf::Clock clock;
public:

	Bullet(sf::Vector2f position, int speed, int ang, sf::Texture& tex, sf::Vector2u winSize);
	void Update();
};
