//vns 4 variant 14
#include <iostream>
using namespace std;
int main()
{
    // Кількість чисел, які будуть введені користувачем
    const int lineLength = 5;
    double sum; // Змінна для зберігання суми чисел

    cout<< "Enter "<<lineLength<<" fractional numbers "<<endl;

    // Цикл для введення кожного з чисел та обчислення суми та середнього значення
    for (int i=1; i<= lineLength; i++)
    {
        double number;
        cout<<"Enter the "<<i<<" number"<<endl;
        cin>>number;

        sum += number;

        // Виведення середнього значення для поточного числа
        cout<<"The avarage value of current numbers is "<<sum/i<<endl;

    }
    // Виведення середнього значення для всіх введених чисел
    cout<<"The avarage value of all numbers is "<< sum/lineLength <<endl;
    return 0;

}
