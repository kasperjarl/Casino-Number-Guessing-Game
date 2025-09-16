#include <iostream>
#include "casino.h"
#include "player.h"

int getDifficulty()
{
	while (true)
	{
		std::cout << "Time to pick the difficulty.\n" <<
			"Difficulty levels are as followed:\n" <<
			"Your entered integer * 2 = number of possible numbers from 0 and up\n"
			<< "The reward = your bet * (n_guess - 1)\n";

		// er nået hertil.
		int difficulty{};
		std::cin >> difficulty;

		if (clearFailedExtraction())
		{
			std::cout << "Oops. Invalid input. Please try again.\n";
			continue;
		}
		ignoreLine();
		return difficulty;
	}
}

double getBet(Player player)
{
	while (true)
	{
		std::cout << "How much do you want to bet?: ";
		double bet{};
		std::cin >> bet;

		if (clearFailedExtraction())
		{
			std::cout << "Oops. Invalid input for bet amount. Please try again.\n";
			continue;
		}

		if (bet > player.getMoney())
		{
			std::cout << "You don't have enough money for that bet. Please try again.\n";
			continue;
		}

		ignoreLine();
		return bet;
	}
}

double getPossibleReward(double bet, int difficulty)
{
	return bet * difficulty;
}


int answer() {

	// I need to introduce the random number
	// not sure if I need a min, or just use the difficulty level for the max num
			
	return 7;
}

int guess()
{
	while (true)
	{
		std::cout << "\nEnter your guess: ";
		int guess{};
		std::cin >> guess;

		if (clearFailedExtraction())
		{
			std::cout << "\nOops, you must enter an integer. Please try again\n";
			continue;
		}
		ignoreLine();
		return guess;
	}
}



void game(Player player, int difficulty)
{
	std::cout << "Welcome " << player.getName() << '\n';

	if (player.getMoney() <= 0) {
		std::cout << "\nYou're out of money.\n";
		return;
	}

	double bet{ getBet(player) };

	// I need to keep track of the money 
	// I need to check if the player is betting more than they have
	// I need to check if their guess == answer
	// I need to add/subtract money depeding on them being right or not

	std::cout << "Then you can win: " << getPossibleReward(bet, difficulty) << "$\n";
}