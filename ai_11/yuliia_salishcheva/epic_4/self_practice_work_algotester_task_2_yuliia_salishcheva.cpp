//Завдання 2. У одновимірному масиві зберігається
//інформація про вартість 10 марок автомобілів.
//Визначити суму найдорожчого автомобіля і дізнатися
//його номер.Якщо таких автомобілів декілька,
//визначити номер першого найдорожчого і номер
//останнього найдорожчого автомобіля.

#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 10;
    int max_first = 0, max_last = 0;
    int list[SIZE]{ 1000, 6000, 7000, 4500, 2500, 3000, 7000, 6500, 5500, 4500 };

    for (int i = 0; i < SIZE; i++)
    {
        if (list[i] > list[max_first])
        {
            max_first = i;
            //cout << max_first << " max" << endl;
        }

    }
    cout << "\nThe largest amount for the fist car : " << list[max_first] << " -- " << max_first + 1 << " car number" << endl;

    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (list[i] > list[max_last])
        {
            max_last = i;
            //cout << max_last << " max" << endl;
        }

    }
    cout << "\nThe largest amount for the last car : " << list[max_last] << " -- " << max_last + 1 << " car number" << endl;

}
