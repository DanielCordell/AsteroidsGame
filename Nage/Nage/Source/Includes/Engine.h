#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include "IResourceManager.h"
#include "Window.h"

class Engine {
public:
	Engine(sf::String title, sf::Vector2u size);
	bool Init(Engine&);
	void Cleanup();

	void Events(Engine&, sf::Time dt);

	void Update(Engine&, sf::Time dt);

	void Draw(Engine&, sf::Time dt);

	Window& getWindow() { return window; }

private:
	Window window;

	// std::vector<std::shared_ptr<IGameState>> States


public:
	// Resource Managers
	IResourceManager<sf::Texture, IDTexture>	TexManager;
	IResourceManager<sf::SoundBuffer, IDSound>	SoundManager;
	IResourceManager<sf::Music, IDMusic>		MusicManager;
	IResourceManager<sf::Font, IDFont>			FontManager;
	IResourceManager<sf::Shader, IDShader>		ShaderManager;
};
