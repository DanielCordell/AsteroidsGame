#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include "ResourceManager.h"
#include "Window.h"

class Engine {
public:
	Engine(sf::String title, sf::Vector2u size);
	bool Init(Engine&);
	void Cleanup();

	void Events(Engine&);

	void Update(Engine&);

	void Draw(Engine&);

	Window& getWindow() { return window; }

private:
	Window window;

	// std::vector<std::shared_ptr<IGameState>> States


public:
	// Resource Managers
	ResourceManager<sf::Texture, IDTexture>		TexManager;
	ResourceManager<sf::SoundBuffer, IDSound>	SoundManager;
	ResourceManager<sf::Music, IDMusic>			MusicManager;
	ResourceManager<sf::Font, IDFont>			FontManager;
	ResourceManager<sf::Shader, IDShader>		ShaderManager;
};
