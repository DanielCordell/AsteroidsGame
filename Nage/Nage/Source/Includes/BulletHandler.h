#pragma once

#include <vector>

#include "Bullet.h"

class BulletHandler : public sf::Drawable {
private:
	Engine& engine;
	std::vector<std::unique_ptr<Bullet>> bullets;
	sf::Texture& bulletTexture;
public:
	BulletHandler(Engine& eng);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void Update();
	void CreateBullet(sf::Vector2f pos, Bullet::shotSpeed speed, int angle);
};
