#include <iostream>
using namespace std;

int counter_golosni(string str);
double from_yadr_to_futs(double a);
double from_futs_to_duim(double a);
double fromDuimsToCm(double a);
void fromLeftToRight(string str, int a);
void fromRightToLeft(string str, int a);

struct Dano { //в коді використано свою структуру даних
public:
	const string surname{ "Molnar" }; // 1)в коді використана як мінімум одна цілочисельна константа (ми не плануєм змінювати нашу фамілію 2)в коді використаний одновимірний масив (томущо стрінг є одновимірним масивом типу char.
	int min_length{ 100 }; // в коді використана як мінімум одна цілочисельна змінна (не дабл, або флоат, томущо нам вказанно число рівно 100)
	int min_width{ 50 };
	int count_golosni{ counter_golosni(surname) };
	double len_width{ count_golosni * 0.8 };//в коді використано математичні операції та математичні функції
	int a = static_cast<int>(3 / 0.9144);

};

int main()
{
	Dano qq;
	cout << "\nFrom left to right: \n";
	fromLeftToRight(qq.surname, qq.a);
	cout << "From right to left: \n";
	fromRightToLeft(qq.surname, qq.a);
}

int counter_golosni(string str)
{
	int counter{};
	for (char c : str)//в коді використаний for цикл (пробігаємось по нашій фамілії
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') // в коді використані умовні оператори та розгалуження (щоб перевірити чи наша буква є голосною)
			counter++;
	return counter;
}




void fromLeftToRight(string str, int a){ // в коді використано параметри та аргументи функції	(передаємо нашу фамілію і змінну 
	for (int i = 0; i < a; ++i)
		cout << str[i];
}

void fromRightToLeft(string str, int a){
	for (int i = str.length() - 1; i >= str.length() - a; --i)
		cout << str[i];
}

double from_yadr_to_futs(double a)
{
	return a / 3; //в коді використано математичні операції та математичні функції
}

double from_futs_to_duim(double a)
{
	return a / 12; //в коді використано математичні операції та математичні функції

}

double fromDuimsToCm(double a)
{
	return a / 2.54; //в коді використано математичні операції та математичні функції

}
