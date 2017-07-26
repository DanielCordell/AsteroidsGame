#pragma once
#include <vector>

#include "Player.h"
#include "BulletHandler.h"
#include "Asteroid.h"

class AsteroidHandler : public sf::Drawable{
public:
	AsteroidHandler(sf::Texture& large, sf::Texture& med, sf::Texture& small)
		: largeTex(large),
		  medTex(med),
		  smallTex(small) {}

	bool	HandleCollision(Player& player);
	void	draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	int		HandleCollision(BulletHandler& bullets);
	void	SpawnAsteroids(int num, Asteroid::AsteroidType oldType, sf::Vector2f position);
	void	GenerateAsteroids(int numLarge, int numMed, int numSmall);
	void	Update();
	Asteroid& operator [](int i) const { return *asteroids[i]; }
	const int Length() const { return asteroids.size(); }

private:
	std::vector <std::unique_ptr<Asteroid>> asteroids;
	sf::Texture& largeTex;
	sf::Texture& medTex;
	sf::Texture& smallTex;
};
