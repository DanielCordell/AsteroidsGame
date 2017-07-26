#include "Includes/AsteroidHandler.h"

bool AsteroidHandler::HandleCollision(Player& player)
{
	bool isCollision = false;
	auto pBounds = player.GetBounds();
	for (int i = 0; i < Length(); ++i) {
		if (pBounds.intersects(asteroids[i]->GetBounds())) {
			asteroids[i]->SetDelete();
			isCollision = true;

			//Create new asteroids
			if (asteroids[i]->type == Asteroid::large || asteroids[i]->type == Asteroid::medium) SpawnAsteroids(2, asteroids[i]->type, asteroids[i]->GetPosition());
		}
	}
	return isCollision;
}

void AsteroidHandler::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	for (auto& asteroid : asteroids) {
		target.draw(*asteroid, states);
	}
}


int AsteroidHandler::HandleCollision(BulletHandler& bullets)
{
	int scoreChange = 0;
	for (int i = 0; i < Length(); ++i) {
		for (int i = 0; i < bullets.Length(); ++i) {
			if (bullets[i].GetBounds().intersects(asteroids[i]->GetBounds())) {
				asteroids[i]->SetDelete();
				bullets[i].SetDelete();
				scoreChange += asteroids[i]->type;

				//Create new asteroids
				if (asteroids[i]->type == Asteroid::large || asteroids[i]->type == Asteroid::medium) SpawnAsteroids(3, asteroids[i]->type, asteroids[i]->GetPosition());
			}
		}
	}
	return scoreChange;
}

void AsteroidHandler::SpawnAsteroids(int num, Asteroid::AsteroidType oldType, sf::Vector2f position) {
	Asteroid::AsteroidType newType;
	if (oldType == Asteroid::large) newType = Asteroid::medium;
	else newType = Asteroid::small;
	for (int i = 0; i < num; ++i) 
		asteroids.push_back(std::make_unique<Asteroid>(newType, newType == Asteroid::large ? largeTex : medTex,position));
}

void AsteroidHandler::GenerateAsteroids(int numLarge, int numMed, int numSmall) {
	for (int i = 0; i < numLarge; ++i) asteroids.push_back(std::make_unique<Asteroid>(Asteroid::large, largeTex));
	for (int i = 0; i < numMed; ++i) asteroids.push_back(std::make_unique<Asteroid>(Asteroid::medium, medTex));
	for (int i = 0; i < numSmall; ++i) asteroids.push_back(std::make_unique<Asteroid>(Asteroid::small, smallTex));
}

void AsteroidHandler::Update() {
	if (asteroids.empty()) GenerateAsteroids(3, 3, 3);
	for (auto& asteroid : asteroids) asteroid->Update();
	for (auto i = asteroids.begin(); i != asteroids.end();) {
		if ((*i)->ShouldDelete()) i = asteroids.erase(i);
		else ++i;
	}
}
