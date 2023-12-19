#include <iostream>
using namespace std;
#include <string>

int eyuoia(string& s) 
{
    int b = 0;
    for (char a : s) {
        if (a == 'e' || a == 'u' || a == 'i' || a == 'o' || a == 'a' || a == 'y' || a == 'E' || a == 'U' || a == 'I' || a == 'O' || a == 'A' || a == 'Y') {
            b++;
        }
    }
    return b;
}

int lght(string& s) 
{
    int b = 0;
    for (char a : s) 
    {
        b++;  
    }
    return b;
}

int main()
{
    float dum = 0.0254;
    double foot = 0.3048;
    double yard = 0.9144;
    string surname ;
    cin>>surname;
    const int count = eyuoia(surname);
    const int lenght =130;
    double letterlenght = 0.8*count;
    int namelenght=lght(surname);
    cout<<"Minimum lenght:"<<namelenght*letterlenght<<endl;
    double centre = (130*yard);


    int startIndexLeftToRight = (lght(surname) - 1) / 2;
    int startIndexRightToLeft = lght(surname) - startIndexLeftToRight - 1;

    cout << "Characters within the central three meters (left to right): ";
    for (int i = startIndexLeftToRight; i < lght(surname) && i < startIndexLeftToRight + 3; ++i) {
        cout << surname[i] << " ";
    }
    cout << endl;

    cout << "Characters within the central three meters (right to left): ";
    for (int i = startIndexRightToLeft; i >= 0 && i > startIndexRightToLeft - 3; --i) {
        cout << surname[i] << " ";
    }
    cout << endl;









}

// //Загальні відомості
// В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
// Футбольні поля мають можуть мати різну довжину
// Довжина: мінімум 100 ярдів, максимум 130 ярдів.
// Ширина: мінімум 50 ярдів, максимум 100 ярдів.

// // Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.

// Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
//  За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв у Вашому прізвищі * 0.8 метра.
// На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3-х центральних(по довжині) метрах поля. 
// Обчислення зробити для 2-х випадків:
// 1) при написанні прізвища з лівого краю поля —>  до правого
// 2) при написанні прізвища з правого краю поля <—  до лівого.
// Результат записати.
