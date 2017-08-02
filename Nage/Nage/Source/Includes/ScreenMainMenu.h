#pragma once
#include "IScreen.h"
#include "Starfield.hpp"

class ScreenMainMenu : public IScreen {
public:
	ScreenMainMenu(Engine& eng) : IScreen(eng, false), starfield(sf::Vector2f(1920, 1080), 400, sf::Color::White) { Init(); }
	selbaward::Starfield starfield;
	sf::Sprite title;
	//Setup and Destroy
	void Init() override;
	void Cleanup() override;

	//Main Functions
	void HandleEvents() override;
	void Update() override;
	void Draw() override;
};
