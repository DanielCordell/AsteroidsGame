#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/Sound.hpp"

#include "Engine.h"
#include "Entity.h"

class Player : public Entity {
private:
	sf::Texture&	texStill;
	sf::Texture&	texMove;

	sf::Sound		thrust;
public:
	Player(sf::Vector2u windowSize, Engine& eng);
	void			Update();
	void			draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
