#include "all_pack.h"

std::array<Awful, 5> main_array{};				//�������� union ������ 
std::array <States, 5> states_array{};		    //������ ��������� ��������� �������
Civ6 clear_structure{};							//������ ��������� ��� ������� ������ ��������� �������




int main()
{
	setlocale(0, "");							//�� ����, ����� �� ���
	states_array.fill(EMPTY);					//�������� states ���������� EMPTY

	main_menu(main_array, states_array, clear_structure);

	return 0;
}