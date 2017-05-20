#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include "IResourceManager.h"

class Engine {
public:
	Engine();
	bool Init(Engine&);
	void Cleanup();


	void Events(Engine&);

	void Update(Engine&);

	void Draw(Engine&);

private:
	sf::RenderWindow window;

	// std::vector<std::shared_ptr<IGameState>> States


public:
	// Resource Managers
	IResourceManager<sf::Texture, IDTexture>	TexManager;
	IResourceManager<sf::SoundBuffer, IDSound>	SoundManager;
	IResourceManager<sf::Music, IDMusic>		MusicManager;
	IResourceManager<sf::Font, IDFont>			FontManager;
	IResourceManager<sf::Shader, IDShader>		ShaderManager;
};
