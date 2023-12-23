/*Загальні відомості
В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
Футбольні поля мають можуть мати різну довжину
Довжина : мінімум 100 ярдів, максимум 130 ярдів.
Ширина : мінімум 50 ярдів, максимум 100 ярдів.

// Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.

Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв у Вашому прізвищі * 0.8 метра.
На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3 - х центральних(по довжині) метрах поля.
Обчислення зробити для 2 - х випадків :
1) при написанні прізвища з лівого краю поля — > до правого
2) при написанні прізвища з правого краю поля < —  до лівого.
    Результат записати.*/


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ofstream out("New.txt"); //виконую роботу з файлами
    string mysurname;
    cout << "Enter your surname: " << endl;
    cin >> mysurname;
    const int length = 130; //довжина поля в ярдах 
    double fieldlength = 130 * 3 * 12 * 2.54 / 100; //довжина поля в метрах
    cout << "The length of a field in metres " << fieldlength << endl;
    //Моє прізвище - Shevchenko(3 голосні букви), отже, інтервал між буквами буде = 3 * 0.8 = 2.4(м)
    //В Shevchenko 10 букв, отже, ширина слова складе сумарно 24 м
    double letterwide = 3 * 0.8; //ширина однієї букви
    int letteramount = 10;
    double wordwide = letterwide * letteramount;
    cout << "The length of each word in metres is " << wordwide << endl;
    int wordamount = fieldlength / wordwide; //ціла кількість слів, які помістяться на полі(однаково для початку і зліва і справа
    cout << "The amount of words that fully can be placed is " << wordamount << endl;
    //обчислено, що поле склкдає 118.872 м(отже, 3 центральних фута це приблизно 58, 59 та 60 м)
    //олбчислюємо для лівого края поля
    cout << "First we will count for the start from the left side: " << endl;
    int i = 0;
    while (24 * i < 58)
    {
        i++;
    } //цикл обчислує, скільки слів не буде заходити на центр поля, але виводить число на 1 більше за те, що потрібно(бо виконує один зайвий інкремент, який вже не вкладається в умову)(початок зліва)
    cout << "The amount of words that won't reach the centre is " << i - 1 << endl;
    cout << "The word that will reach centre is # " << i << endl; //виводить номер слова, що потрапить в центр

    vector<char>answer1; //використовую вектор стрічок для запису центральних букв
    for (int h = 0; h < mysurname.size(); h++)
    {
        cout << "The letter " << mysurname[h] << " will be from metre " << wordwide * (i - 1) + letterwide * h << " to metre " << wordwide * (i - 1) + letterwide * (h + 1) << endl;
        out << "The letter " << mysurname[h] << " will be from metre " << wordwide * (i - 1) + letterwide * h << " to metre " << wordwide * (i - 1) + letterwide * (h + 1) << endl;
        if (wordwide * (i - 1) + letterwide * h > 58 - letterwide && wordwide * (i - 1) + letterwide * h < 60 + 2.4) //встановлюємо самі такі межі з додаванням 2.4, бо букви рахуються, навіть якщо частково потраплять в центральні метри)
        {
            answer1.push_back(mysurname[h]);
        }
    }
    cout << "The central letters are: " << endl;
    for (int i = 0; i < answer1.size(); i++)
    {
        cout << answer1[i] << endl;
    }
    //тепер зробимо аналогічну задачу для правого краю поля

    cout << "Now we will count for the start from the right side: " << endl;
    int k = 0;
    while (118.872 - 24 * k > 58)
    {
        k++;
    }
    cout << "The amount of words that won't reach the centre is " << k - 1 << endl;
    cout << "The word that will reach centre is # " << k << endl; //виводить номер слова, що потрапить в центр
    vector<char>answer2;
    for (int m = 0; m < mysurname.size(); m++)
    {
        cout << "The letter " << mysurname[9 - m] << " will be from metre " << 118 - wordwide * (k - 1) - letterwide * m << " to metre " << 118 - wordwide * (k - 1) - letterwide * (m + 1) << endl;
        out << "The letter " << mysurname[9 - m] << " will be from metre " << 118 - 24 * (k - 1) - 2.4 * m << " to metre " << 118 - 24 * (k - 1) - 2.4 * (m + 1) << endl;
        if (118 - wordwide * (k - 1) - letterwide * m < 60 + letterwide && 118 - wordwide * (k - 1) - letterwide * (m + 1) > 58 - letterwide)
        {
            answer2.push_back(mysurname[9 - m]);
        }

    }
    cout << "The central letters are: " << endl;
    for (int i = 0; i < answer2.size(); i++)
    {
        cout << answer2[i] << endl;
    }

}