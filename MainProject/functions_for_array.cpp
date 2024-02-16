#include "enums.h"
#include "union.h"
#include <iostream>
#include <array>




void input_civ(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5> &states)
{
	std::cout << "How long do you play Civilization 6: ";
	std::cin >> arr.at(index).civ.hours;

	std::cout << "Max science: ";
	std::cin >> arr.at(index).civ.science;


	std::cout << "1 or 0: ";
	std::cin >> arr.at(index).civ.idk;

	states.at(index) = CIV6; //Записываю CIV6 в массив состояний
}


void input_eve(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5> &states)
{
	std::cout << "How long do you play Eve Online: ";
	std::cin >> arr.at(index).eve.hours;

	std::cout << "Damage per second: ";
	std::cin >> arr.at(index).eve.dps;


	std::cout << "1 or 0: ";
	std::cin >> arr.at(index).eve.idk;

	states.at(index) = EVE; //Записываю EVE в массив состояний
}


void input(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5>& states)
{
	std::cout << "Does this person play Civilization 6(0) or Eve Online(1): ";
	int choise{};
	std::cin >> choise;

	if (choise == 0)
		input_civ(arr, index, states);
	else if (choise == 1)
		input_eve(arr, index, states);
	else
		std::cout << "Input error...";
}


void add(std::array<Awful, 5>& arr, std::array <States, 5> &states)
{
	for (std::size_t i{ 0 }; i < arr.size(); i++)
	{
		std::cout << "Does this person play Civilization 6(Civ) or Eve Online(Eve): ";
		std::string answer;
		std::getline(std::cin, answer);

		if (answer == "Civ")
			input_civ(arr, i ,states);
		else if (answer == "Eve")
			input_eve(arr, i ,states);
		else
			std::cout << "Input error...";
	}
}

void delete_item(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5> &states, Civ6 &str)
{
	arr.at(index).civ = str;

	states.at(index) = EMPTY;
}

void delete_all(std::array<Awful, 5> &arr, std::array <States, 5> &states, Civ6& str)
{
	for (std::size_t index{ 0 }; index < arr.size(); index++)
		delete_item(arr, index,states,str);

	states.fill(EMPTY);
}

States definer(std::array<Awful, 5> const& arr, std::size_t index, std::array <States, 5> &states) //Возвращает enum-статус данной ячейки данного массива 
{
	switch (states.at(index))
	{
	case(EMPTY): return EMPTY; break;
	case(EVE): return EVE; break;
	case(CIV6): return CIV6; break;
	}
} 


void print_item(std::array<Awful, 5> const& arr, std::size_t index, std::array <States, 5> &states)
{
	switch (definer(arr, index, states))
	{
	case(EMPTY):
		std::cout << "This union is empty!";
		break;
	case(CIV6):
		std::cout << "Hours of playing Civilization 6:" << arr.at(index).civ.hours;
		std::cout << "Max science: " << arr.at(index).civ.science;
		std::cout << "Gayness: " << ((arr.at(index).civ.idk)?("true") : ("false"));
		break;
	case(EVE):
		std::cout << "Time of playing Civilization 6:" << arr.at(index).eve.hours;
		std::cout << "Max dps: " << arr.at(index).eve.dps;
		std::cout << "Gayness: " << ((arr.at(index).eve.idk) ? ("true") : ("false"));
		break;
	}
}


void print_all(std::array<Awful, 5> const& arr, std::array <States, 5> &states)
{
	for (std::size_t index{ 0 }; index < arr.size(); index++)
		print_item(arr, index,states);
}


void joking()
{

}


void main_menu(std::array<Awful,5> &arr,std::array<States,5> &states,Civ6 &clear_str)
{
	std::cout
		<< "Hello there!\n"
		<< "I hope you'll enjoy this...perfomance\n"
		<< "Well, talk is cheap, programmers' work is expensive, so let's go!";

	system("cls");

	int answer{ 0 };
	std::size_t index1{ 0 };
	std::size_t index3{ 0 };
	std::size_t index5{ 0 };



	do
	{
		std::cout
			<< "\t\t----------MENU----------\n"
			<< "1) I want to input a current item\n"
			<< "2) I want to input the whole union array\n"
			<< "3) I want to clear current item\n"
			<< "4) I want to clear the whole union array\n"
			<< "5) I want to print current item\n"
			<< "6) I want to print the whole union array\n"
			<< "7) I want a joke(-___-)\n"
			<< "8) I want to exit!\n\n";

		std::cout << "Your option: ";
		std::cin >> answer;

		switch (answer)
		{
		case(1):
			std::cout << "Element's index:";
			std::cin >> index1;
			input(arr,index1, states);
			break;

		case(2): add(arr, states); break;

		case(3):
			std::cout << "Element's index:";
			std::cin >> index3;
			delete_item(arr, index3, states,clear_str);
			break;

		case(4): delete_all(arr, states, clear_str); break;

		case(5):
			std::cout << "Element's index:";
			std::cin >> index5;
			print_item(arr, index5, states);
			break;

		case(6): print_all(arr, states); break; 

		case(7): joking(); break; //Выводит случайную шутку

		case(8): break;

		default:
			std::cout << "Oops...try again...";
			break;
		}
	} while (answer != 8);
	std::cout << "Until we meet again!";
}

