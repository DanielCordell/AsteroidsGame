#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

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
};
