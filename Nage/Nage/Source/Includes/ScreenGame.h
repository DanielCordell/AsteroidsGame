#pragma once
#include "IScreen.h"
#include "Player.h"
#include "BulletHandler.h"

#include "Starfield.hpp"
#include "AsteroidHandler.h"

class ScreenGame : public IScreen {
private:
	int				score;
	int				lives;
	Player			player;
	BulletHandler	bulletHandler;
	AsteroidHandler asteroidHandler;
	sw::Starfield	starfield;
	sf::Sound		explode;
	sf::Sound		shoot;
	sf::Text		scoreboard;
	sf::Clock		clock;
	sf::Time		shotTimer;
public:
	ScreenGame(Engine& eng);
	//Setup and Destroy
	void Init() override;
	void Cleanup() override;

	//Main Functions
	void HandleEvents() override;
	void Update() override;
	void Draw() override;
};
