#include <SFML/Graphics/Shader.hpp>

#include "Includes/Engine.h"
#include "Includes/IResourceManager.h"

Engine::Engine() {
}

bool Engine::Init(Engine &)
{

	//Loading Textures
	//TexManager.Load(IDTexture::one, "Resources/Test.png");

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

void Engine::Events(Engine &)
{
}

void Engine::Update(Engine &)
{
}

void Engine::Draw(Engine &)
{
}
