#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "IResourceManager.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

class Engine {
public:
	bool Init(Engine&);
	void Cleanup();


	void Events(Engine&);

	void Update(Engine&);

	void Draw(Engine&);

private:
	sf::RenderWindow window;

	// std::vector<std::shared_ptr<IGameState>> _States



	// Resource Managers
	IResourceManager<sf::Texture, IDTexture>	TexManager;
	IResourceManager<sf::SoundBuffer, IDSound>	SoundManager;
	IResourceManager<sf::Music, IDMusic>		MusicManager;
	IResourceManager<sf::Font, IDFont>			FontManager;
	IResourceManager<sf::Shader, IDShader>		ShaderManager;
};
