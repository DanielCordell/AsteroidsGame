#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "Engine.h"

class Bullet : public sf::Drawable {
private:
	sf::Sprite sprite;
	sf::Texture& texture;

	sf::Vector2f		pos;
	sf::Vector2f		vel;
	int					angle; // In Degrees
public:
	enum shotSpeed {
		slow = 1,
		normal = 2,
		fast = 3
	};

	Bullet(sf::Vector2f position, shotSpeed speed, int ang, Engine& eng);
	void				Update();
	void				draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	const sf::Vector2f	GetPosition() const;
	const sf::FloatRect	GetBounds() const;
};
