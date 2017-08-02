#pragma once
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>

#include "ResourceManager.h"
#include "Window.h"
#include "IScreen.h"

class Engine {
public:
	// Resource Managers
	ResourceManager<sf::Texture, IDTexture>		TexManager;
	ResourceManager<sf::SoundBuffer, IDSound>	SoundManager;
	ResourceManager<sf::Music, IDMusic>			MusicManager;
	ResourceManager<sf::Font, IDFont>			FontManager;
	ResourceManager<sf::Shader, IDShader>		ShaderManager;

	//Basic Game Functions
	Engine(sf::String title, sf::Vector2u size);
	void Init(Engine&);
	void Cleanup();
	void Events(Engine&);
	void Update(Engine&);
	void Draw(Engine&);
	Window& GetWindow() { return window; }

	//Adding and removing Screens
	void PushScreen(IScreen::Type type);
	void PopScreen();
	void ReplaceScreen(IScreen::Type type);
	void MainMenu();
private:
	Window window;
	std::vector<std::unique_ptr<IScreen>> Screens;
	sf::Music* music;
};
