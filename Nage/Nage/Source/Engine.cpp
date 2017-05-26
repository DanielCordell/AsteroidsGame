#include <SFML/Graphics/Shader.hpp>

#include "Includes/Engine.h"
#include "Includes/ResourceManager.h"
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

void Engine::Events(Engine& engine)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) { if (!window.IsFullscreen()) window.ToggleFullscreen(); }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) { if (window.IsFullscreen()) window.ToggleFullscreen(); }
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) window.Recreate();

	sf::Event event;
	while (window.pollEvent(event)) {
		//if (event.type == sf::Event::Resized) window.changeView(event.size.width, event.size.height);
	}
}

void Engine::Update(Engine& engine)
{
}

void Engine::Draw(Engine& engine)
{
	window.DrawStart();
	sf::Sprite sprite(TexManager.Get(IDTexture::one));
	sprite.setScale(10, 5);
	window.Draw(sprite);
	window.DrawEnd();
}
