#pragma once

class Engine;

class IScreen {
protected:
	const bool isTransparant;
	Engine& engine;
public:
	IScreen(Engine& eng, bool transparant) : isTransparant(transparant), engine(eng) {}

	//Setup and Destroy
	virtual bool Init() = delete;
	virtual bool Cleanup() = delete;

	//Temp Transitions? TODO: See if I will ever use
	virtual void Pause() = delete;
	virtual void Resume() = delete;

	//Main Functions
	virtual void HandleEvents() = delete;
	virtual void Update() = delete;
	virtual void Draw() = delete;

	const bool IsTransparant() const { return isTransparant; }
	virtual ~IScreen() {}
};
