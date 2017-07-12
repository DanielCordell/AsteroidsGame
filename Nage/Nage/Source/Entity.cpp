#include "Includes\Entity.h"
#include <iostream>

void Entity::WrapAround()
{
	//Adjust position if off screen
	sf::Vector2f positionChange(0, 0);
	std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
	if (sprite.getPosition().x + sprite.getLocalBounds().width / 2.f < 0) {
		positionChange.x += (sprite.getLocalBounds().width / 2.f + windowSize.x);
	}
	else if (sprite.getPosition().x - sprite.getLocalBounds().width / 2.f >= windowSize.x) {
		positionChange.x -= (sprite.getLocalBounds().width / 2.f + windowSize.x);
	}
	if (sprite.getPosition().y + sprite.getLocalBounds().height / 2.f < 0) {
		positionChange.y += (sprite.getLocalBounds().height / 2.f + windowSize.y);
	}
	else if (sprite.getPosition().y - sprite.getLocalBounds().height / 2.f >= windowSize.y) {
		positionChange.y -= (sprite.getLocalBounds().height / 2.f + windowSize.y);
	}
	sprite.move(positionChange);

	if (angle > 360) angle -= 360;
	if (angle < 0) angle += 360;
	sprite.setRotation(angle);
}
