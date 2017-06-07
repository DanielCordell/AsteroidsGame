#pragma once
#include "TGUI/TGUI.hpp"

class Engine;

class IScreen {
protected:
	const bool isTransparant;
	Engine& engine;
	tgui::Gui gui;
public:
	virtual ~IScreen() = default;
	IScreen(Engine& eng, bool transparant);


	//Setup and Destroy
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	/*
	//Temp Transitions? TODO: See if I will ever use
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	*/
	//Main Functions
	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	const bool IsTransparant() const;
};
