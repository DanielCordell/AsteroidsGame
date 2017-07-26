#include "Includes/Asteroid.h"
#include "Includes/DiceRoller.h"


Asteroid::Asteroid(AsteroidType type, sf::Texture& texture) : Entity(texture, DiceRoller::RollSum(1, 360)), type(type) {
	shouldDelete = false;
	sprite.setTexture(texture);
	
	this->sprite.setPosition(DiceRoller::RollSum(1, 1920), DiceRoller::RollSum(1, 1080));
	this->vel = sf::Vector2f(DiceRoller::RollSum(1, 5) - 2.5f, DiceRoller::RollSum(1, 5) - 2.5f);
	this->sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	this->sprite.setColor(sf::Color::White);
}

Asteroid::Asteroid(AsteroidType type, sf::Texture& texture, sf::Vector2f position) : Entity(texture, DiceRoller::RollSum(1, 360)), type(type) {
	shouldDelete = false;
	sprite.setTexture(texture);

	this->sprite.setPosition(position);
	this->vel = sf::Vector2f(DiceRoller::RollSum(1, 5) - 2.5f, DiceRoller::RollSum(1, 5) - 2.5f);
	this->sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
}

void Asteroid::Update() {
	sprite.move(vel);
	WrapAround();
}
