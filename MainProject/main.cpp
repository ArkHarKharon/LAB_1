#include "all_pack.h"





int main()
{
	std::array<Awful, 5> main_array{};				//�������� union ������ 
	std::array <States, 5> states_array{};		    //������ ��������� ��������� �������
	Civ6 clear_structure{};							//������ ��������� ��� ������� ������ ��������� �������

	setlocale(0, "");								//�� ����, ����� �� ���
	states_array.fill(EMPTY);						//�������� states ���������� EMPTY

	main_menu(main_array, states_array, clear_structure);

	std::cout << termcolor::green << "Until we meet again!\n\n" << termcolor::reset;

	return 0;
}