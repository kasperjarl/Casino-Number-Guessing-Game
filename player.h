#pragma once
#include <iostream>
#include <string_view>
#include "invalidInput.h"

class Player
{
public:
	Player()
		: m_name{ setName() }, m_money{ setMoney()}
	{
	}

	//~Player();
	
	std::string setName()
	{
		while (true)
		{
			std::cout << "Enter your name: ";
			std::string name{};
			std::cin >> name;

			if (clearFailedExtraction())
			{
				std::cout << "Oops, that input is invalid. Please try again.\n";
				continue;
			}
			return name;
		}
	}

	std::string_view getName()
	{
		std::string_view name{ m_name };
		return name;
	}


	double setMoney()
	{
		while (true)
		{
			std::cout << "Enter your bankroll: ";
			double bankroll{};
			std::cin >> bankroll;

			if (clearFailedExtraction())
			{
				std::cout << "That input is invalid. Please try again.\n";
				continue;
			}
			ignoreLine();
			return bankroll;
		}
		
		
	}


	double getMoney()
	{
		return m_money;
	}

	void adjustMoney(double amount)
	{
		m_money += amount;
		std::cout << "\n--> Your balance is now: " << m_money << "$.\n";
	}


private:
	const std::string m_name{};
	double m_money{};

};

