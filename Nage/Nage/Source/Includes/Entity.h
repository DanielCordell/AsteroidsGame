#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Entity : public sf::Drawable {
protected:
	sf::Sprite		sprite;
	sf::Vector2f	vel;
	int				angle; // In Degrees
	sf::Vector2u	windowSize = {1920,1080};
	bool shouldDelete;
	sf::Texture& texture;
public:
	Entity(sf::Texture& texture, int angle)
		: angle(angle), shouldDelete(false), texture(texture) {}

	void WrapAround();
	const sf::Vector2f	GetPosition() const { return sprite.getPosition(); }
	const sf::FloatRect	GetBounds() const { return sprite.getGlobalBounds(); }
	const bool			ShouldDelete() const { return shouldDelete; }
	void				SetDelete() { shouldDelete = true; }
	int					GetAngle() const { return angle; }
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};