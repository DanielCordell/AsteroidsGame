#include "Includes/Player.h"

Player::Player(sf::Vector2u windowSize, Engine& eng) : Entity(texStill,0),
texStill(eng.TexManager.Get(IDTexture::PLAYER)),
texMove(eng.TexManager.Get(IDTexture::PLAYER_MOVE)),
thrust(eng.SoundManager.Get(IDSound::THRUST)) {
	vel = {0,0};
	this->windowSize = windowSize;
	thrust.setLoop(true);
	sprite.setTexture(texStill);
	sprite.setScale(0.3, 0.3);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
	angle = 180;
}

void Player::Update(sf::Time time) {
	if (!broken && breakCount < 3) {
		sprite.setColor(sf::Color::White);
		sf::Vector2f velChange(0, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			velChange.x = sin(-angle * tgui::pi / 180.f) / 6.f;
			velChange.y = cos(angle * tgui::pi / 180.f) / 6.f;
			vel += velChange;
		}
		if (velChange != sf::Vector2f(0, 0)) {
			if (thrust.getStatus() != sf::Sound::Playing) thrust.play();
			sprite.setTexture(texMove);
		}
		else {
			if (thrust.getStatus() == sf::Sound::Playing) thrust.stop();
			sprite.setTexture(texStill);
		}

		//Friction
		vel.x *= .985f;
		vel.y *= .985f;

		int angleChange = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			angleChange -= 5;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			angleChange += 5;

		angle += angleChange;
		sprite.move(vel);
		WrapAround();
	}else {
		thrust.stop();
		sprite.setColor(sf::Color::Transparent);
		breakTime += time;
	}
	if (broken && breakTime.asSeconds() > 3.f) {
		broken = false;
		sprite.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
		sprite.setTexture(texStill);
		breakTime = sf::Time::Zero;
		vel = sf::Vector2f(0, 0);
		angle = 180;
		++breakCount;
	}
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
