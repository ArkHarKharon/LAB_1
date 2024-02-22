#include "enums.h"
#include "union.h"
#include <iostream>
#include <array>
#include <Windows.h>
#include <ctime>
#include <string>
#include "termcolor.hpp"
#include "prototypes.h"



void input_civ(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5> &states)
{
	std::cout << "How many hours do you play Civilization 6: ";
	std::cin >> arr.at(index).civ.hours;

	std::cout << "Max science: ";
	std::cin >> arr.at(index).civ.science;


	std::cout << "1 or 0 (don't ask): ";
	std::cin >> arr.at(index).civ.idk;

	states.at(index) = States::CIV6; //��������� CIV6 � ������ ���������
}


void input_eve(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5> &states)
{
	std::cout << "How many hours do you play Eve Online: ";
	std::cin >> arr.at(index).eve.hours;

	std::cout << "Damage per second: ";
	std::cin >> arr.at(index).eve.dps;


	std::cout << "1 or 0 (don't ask): ";
	std::cin >> arr.at(index).eve.idk;

	states.at(index) = States::EVE; //��������� EVE � ������ ���������
}


void input(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5>& states)
{
	std::cout << "Do you play Civilization 6(0) or Eve Online(1): ";
	int choise{};
	std::cin >> choise;

	if (choise == 0)
		input_civ(arr, index, states);
	else if (choise == 1)
		input_eve(arr, index, states);
	else
		std::cout << termcolor::red << "Input error..." << termcolor::reset;
}


void add(std::array<Awful, 5>& arr, std::array <States, 5> &states)
{
	for (std::size_t index{ 0 }; index < arr.size(); index++)
		input(arr, index, states);
}		

void delete_item(std::array<Awful, 5>& arr, std::size_t index, std::array <States, 5> &states, Civ6 &str)
{
	arr.at(index).civ = str;
	states.at(index) = States::EMPTY;
}

void delete_all(std::array<Awful, 5> &arr, std::array <States, 5> &states, Civ6& str)
{
	for (std::size_t index{ 0 }; index < arr.size(); index++)
		delete_item(arr, index,states,str);

	states.fill(States::EMPTY);
}


void print_item(std::array<Awful, 5> const& arr, std::size_t index, std::array <States, 5> &states)
{
	switch (states.at(index))
	{
	case(States::EMPTY):
		system("cls");
		std::cout << index << "-th element is empty!";
		break;

	case(States::CIV6):
		system("cls");
		std::cout << "\t\t\t----------CIVILIZATION PLAYER (" << index << "/4 NUMBER)----------\n\n";
		std::cout << "Hours of playing Civilization 6: " << arr.at(index).civ.hours;
		std::cout << "\nMax science: " << arr.at(index).civ.science;

		if ((arr.at(index).civ.idk == true) or arr.at(index).civ.hours >= 1000)
		{
			std::cout << "\nGayness:" << termcolor::red << "TRUE" << termcolor::reset;
			std::cout << termcolor::red << "\n\t\t\t!!!!ATTENTION!!!!   !!!GAY DETECTED!!!" << termcolor::reset;
			Sleep(6000);
		}
		else
			std::cout << "\nGayness:" << termcolor::green << "false" << termcolor::reset;

		break;

	case(States::EVE):
		system("cls");
		std::cout << "\t\t\t----------EVE ONLINE PLAYER (" << index << "/4 NUMBER)----------\n\n";
		std::cout << "Hours of playing EVE Online: " << arr.at(index).eve.hours;
		std::cout << "\nMax dps: " << arr.at(index).eve.dps;
		
		if ((arr.at(index).eve.idk == true) or arr.at(index).eve.hours >= 1000)
		{
			std::cout << "\nGayness:" << termcolor::red << "TRUE" << termcolor::reset;
			std::cout << termcolor::red << "\n\t\t\t!!!!ATTENTION!!!!   !!!GAY DETECTED!!!" << termcolor::reset;
			Sleep(6000);
		}
		else
			std::cout << "\nGayness:" << termcolor::green << "false" << termcolor::reset;

		break;
	}
}


void print_all(std::array<Awful, 5> const& arr, std::array <States, 5> &states)
{
	for (std::size_t index{ 0 }; index < arr.size(); index++)
	{
		print_item(arr, index, states);
		Sleep(3000);
	}
}


int random(int min, int max)
{
	srand(time(NULL));
	int number = min + rand() % (max - min + 1);
	return number;
}


void joking()				//������� ��������� �����
{
	switch (random(0, 10))
	{
	case(0):
		std::cout 
			<< "\t���������������� ������ �� ����:\n"
			<< " ���� ������ � � ��� ����� �������� ������������.";
		break;

	case(1):
		std::cout
			<< "\t���� �� ��������� �������� ��� ��, ��� ������������ �����,\n"
			<< " �� ����� �����, ��������� ��������� �� ����� ����,\n"
			<< " ����� �� ����� �������� ������ �����������.";
		break;

	case(2):
		std::cout
			<< "\t���� � ��������� ������ Java ����� ����������� ������� ������ ������������ ������,\n"
			<< " ������� ����� Java - ���������� ����� ������� ���� ����� ����� ���������.";
		break;

	case(3):
		std::cout
			<< "\t������� � ��� �������� �� ������������ ���� ��������� �����.\n"
			<< " ������, ���������������� � ��� �������� � ���������� ���� ����� ����� � ���?";
		break;

	case(4):
		std::cout
			<< "\t��� ������ ����� ����������� ����� � ��������?\n"
			<< " ������� �� �� ������, ����� �������� �� ��� ��������.";
		break;

	case(5):
		std::cout << "\t�������, IT-���� � ��� ���������� ��� ��� �� �������?";
		break;

	case(6):
		std::cout
			<< "\t�� ��������� GoTo: ���� � ������ �������� ������ ��������,\n"
			<< " ����� ��� ����� ���� ���� �� �������� ����������.";
		break;

	case(7):
		std::cout
			<< "\t����������� ����������� ����������� ���������� ���������� ��������.\n"
			<< " �������� ������ ���-�� ����� ���� �� ����� ��� �����-�� ����������� �����������,\n"
			<< " �� � ������� ���������� ����� ����� �����.";
		break;

	case(8):
		std::cout
			<< "\t�� ���������, ���� �� ��� �������� ��� ����.\n"
			<< " ���� �� ���  �������� ������ , �� �� �� ����� ����� ��� �� �������.";
		break;

	case(9):
		std::cout
			<< "\t��� ������ ���� ��� , ������ �������, ������� ����� ��� ������������  � ��������,\n"
			<< " ������� �����, ��� �� ������.";
		break;

	case(10):
		std::cout
			<< "\t������� ������  ���������� � �������  ���-��,\n"
			<< " ��� ��������  ���� �� �� ������� ���������� �������.";
		break;
	}
}  


void pclear()				//�������� �� 4 ������� � ������� �������
{
	Sleep(4000);
	system("cls");
}

void main_menu(std::array<Awful,5> &arr,std::array<States,5> &states,Civ6 &clear_str)
{
	std::cout
		<< "Hello there!\n"
		<< "I hope you'll enjoy this...perfomance.\n"
		<< "Well, talk is cheap, programmers' work is expensive, so let's go!";

	Sleep(8000);
	system("cls");

	int answer{ 0 };
	std::size_t index1{ 0 };
	std::size_t index3{ 0 };
	std::size_t index5{ 0 };

	do
	{

		std::cout
			<< "\t\t\t----------MENU----------\n\n"
			<< "1) I want to input a current item\n"
			<< "2) I want to input the whole union array\n"
			<< "3) I want to clear current item\n"
			<< "4) I want to clear the whole union array\n"
			<< "5) I want to print current item\n"
			<< "6) I want to print the whole union array\n"
			<< "7) I want a joke(-___-)\n"
			<< "8) I want to write down the file\n"
			<< "9) I want to read the file\n"
			<< "10) I want to exit!\n\n";

		std::cout << "Your option: ";
		std::cin >> answer;
		system("cls");

		switch (answer)
		{
		case(1):
			std::cout << "\t\t\t----------INPUT ITEM----------\n\n";
			std::cout << "Element's index(0-4): ";
			std::cin >> index1;
			if (index1 >= 0 and index1 <= 4) 
				input(arr, index1, states);
			else
			{
				system("cls");
				std::cout << termcolor::red << "Index is out of range!" << termcolor::reset;
				Sleep(3000);
				system("cls");
				break;
			}
			system("cls");
			std::cout << termcolor::green << "Done!" << termcolor::reset;
			pclear();
			break;

		case(2):
			std::cout << "\t\t\t----------INPUT ALL----------\n\n";
			add(arr, states);
			system("cls");
			std::cout << termcolor::green << "Done!" << termcolor::reset;
			pclear();
			break;

		case(3):
			std::cout << "\t\t\t----------DELETE ITEM----------\n\n";
			std::cout << "Element's index: ";
			std::cin >> index3;
			if (index3 >= 0 and index3 <= 4)
				delete_item(arr, index3, states, clear_str);
			else
			{
				system("cls");
				std::cout << termcolor::red << "Index is out of range!" << termcolor::reset;
				Sleep(3000);
				system("cls");
				break;
			}
			system("cls");
			std::cout << termcolor::green << "Done!" << termcolor::reset;
			pclear();
			break;

		case(4):
			std::cout << "\t\t\t----------DELETE ALL----------\n\n";
			delete_all(arr, states, clear_str);
			system("cls");
			std::cout << termcolor::green << "Done!" << termcolor::reset;
			pclear();
			break;

		case(5):
			std::cout << "\t\t\t----------PRINT ITEM----------\n\n";
			std::cout << "Element's index: ";
			std::cin >> index5;
			if (index5 >= 0 and index5 <= 4)
				print_item(arr, index5, states);

			else
			{
				system("cls");
				std::cout << termcolor::red << "Index is out of range!" << termcolor::reset;
				Sleep(3000);
				system("cls");
				break;
			}
			system("cls");
			break;

		case(6):
			std::cout << "\t\t\t----------PRINT ALL----------\n\n";
			print_all(arr, states);
			Sleep(10000);
			system("cls");
			std::cout << termcolor::green << "Done!" << termcolor::reset;
			pclear();
			break; 

		case(7):
			std::cout << "\t\t\t----------JOKE----------\n\n";
			joking();
			Sleep(10000);
			system("cls");
			break;		

		case(8):
			std::cout << "\t\t\t----------WRITING FILE----------\n\n";
			saving(arr, states);
			Sleep(10000);
			system("cls");
			break;

		case(9):
			std::cout << "\t\t\t----------READING FILE----------\n\n";
			system("cls");
			reading(arr, states);
			Sleep(10000);
			system("cls");
			std::cout << termcolor::green << "Done!" << termcolor::reset;
			pclear();
			break;

		case(10): break;         //����� �� �����

		default:
			system("cls");
			std::cout << termcolor::red << "\t\t\t----------UNEXPECTED ERROR----------\n\n" ;
			std::cout  << "Error...try again..." << termcolor::reset;
			pclear();
			break;
		}
	} while (answer != 10);

}