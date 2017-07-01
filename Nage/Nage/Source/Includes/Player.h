#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/Sound.hpp"
#include "Engine.h"

class Player : public sf::Drawable {
private:
	sf::Sprite		sprite;
	sf::Texture&	texStill;
	sf::Texture&	texMove;

	sf::Sound		thrust;
	sf::Sound		shoot;

	sf::Vector2f	pos;
	sf::Vector2f	vel;
	int				angle; // In Degrees
	sf::Vector2u	windowSize;
public:
	Player(sf::Vector2u windowSize, Engine& eng);
	void Update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};
