#include "Includes/Engine.h"
#include "Includes/IResourceManager.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>

bool Engine::Init(Engine &)
{

	//Generating Missing Texture
	sf::RenderTexture tex;
	sf::Text text2("MISSINGTEX", FontManager.Get(IDFont::one));
	int texSize = text2.getLocalBounds().width;
	tex.create(128, 128);
	tex.clear(sf::Color::Magenta);
	tex.draw(text2);
	tex.display();

	//Defining Default Resources
	TexManager = IResourceManager<sf::Texture, IDTexture>(tex.getTexture());

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
