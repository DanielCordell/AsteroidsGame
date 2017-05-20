#include <string>
#include <algorithm>

#include "Includes/DiceRoller.h"
#include "Includes/EngineLogger.h"

const std::vector<unsigned int> DiceRoller::Roll(unsigned int diceNumber, unsigned int sideNumber)
{
	std::uniform_int_distribution<unsigned int> distribution(1, sideNumber);
	std::vector<unsigned int> rolls;

	for (unsigned int i = 0; i < diceNumber; i++)
	{
		rolls.push_back(distribution(generator));
	}
	return rolls;
}

const std::vector<unsigned int> DiceRoller::RollAdv(unsigned int diceNumber, unsigned int sideNumber, unsigned int numToKeep) { return Adv(Roll(diceNumber, sideNumber), numToKeep); }

const std::vector<unsigned int> DiceRoller::RollDis(unsigned int diceNumber, unsigned int sideNumber, unsigned int numToKeep) { return Dis(Roll(diceNumber, sideNumber), numToKeep); }

const std::vector<unsigned int> DiceRoller::Adv(std::vector<unsigned int> rolls, unsigned int numToKeep)
{
	if (rolls.size() < numToKeep) {
		EngineLogger::Log(EngineLogger::LOG_WARNING,"Error in DiceRoller - Trying to keep more rolls than exist (" + std::to_string(rolls.size()) + "<" + std::to_string(numToKeep) + ")");
		EngineLogger::Log(EngineLogger::LOG_WARNING, "Keeping All Rolls");
		return rolls;

	}
	std::sort(rolls.begin(), rolls.end());
	std::reverse(rolls.begin(), rolls.end());
	std::vector<unsigned int> newRolls;
	for (unsigned int i = 0; i < numToKeep; i++) newRolls.push_back(rolls[i]);
	return newRolls;
}

const std::vector<unsigned int> DiceRoller::Dis(std::vector<unsigned int> rolls, unsigned int numToKeep)
{
	if (rolls.size() < numToKeep) {
		EngineLogger::Log(EngineLogger::LOG_WARNING, "Error in DiceRoller - Trying to keep more rolls than exist (" + std::to_string(rolls.size()) + "<" + std::to_string(numToKeep) + ")");
		EngineLogger::Log(EngineLogger::LOG_WARNING, "Keeping All Rolls");
		return rolls;
	}
	std::sort(rolls.begin(), rolls.end());
	std::vector<unsigned int> newvector;
	for (unsigned int i = 0; i < numToKeep; i++) newvector.push_back(rolls[i]);
	return newvector;
}

const int DiceRoller::RollSum(unsigned int diceNumber, unsigned int sideNumber) { return Sum(Roll(diceNumber, sideNumber)); }

const int DiceRoller::Sum(std::vector<unsigned int> rolls)
{
	int sum = 0;
	for (int roll : rolls) sum += roll;
	return sum;
}

std::default_random_engine DiceRoller::generator;