#include <iostream>
#include "casino.h"
#include "player.h"


// I need to know the following:
int difficulty{};
double bet{};
double reward{};

int getDifficulty()
{
	while (true)
	{
		std::cout << "Time to pick the difficulty.\n" <<
			"Difficulty levels are as followed:\n" <<
			"Your entered integer * 2 = number of possible numbers from 0 and up\n"
			<< "The reward = your bet * (n_guess - 1)"

			// er nået hertil.
			int difficulty{};
	}
}

// getBet()

// getReward()

void game(Player player)
{
	std::cout << "Welcome " << player.getName() << '\n';

	std::cout << "What difficulty do you want?: ";
	std::cin >> difficulty;

	std::cout << "What do you bet?: ";
	std::cin >> bet;

	std::cout << "Then you can win: " << bet * difficulty << "$\n";
}