#include <iostream>
using namespace std;
int main()
{

 int age = 0; // вводить користувач
 int maxAge = 0; // для запису максимального значення віку
 int minAge = 100; // для запису мінімального значення віку
 int sum = 0; // загальна сума, для розрахунків  
 int average = 0; // для запису середнього віку
 int amount = 0; // кількість відвідувачів спортзалу

cout << "Enter amount visitors of gym: ";
cin >> amount;

for (int i = 0; i < amount; i++)
{
 cout << "Enter age " << i + 1 << " visitor: "; // запит на введення числа
cin >> age;

if (age > maxAge) // якщо воно більше, ніж зберігає в собі змінна max
maxAge = age; // записуємо в неї це число 
if (age < minAge) 
minAge = age;

 sum += age; // накопичення загальної сумми
}

 average = sum / amount; // для підрахунку середнього віку

cout << "\nAverege age of visitors: " << average << endl;
cout << "\nThe most adult visitor: " << maxAge << endl;
cout << "\nThe youngest visitor: " << minAge << endl;

return 0;
}