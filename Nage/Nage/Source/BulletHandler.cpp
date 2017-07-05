#include "Includes\BulletHandler.h"

BulletHandler::BulletHandler(Engine & eng): bulletTexture(eng.TexManager.Get(IDTexture::BULLET)), engine(eng) {}

void BulletHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	for (auto&& bullet : bullets) {
		target.draw(*bullet, states);
	}
}

void BulletHandler::Update() {
	for (auto&& bullet : bullets){
		bullet->Update();
	}
	for (auto i = bullets.begin(); i != bullets.end();) {
		if ((*i)->ShouldDelete()) i = bullets.erase(i);
		else ++i;
	}
}

void BulletHandler::CreateBullet(sf::Vector2f pos, Bullet::shotSpeed speed, int angle) {
	bullets.push_back(std::make_unique<Bullet>(pos, speed, angle, bulletTexture));
}
