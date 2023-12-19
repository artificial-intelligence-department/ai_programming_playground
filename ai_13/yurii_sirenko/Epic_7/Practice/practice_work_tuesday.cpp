#include <iostream>
using namespace std;


int countVowels(string str) 
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) 
    {
        char ch = std::tolower(str[i]);  // Convert to lowercase for case-insensitivity
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') 
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    const double lenghtPole = 109.728;

    string myLastName;
    cin>>myLastName;
    const int vowelsCount = countVowels(myLastName);
    const double widthPerVowel = 0.8;

    int nameLength = 0;
    for (int i = 0; myLastName[i] != '\0'; ++i) {
        nameLength++;
    }

    double letterWidth = vowelsCount * widthPerVowel;
    double bannerLength = nameLength * (letterWidth);



    std::cout << "lenght of banner : " << bannerLength << " m" << std::endl;

    int number_ofelements_pole = lenghtPole/letterWidth;
    char pole[number_ofelements_pole];
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

    int j = 0;
    for(double i = 0;i<lenghtPole;j++,i+=letterWidth)
    {
        if(i>middleIndex-1.5&&i<middleIndex+1.5)
        {
            cout<<pole[j];
        }
    }

    return 0;
}