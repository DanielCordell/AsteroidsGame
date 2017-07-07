#include <SFML/Graphics/Shader.hpp>

#include "Includes/Engine.h"
#include "Includes/ResourceManager.h"
#include "Includes/ScreenMainMenu.h"
#include "Includes/ScreenGame.h"

Engine::Engine(sf::String title, sf::Vector2u size): window(title, size) {}

void Engine::Init(Engine &)
{
	//Loading Textures
	TexManager.Load(IDTexture::ASTEROID_HUGE, "Resources/asteroidhuge.png");
	TexManager.Load(IDTexture::ASTEROID_LARGE, "Resources/asteroidlarge.png");
	TexManager.Load(IDTexture::ASTEROID_NORMAL, "Resources/asteroid.png");
	TexManager.Load(IDTexture::ASTEROID_TINY, "Resources/asteroidtiny.png");
	TexManager.Load(IDTexture::PLAYER, "Resources/player.png");
	TexManager.Load(IDTexture::PLAYER_MOVE, "Resources/playermove.png");
	TexManager.Load(IDTexture::BULLET, "Resources/bullet.png");

	
	//Loading Sounds
	SoundManager.Load(IDSound::THRUST, "Resources/thrust.wav");
	SoundManager.Load(IDSound::SHOOT, "Resources/shoot.wav");

	//Loading Music
	MusicManager.Load(IDMusic::one, "Resources/Test2.wav");
	
	//Loading Fonts
	FontManager.Load(IDFont::one, "Resources/Test.ttf");
	
	//Loading Shaders
	ShaderManager.Load(IDShader::one, "Resources/Test.glsl", sf::Shader::Type::Fragment);

	MainMenu();
}

void Engine::Cleanup()
{
	for (auto& screen : Screens) {
		screen->Cleanup();
	}
	Screens.clear();
}

void Engine::Events(Engine& engine)
{
	Screens.back()->HandleEvents();
}

void Engine::Update(Engine& engine)
{
	Screens.back()->Update();
}

void Engine::Draw(Engine& engine)
{
	window.DrawStart();
	if (Screens.back()->IsTransparant() && Screens.size() > 1) {
		Screens.end()[-2]->Draw();
	}
	Screens.back()->Draw();
	window.DrawEnd();
}

void Engine::PushScreen(IScreen::Type type)
{
	EngineLogger::Log(EngineLogger::LOG_INFO, "Creating Screen of ID " + std::to_string(type));
	std::unique_ptr<IScreen> newScreen;
	switch (type) {
	case IScreen::MAIN_MENU:
		Screens.push_back(std::make_unique<ScreenMainMenu>(*this));
		break;
	case IScreen::GAME:
		Screens.push_back(std::make_unique<ScreenGame>(*this));
		break;
	//TODO: More Cases
	default:
		EngineLogger::Log(EngineLogger::LOG_WARNING, "PushScreen enum is invalid - Doing nothing");
		break;

	}
}
void Engine::PopScreen()
{
	EngineLogger::Log(EngineLogger::LOG_INFO, "Attempting to Destroy Screen");
	if (Screens.size() > 1) {
		Screens.back()->Cleanup();
		Screens.pop_back();
	}
	else{
		EngineLogger::Log(EngineLogger::LOG_WARNING, "Trying to destroy a screen that would leave no valid screens - Doing nothing");
	}
	EngineLogger::Log(EngineLogger::LOG_INFO, "Screen Destroyed");
}

void Engine::ReplaceScreen(IScreen::Type type)
{
	PopScreen();
	PushScreen(type);
}

void Engine::MainMenu()
{
	if (Screens.empty()) {
		PushScreen(IScreen::MAIN_MENU);
	}
	else {
		while (Screens.size() > 1) {
			Screens.pop_back();
		}
	}
}
