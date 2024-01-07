// Lab 1v3
// Персонажу по одному дають сторони 5 кубiв a1..5, з яких вiн будує пiрамiду.
// Коли вiн отримує куб з ребром ai - вiн його ставить на iснуючий, перший ставить на пiдлогу
// (вона безмежна).
// Якщо в якийсь момент об’єм куба у руцi(який будуть ставити) буде бiльший нiж у куба
// на вершинi пiрамiди - персонаж програє i гра закiнчується.Розмiр усiх наступних кубiв пiсля
// програшу не враховується.
// Тобто якщо ai−1 < ai - це програш.
// Ваше завдання - сказати як закiнчиться гра.

#include <iostream>
int main()
{
	const long int cube_count = 5;
    long int cubes[cube_count] = {};
	bool flag_win = true;

	for (int i = 0; i < cube_count; i++)
	{
		std::cin >> cubes[i];
	}
	
	for (int i = 0; i < cube_count; i++)
	{
		//std::cout << i + 1 << "| Enter cube's side: ";
		if (cubes[i] <= 0)
		{
			std::cout << "ERROR" << std::endl;
			flag_win = false;
			break;
		}
			
		if (i != 0)
		{
			if (cubes[i - 1] < cubes[i])
			{
				flag_win = false;
				std::cout << "LOSS" << std::endl;
				break;
			}
		}
	}
	if (flag_win)
		std:: cout << "WIN" << std::endl;
}
