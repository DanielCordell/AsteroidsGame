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
	sf::Time		breakTime;
	bool			broken = true;
	bool			respawning = false;
	bool			dead = false;
	int				breakCount = 0;
public:
	Player(sf::Vector2u windowSize, Engine& eng);
	void			Update(sf::Time time);
	void			draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	bool			IsBroken() const { return broken; }
	bool			IsRespawning() const { return respawning; }
	void			Hit();
	void			Dead();
};
