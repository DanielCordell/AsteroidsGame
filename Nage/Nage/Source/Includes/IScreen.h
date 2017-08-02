#pragma once
#include "TGUI/TGUI.hpp"

class Engine;

class IScreen {
protected:
	const bool isTransparant;
	Engine& engine;
	std::unique_ptr<tgui::Gui> gui;
public:
	virtual ~IScreen() = default;
	IScreen(Engine& eng, bool transparant);


	//Setup and Destroy
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	//Main Functions
	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	const bool IsTransparant() const;

	enum Type {
		MAIN_MENU,
		GAME,
		SETTINGS,
		END_GAME
	};
};
