#pragma once

#include "SFML/Graphics/Sprite.hpp"

#include "Engine.h"

class Bullet : public sf::Drawable {
private:
	sf::Clock clock;
	bool shouldDelete;

	sf::Sprite sprite;
	sf::Texture& texture;

	sf::Vector2f		pos;
	sf::Vector2f		vel;
	int					angle; // In Degrees
public:
	enum shotSpeed {
		slow = 5,
		normal = 10,
		fast = 15
	};

	Bullet(sf::Vector2f position, shotSpeed speed, int ang, sf::Texture& tex);
	void				Update();
	void				draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	const sf::Vector2f	GetPosition() const;
	const sf::FloatRect	GetBounds() const;
	const bool			ShouldDelete() const;
};
