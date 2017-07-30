#include "Includes/Entity.h"
#include <SFML/Graphics/RenderTarget.hpp>

void Entity::WrapAround()
{
	//Adjust position if off screen
	sf::Vector2f positionChange(0, 0);
	if (sprite.getPosition().x + sprite.getGlobalBounds().width / 2.f < 0) {
		positionChange.x += (sprite.getGlobalBounds().width / 2.f + windowSize.x);
	}
	else if (sprite.getPosition().x - sprite.getGlobalBounds().width / 2.f >= windowSize.x) {
		positionChange.x -= (sprite.getGlobalBounds().width / 2.f + windowSize.x);
	}
	if (sprite.getPosition().y + sprite.getGlobalBounds().height / 2.f < 0) {
		positionChange.y += (sprite.getGlobalBounds().height / 2.f + windowSize.y);
	}
	else if (sprite.getPosition().y - sprite.getGlobalBounds().height / 2.f >= windowSize.y) {
		positionChange.y -= (sprite.getGlobalBounds().height / 2.f + windowSize.y);
	}
	sprite.move(positionChange);

	if (angle >= 360) angle -= 360;
	if (angle < 0) angle += 360;
	sprite.setRotation(angle);
}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
