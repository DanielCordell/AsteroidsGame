#include "Includes/Player.h"

Player::Player(sf::Vector2u windowSize, Engine& eng) : vel(0,0), angle(0), thrust(eng.SoundManager.Get(IDSound::THRUST)), texStill(eng.TexManager.Get(IDTexture::PLAYER)), texMove(eng.TexManager.Get(IDTexture::PLAYER_MOVE))
{
	this->windowSize = windowSize;
	thrust.setLoop(true);

	sprite.setTexture(texStill);
	sprite.setScale(0.3, 0.3);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
	sprite.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);
}

void Player::Update() {
	int angleChange = 0;
	sf::Vector2f velChange(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		angleChange -= 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		angleChange += 5;
	if (angleChange > 360) angleChange -= 360;
	if (angleChange < 0) angleChange += 360;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velChange.x = sin(-angle * tgui::pi / 180.f) / 6.f;
		velChange.y = cos(angle * tgui::pi / 180.f) / 6.f;
		vel += velChange;
	}
	if (angleChange != 0 || velChange != sf::Vector2f(0, 0)) {
		if (thrust.getStatus() != sf::Sound::Playing) thrust.play();
		sprite.setTexture(texMove);
		angle += angleChange;
	}
	else {
		if (thrust.getStatus() == sf::Sound::Playing) thrust.stop();
		sprite.setTexture(texStill);
	}

	//Friction
	vel.x *= .99f;
	vel.y *= .99f;
	sprite.move(vel);

	//Adjust position if off screen
	sf::Vector2f positionChange(0, 0);
	if (sprite.getPosition().x + sprite.getLocalBounds().width / 2.f < 0) {
		positionChange.x += (sprite.getLocalBounds().width / 2.f + windowSize.x);
		std::cout << "LEFT\n";
	}
	else if (sprite.getPosition().x - sprite.getLocalBounds().width / 2.f >= windowSize.x){
		positionChange.x -= (sprite.getLocalBounds().width / 2.f + windowSize.x);
		std::cout << "RIGHT\n";
	}
	if (sprite.getPosition().y + sprite.getLocalBounds().height / 2.f < 0) {
		positionChange.y += (sprite.getLocalBounds().height / 2.f + windowSize.y);
		std::cout << "UP\n";
	}
	else if (sprite.getPosition().y - sprite.getLocalBounds().height / 2.f >= windowSize.y) {
		positionChange.y -= (sprite.getLocalBounds().height / 2.f + windowSize.y);
		std::cout << "DOWN\n";
	}
		sprite.move(positionChange);
	sprite.setRotation(angle);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
