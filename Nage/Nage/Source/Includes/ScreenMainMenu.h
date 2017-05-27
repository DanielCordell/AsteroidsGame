#pragma once
#include "IScreen.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class ScreenMainMenu : public IScreen {
	sf::Sprite sprite; //Temp
	sf::RectangleShape shape; //Temp

public:
	ScreenMainMenu(Engine& eng, bool transparant) : IScreen(eng, transparant) { Init(); }

	//Setup and Destroy
	void Init() override;
	void Cleanup() override;

	//Main Functions
	void HandleEvents() override;
	void Update() override;
	void Draw() override;
};