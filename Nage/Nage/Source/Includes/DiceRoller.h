#pragma once

#include <random>
#include <vector>
#include <ctime>

class DiceRoller
{
	static std::default_random_engine generator;
public:
	// Dice Rolling
	const static std::vector<unsigned int> Roll(unsigned int diceNumber, unsigned int sideNumber);

	const static std::vector<unsigned int> RollAdv(unsigned int diceNumber, unsigned int sideNumber, unsigned int numToKeep);
	const static std::vector<unsigned int> Adv(std::vector<unsigned int> rolls, unsigned int numToKeep);

	const static std::vector<unsigned int> RollDis(unsigned int diceNumber, unsigned int sideNumber, unsigned int numToKeep);
	const static std::vector<unsigned int> Dis(std::vector<unsigned int> rolls, unsigned int numToKeep);

	const static int RollSum(unsigned int diceNumber, unsigned int sideNumber);
	const static int Sum(std::vector<unsigned int> rolls);
};
