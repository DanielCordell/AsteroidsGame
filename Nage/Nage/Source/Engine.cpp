#include <SFML/Graphics/Shader.hpp>

#include "Includes/Engine.h"
#include "Includes/ResourceManager.h"
#include "Includes/ScreenMainMenu.h"

Engine::Engine(sf::String title, sf::Vector2u size): window(title, size) {}

void Engine::Init(Engine &)
{

	//Loading Textures
	TexManager.Load(IDTexture::one, "Resources/Test.png");

	//Loading Sounds
	SoundManager.Load(IDSound::one, "Resources/Test.wav");
	
	//Loading Music
	MusicManager.Load(IDMusic::one, "Resources/Test2.wav");
	
	//Loading Fonts
	FontManager.Load(IDFont::one, "Resources/Test.ttf");
	
	//Loading Shaders
	ShaderManager.Load(IDShader::one, "Resources/Test.glsl", sf::Shader::Type::Fragment);

	Screens.push_back(std::make_unique<ScreenMainMenu>(*this,false));
}

void Engine::Cleanup()
{
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
