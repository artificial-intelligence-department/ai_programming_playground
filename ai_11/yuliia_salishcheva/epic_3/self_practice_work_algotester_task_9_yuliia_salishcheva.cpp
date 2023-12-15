////Завдання 9. Написати рекурсивну функцію, яка
////виводить N зірок у ряд, число N задає користувач.
////Проілюструйте роботу функції прикладом.

#include <iostream>
using namespace std;

void output_star(int number);


int main()
{
	output_star(5);
}

void output_star(int number)
{
	if (!number) 
		return;
	cout << '*';
	output_star(number - 1);

}
