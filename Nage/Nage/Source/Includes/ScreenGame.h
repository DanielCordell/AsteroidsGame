#pragma once
#include "IScreen.h"
#include "Player.h"
#include "BulletHandler.h"

class ScreenGame : public IScreen {
private:
	Player			player;
	BulletHandler	bulletHandler;
	sf::Sound		shoot;
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
