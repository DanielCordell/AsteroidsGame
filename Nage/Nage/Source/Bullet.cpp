#include "Includes/Bullet.h"

Bullet::Bullet(sf::Vector2f pos, shotSpeed speed, int ang, sf::Texture& tex, sf::Vector2u winSize): shouldDelete(false), texture(tex) {
	windowSize = winSize;
	angle = ang;
	vel.x = speed * sin(-angle * tgui::pi / 180.f);
	vel.y = speed * cos(angle * tgui::pi / 180.f);
	sprite.setTexture(texture);
	float creationOffset = texture.getSize().y / 2.0f;
	sf::Vector2f position = pos;
	position.x += creationOffset * sin(-angle * tgui::pi / 180.f);
	position.y += creationOffset * cos(angle * tgui::pi / 180.f);
	sprite.setPosition(position);
	sprite.setRotation(angle);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
}

void Bullet::Update() {
	if (clock.getElapsedTime().asSeconds() > 1)  shouldDelete = true;
	sprite.move(vel);
	WrapAround();
}

void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

const sf::Vector2f Bullet::GetPosition() const {
	return sprite.getPosition();
}

const sf::FloatRect Bullet::GetBounds() const {
	return sprite.getGlobalBounds();
}

const bool Bullet::ShouldDelete() const {
	return shouldDelete;
}