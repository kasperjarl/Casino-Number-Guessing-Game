#include <iostream>
#include "casino.h"
#include "player.h"
#include "Random.h"

int getDifficulty()
{
	while (true)
	{
		std::cout 
			<< "\n---------------\t\tDifficulty selector\t\t---------------\n\n" 
			<< "Difficulty levels are as followed:\n"
			<< "Your entered integer * 2 = number of possible numbers from 0 and up\n"
			<< "The reward = your bet * (n_guess - 1)\n"
			<< "\nEnter difficulty level: ";

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
		std::cout 
			<< "\n---------------\t\tBet selector\t\t---------------\n" 
			<< "\nHow much do you want to bet?: ";
		double bet{};
		std::cin >> bet;

		if (clearFailedExtraction())
		{
			std::cout << "Oops. Invalid input for bet amount. Please try again.\n";
			continue;
		}

		// I need to check if the player is betting more than they have
		if (bet > player.getMoney())
		{
			std::cout << "You don't have enough money for that bet. Please try again.\n";
			continue;
		}
		else if (bet <= 0)
		{
			std::cout << "You have to bet above 0$. Please enter a valid bet.\n";
			continue;
		}

		ignoreLine();
		return bet;
	}
}

double getPossibleReward(double bet, int difficulty)
{
	return bet * (difficulty - 1);
}

int answer(int difficulty) {

	int output{ Random::get(0, difficulty) };

	std::cout << "\n---> Tjekker output format: " << output << '\n';

	return output;
}

int guess()
{
	while (true)
	{
		std::cout 
			<< "\n---------------\t\tGuess selector\t\t---------------\n"
			<< "\nEnter your guess: ";
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

bool endGame()
{
	while (true)
	{
		std::cout 
			<< "\n---------------\t\tKeep playing?\t\t---------------\n"
			<< "\nDo you want to bet again?: 'y' or 'n': ";
		char answer{};
		std::cin >> answer;

		if (clearFailedExtraction())
		{
			std::cout << "Oops, invalid input. Enter 'y' or 'n': ";
			continue;
		}
		
		ignoreLine();
		if (answer == 'y')
		{
			return false;
		}
		return true;
	}
}

void game(Player player, int difficulty)
{
	std::cout << "Welcome " << player.getName() << '\n';

	// need to get seed for random generator. 

	while (true)
	{

		if (player.getMoney() <= 0) {
			std::cout << "\nYou're out of money. \n-> BYE SUCKER <- \n";
			return;
		}

		double bet{ getBet(player) };
		int correctAnswer{ answer(difficulty) };
		if (guess() == correctAnswer)
		{
			std::cout << "Guess is correct. Adding reward.\n";
			player.adjustMoney(getPossibleReward(bet, difficulty));
		}
		else
		{
			std::cout 
				<< "Guess is incorrect. The answer was: " << correctAnswer
				<< " Subtracting bet.\n";
			player.adjustMoney(-bet);
		}

		if (endGame())
		{
			std::cout << "\nAll right, bye!\n";
			return;
		}
		else 
		{
			std::cout << "\nLet's keep gambling then!\n";
		}
	}
	

}