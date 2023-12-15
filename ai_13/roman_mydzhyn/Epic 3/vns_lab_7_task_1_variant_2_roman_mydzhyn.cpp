#include <iostream>
#include <cstdarg>

using namespace std;

float mult(int count, ...) // count - к-сть параметрів, а ... наші параметри
{

	va_list args;			  // змінна (список для параметрів)
	va_start(args, count); // викликаємо список

	float result = 1;
	for (int i = 0; i < count; i++) // обрахунок добутку
	{
		float arg = va_arg(args, double);
		result = result * arg;
	}

	va_end(args); // кінець роботи зі списком
	return result;
}

int main()
{
	cout << "mult = " << mult(2, 1.8, 4.2) << endl;
	cout << "mult = " << mult(6, 4.3, 1.2, 2.6, 2.2, 3.4, 7.45) << endl;
	cout << "mult = " << mult(10, 4.5, 6.3, 2.1, 2.2, 3.1, 5.7, 2.9, 7.45, 8.45, 1.8) << endl;

	return 0;
}
