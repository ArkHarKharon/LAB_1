#include "all_pack.h"

std::array<Awful, 5> main_array{};				//Основной union массив 
std::array <States, 5> states_array{};		    //Массив состояний основного массива
Civ6 clear_structure{};							//Пустая структура для очистки ячейки основного массива




int main()
{
	setlocale(0, "");							//Не знаю, зачем он тут
	states_array.fill(EMPTY);					//Заполняю states элементами EMPTY

	main_menu(main_array, states_array, clear_structure);

	return 0;
}