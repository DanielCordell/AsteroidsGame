#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

#include "Includes/Engine.h"
#include "Includes/IResourceManager.h"


Engine::Engine() {

	//Generating Missing Texture
	sf::RenderTexture tex;
	sf::Text text2("MISSINGTEX", FontManager.Get(IDFont::one));
	tex.create(128, 128);
	tex.clear(sf::Color::Magenta);
	tex.draw(text2);
	tex.display();

	//Defining Default Resources
	TexManager = IResourceManager<sf::Texture, IDTexture>(std::make_shared<sf::Texture>(tex.getTexture()));
	SoundManager = IResourceManager<sf::SoundBuffer, IDSound>();
	MusicManager = IResourceManager<sf::Music, IDMusic>();
	FontManager = IResourceManager<sf::Font, IDFont>();
	ShaderManager = IResourceManager<sf::Shader, IDShader>();
}

bool Engine::Init(Engine &)
{

	//Loading Textures
	TexManager.Load(IDTexture::one, "Resources/Test.png");

	//Loading Sounds
	SoundManager.Load(IDSound::one, "Resources/Test.wav");
	
	//Loading Music

	std::shared_ptr<sf::Music> music;
	music->openFromFile("Resources/Test2.wav");
	MusicManager.Load(IDMusic::one, music);
	
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
