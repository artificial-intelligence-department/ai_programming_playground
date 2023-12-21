#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file1("F1");

    if (!file1.is_open())
    {
        cout << "Помилка запису в файл" << endl;
        return 0;
    }

    for (int i = 0; i < 10; ++i)
    {
        string textLine;
        cout << "Введіть " << i + 1 << "-ий рядок: ";
        cin >> textLine;
        file1 << textLine << endl;
    }
    file1.close();

    ifstream file1Read("F1");
    ofstream file2("F2");

    string lineToAdd;
    int K;
    cout << "Введіть з якого рядка почати копіювання: ";
    cin >> K;
    int N = K;
    int M = 0;

    while (getline(file1Read, lineToAdd))
    {   
        ++M;
        if (M >= N)
        {
            if (K < N + 6)
            {
                file2 << lineToAdd << endl;
                ++K;
            }
        }
    }
    file1Read.close();
    file2.close();

    ifstream file2Read("F2");

    string line3;
    char symbol;
    int count = 0;

    while (getline(file2Read, line3))
    {
        for (int i = 0; i < line3.size(); ++i)
        {
            symbol = line3[i];
            if (symbol == 'A' || symbol == 'a' || symbol == 'E' || symbol == 'e' || symbol == 'I' || symbol == 'i' || symbol == 'O' || symbol == 'o' || symbol == 'U' || symbol == 'u' || symbol == 'Y' || symbol == 'y')
            {
                ++count;
            }
        }
    }

    file2Read.close();

    cout << "Кількість голосних букв y файлі F2: " << count;

    return 0;
}