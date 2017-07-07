#include "Includes/Bullet.h"

Bullet::Bullet(sf::Vector2f pos, shotSpeed speed, int ang, sf::Texture& tex): shouldDelete(false), texture(tex), pos(pos), angle(ang) {
	vel.x = speed * sin(-angle * tgui::pi / 180.f);
	vel.y = speed * cos(angle * tgui::pi / 180.f);
	sprite.setTexture(texture);
	float creationOffset = texture.getSize().y / 2.0f;
	pos.x += creationOffset * sin(-angle * tgui::pi / 180.f);
	pos.y += creationOffset * cos(angle * tgui::pi / 180.f);
	sprite.setPosition(pos);
	sprite.setRotation(ang);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
}

void Bullet::Update() {
	if (clock.getElapsedTime().asSeconds() > 1)  shouldDelete = true;
	sprite.move(vel);
}

void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

const sf::Vector2f Bullet::GetPosition() const {
	return pos;
}

const sf::FloatRect Bullet::GetBounds() const {
	return sprite.getGlobalBounds();
}

const bool Bullet::ShouldDelete() const {
	return shouldDelete;
}