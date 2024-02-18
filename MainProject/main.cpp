#include "all_pack.h"





int main()
{
	std::array<Awful, 5> main_array{};				//Основной union массив 
	std::array <States, 5> states_array{};		    //Массив состояний основного массива
	Civ6 clear_structure{};							//Пустая структура для очистки ячейки основного массива

	setlocale(0, "");								//Не знаю, зачем он тут
	states_array.fill(EMPTY);						//Заполняю states элементами EMPTY

	main_menu(main_array, states_array, clear_structure);

	std::cout << termcolor::green << "Until we meet again!\n\n" << termcolor::reset;

	return 0;
}