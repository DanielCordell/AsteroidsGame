#include "SFML/Graphics.hpp"
#include "Includes/EngineLogger.h"
#include "Includes/IResourceManager.h"

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Startup Initialised");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Testing TextureManager");
	IResourceManager<sf::Texture, IDTexture> TexManager;
	TexManager.Load(IDTexture::one,"Resources/Test.png");
	sf::Sprite sprite(TexManager.Get(IDTexture::one));
	sprite.setPosition(500, 300);
	EngineLogger::Log(EngineLogger::LOG_INFO, "Success");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Testing SoundManager");
	IResourceManager<sf::SoundBuffer, IDSound> SoundManager;
	SoundManager.Load(IDSound::one, "Resources/Test.wav");
	sf::Sound sound(SoundManager.Get(IDSound::one));
	EngineLogger::Log(EngineLogger::LOG_INFO, "Success");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Testing MusicManager");
	IResourceManager<sf::Music, IDMusic> MusicManager;
	MusicManager.Load(IDMusic::one, "Resources/Test2.wav");
	sf::Music & music(MusicManager.Get(IDMusic::one));
	EngineLogger::Log(EngineLogger::LOG_INFO, "Success");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Testing FontManager");
	IResourceManager<sf::Font, IDFont> FontManager;
	FontManager.Load(IDFont::one, "Resources/Test.ttf");
	sf::Text text("OH HELLO THERE", FontManager.Get(IDFont::one));
	text.setPosition(200, 200);
	EngineLogger::Log(EngineLogger::LOG_INFO, "Success");

	EngineLogger::Log(EngineLogger::LOG_INFO, "Testing ShaderManager");
	IResourceManager<sf::Shader, IDShader> ShaderManager;
	auto test = sf::Shader::Type::Fragment;
	ShaderManager.Load(IDShader::one, "Resources/Test.glsl", test);
	sf::Shader & shader(ShaderManager.Get(IDShader::one));
	EngineLogger::Log(EngineLogger::LOG_INFO, "Success");


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					sound.play();
					music.stop();
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					music.play();
				}
				break;
			default: 
				break;
			}
		}

		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(sprite,&ShaderManager.Get(IDShader::one));
		window.display();

	}
}