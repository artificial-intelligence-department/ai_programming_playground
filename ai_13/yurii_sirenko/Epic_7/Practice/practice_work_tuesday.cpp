#include <iostream>
using namespace std;


int countVowels(string str) //14 в коді використано параметри та аргументи функції
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) 
    {
        char ch = std::tolower(str[i]);  // Convert to lowercase for case-insensitivity
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') //5 в коді використані умовні оператори та розгалуження
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    const double lenghtPole = 109.728; //4 в коді використана як мінімум одна цілочисельна константа 

    string myLastName;
    cin>>myLastName;
    const int vowelsCount = countVowels(myLastName);
    const double widthPerVowel = 0.8; //3 в коді використана як мінімум одна дійсний з подвійною точністю змінна

    int nameLength = 0;
    for (int i = 0; myLastName[i] != '\0'; ++i) { //10 в коді використаний for цикл 
        nameLength++;
    }

    double letterWidth = vowelsCount * widthPerVowel; //2 в коді використана як мінімум одна дійсна змінна
    double bannerLength = nameLength * (letterWidth);



    std::cout << "lenght of banner : " << bannerLength << " m" << std::endl;

    int number_ofelements_pole = lenghtPole/letterWidth;
    char pole[number_ofelements_pole]; //6 в коді використаний одновимірний масив 
    for(int i = 0;i<number_ofelements_pole;i+=nameLength)
    {
        for(int j = 0;j<nameLength;j++)
        {
            pole[i+j]=myLastName[j];
        }
    }

    // Знаходимо середній індекс
    double middleIndex = number_ofelements_pole / 2;

    // Виводимо символи на 3-х центральних метрах
    std::cout << "middle symbols ";

    int j = 0; // 1 в коді використана як мінімум одна цілочисельна змінна
    for(double i = 0;i<lenghtPole;j++,i+=letterWidth)
    {
        if(i>middleIndex-1.5&&i<middleIndex+1.5+letterWidth)
        {
            cout<<pole[j]; //18 в коді використано оператори виведення та введення даних
        }
    } 


    return 0;
}