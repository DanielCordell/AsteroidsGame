#include <SFML/Graphics/Shader.hpp>

#include "Includes/Engine.h"
#include "Includes/IResourceManager.h"
#include <SFML/Window/Event.hpp>

Engine::Engine(sf::String title, sf::Vector2u size): window(title, size) {}

bool Engine::Init(Engine &)
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

	return true;
}

void Engine::Cleanup()
{
}

void Engine::Events(Engine& engine, sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
		window.ToggleFullscreen();
		window.Rereate();
	};
}

void Engine::Update(Engine& engine, sf::Time dt)
{
}

void Engine::Draw(Engine& engine, sf::Time dt)
{
}
