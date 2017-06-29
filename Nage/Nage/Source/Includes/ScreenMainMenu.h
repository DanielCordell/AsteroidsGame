#pragma once
#include "IScreen.h"

class ScreenMainMenu : public IScreen {
public:
	ScreenMainMenu(Engine& eng) : IScreen(eng, false) { Init(); }

	//Setup and Destroy
	void Init() override;
	void Cleanup() override;

	//Main Functions
	void HandleEvents() override;
	void Update() override;
	void Draw() override;
};
