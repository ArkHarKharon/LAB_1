#include <array>
#include <string>
#include <iostream>
#include <fstream>

#include "structures.h"
#include "enums.h"
#include "union.h"
#include "termcolor.hpp"


void saving(std::array<Awful, 5>const &arr, std::array <States, 5>const &states)
{
	std::fstream file("Array_of_unions.txt", std::ios::out);
	if (file.is_open())
	{
		file << termcolor::green << "\t\t\t--------UNION ARRAY--------\n\n" << termcolor::reset;
		for (int index{0}; index < arr.size(); index++)
		{
			if (states.at(index) == States::CIV6)
			{
				file << "\t\t\t-----CIVILIZATION-----\n\n";
				file << "Hours of playing Civilization 6:  " << arr.at(index).civ.hours << '\n';
				file << "Max science: " << arr.at(index).civ.science << '\n';
				file << "IDK(-___-): " << arr.at(index).civ.idk << "\n\n";
			}
			else if (states.at(index) == States::EVE)
			{
				file << "\t\t\t-----EVE ONLINE-----\n\n";
				file << "Hours of playing Eve Online:  " << arr.at(index).eve.hours << '\n';
				file << "Max DPS: " << arr.at(index).eve.dps << '\n';
				file << "IDK(-___-): " << arr.at(index).eve.idk << "\n\n";
			}
			else if(states.at(index) == States::EMPTY)
			{
				file << "\t\t\t   -----EMPTY UNION-----\n\n";
			}
		}
		file.close();
		std::cout << termcolor::green << "Data was successfully saved!\n\n" << termcolor::reset;
	}
	else
	{
		std::cout << termcolor::red << "File is NOT opened!!!\n" << termcolor::reset;
		return;
	}
}


void reading(std::array<Awful, 5>const &arr, std::array <States, 5>const &states)
{
	std::fstream file("Array_of_unions.txt", std::ios::in);
	std::string str{};

	std::cout << "File's data:\n\n";
	if (file.is_open())
	{
		while (file) 
		{			
			std::getline(file, str);		
			std::cout<< termcolor::bright_yellow << str << '\n' << termcolor::reset;
		}
		file.close();		
	}
	else 
	{ 
		std::cout << termcolor::red << "File was NOT read!\n" << termcolor::reset;
		return;
	}
}