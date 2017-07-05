#include "Includes/Bullet.h"

Bullet::Bullet(sf::Vector2f pos, shotSpeed speed, int ang, Engine& eng): angle(ang), pos(pos),
	texture(eng.TexManager.Get(IDTexture::BULLET)) {
	vel.x = speed * sin(angle * tgui::pi / 180.f);
	vel.y = speed * cos(angle * tgui::pi / 180.f);
}

void Bullet::Update() {
	sprite.move(vel);
}

void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

const sf::Vector2f Bullet::GetPosition() const
{
	return pos;
}

const sf::FloatRect Bullet::GetBounds() const
{
	return sprite.getGlobalBounds();
}
