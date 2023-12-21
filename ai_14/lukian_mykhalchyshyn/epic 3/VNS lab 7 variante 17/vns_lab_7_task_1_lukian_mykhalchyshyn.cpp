#include <iostream>

using namespace std;

void prost(int A, int B, int number1)
{

    if (number1 >= A && number1 <= B)
        cout << number1<< " ";
}

void prost(int A, int B, int number1, int number2, int number3)
{
    if (number1 >= A && number1 <= B)
        cout << number1<< " ";
    if (number2 >= A && number2 <= B)
        cout << number2<< " ";
    if (number3 >= A && number3 <= B)
        cout << number3<< " ";
}

void prost(int A, int B, int number1, int number2, int number3, int number4)
{
    if (number1 >= A && number1 <= B)
        cout << number1 << " ";
    if (number2 >= A && number2 <= B)
        cout << number2 << " ";
    if (number3 >= A && number3 <= B)
        cout << number3 << " ";
    if (number4 >= A && number4 <= B)
        cout << number4 << " ";
}

double mal (int car[], int size)
{
    double a_cer=0;
    for (int i=0; i<size; i++)
    {
       a_cer+=car[i];
    }
    a_cer/=size;
    return a_cer;
}

int puck(string word)
{
    int numberOfLetters = word.length();
    return numberOfLetters;
}

int main()
{
    cout << "task1\n";
    int a, b;
    cin >> a >> b;

    prost(a, b, 3);
    cout << endl;
    prost(a, b, 5, 6, 3) ;
    cout << endl;
    prost(a, b, 6, 8, 7, 4);

    cout << endl;
    cout << "task2, Написати перевантажені функції й основну програму, що їх викликає.\n";
    int const size=5;
    int deu[size]={6,5,4,2,5};

    cout << "a)  для масиву цілих чисел знаходить середнє арифметичне "<< endl << mal (deu,size) << endl;
    cout << "b) для рядка знаходить кількість букв, що містяться в ньому\n";
    string word;
    cin >> word;
    cout <<  puck(word);

    return 0;
}
