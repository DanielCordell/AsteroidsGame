#pragma once

#include "SFML/Graphics/Sprite.hpp"

#include "Engine.h"
#include "Entity.h"

class Bullet : public Entity {
private:
	sf::Clock clock;
	bool shouldDelete;

	sf::Texture& texture;
public:
	enum shotSpeed {
		slow = 5,
		normal = 10,
		fast = 15
	};

	Bullet(sf::Vector2f position, shotSpeed speed, int ang, sf::Texture& tex, sf::Vector2u winSize);
	void				Update();
	void				draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	const sf::Vector2f	GetPosition() const;
	const sf::FloatRect	GetBounds() const;
	const bool			ShouldDelete() const;
};
