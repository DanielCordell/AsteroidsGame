#pragma once
#include "IScreen.h"

class ScreenMainMenu : public IScreen {
	bool isPlaying = false;

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
