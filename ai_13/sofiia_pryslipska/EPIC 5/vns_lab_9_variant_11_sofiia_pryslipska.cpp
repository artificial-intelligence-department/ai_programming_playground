#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// Функція для знаходження довжини найкоротшого слова у рядку
int shortestWordLength(const string &line)
{
    istringstream iss(line);
    string word;
    int shortest = numeric_limits<int>::max();

    while (iss >> word)
    {
        shortest = min(shortest, static_cast<int>(word.length()));
    }
    return shortest;
}

int main()
{
    string filename1 = "F1.txt";
    string filename2 = "F2.txt";

    // Створення файлу F1 з рядками
    ofstream file1(filename1);
    if (!file1.is_open())
    {
        cout << "Error creating file F1.txt." << endl;
        return 1;
    }

    file1 << "Методичні вказівки\n";
    file1 << "Методичні вказівки\n";
    file1 << "Постановка завдання.\n";
    file1 << "Опис використовуваних типів даних.\n";
    file1 << "Текст функцій для:\n";
    file1 << "формування файлу,\n";
    file1 << "друку файлу,\n";
    file1 << "копіювання файлів,\n";
    file1 << "виконання завдання.\n";
    file1 << "Результат розв’язання конкретного варіанту.\n";

    file1.close();

    // Відкриття файлу F1 для читання та F2 для запису
    ifstream fileIn(filename1);
    ofstream fileOut(filename2);
    if (!fileIn.is_open() || !fileOut.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    // Читання рядків з файлу F1 та зберігання їх у векторі
    while (getline(fileIn, line))
    {
        lines.push_back(line);
    }

    fileIn.close();

    // Знаходження довжини найкоротшого слова у кожному рядку
    vector<int> shortestLengths;
    for (const auto &str : lines)
    {
        shortestLengths.push_back(shortestWordLength(str));
    }

    // Знаходження індексу рядка, у якому слово має мінімальну довжину
    auto minPos = min_element(shortestLengths.begin(), shortestLengths.end());
    int minIndex = distance(shortestLengths.begin(), minPos);

    // Копіювання рядків (крім рядка з найкоротшим словом) до файлу F2
    for (int i = 0; i < lines.size(); ++i)
    {
        if (i != minIndex)
        {
            fileOut << lines[i] << endl;
        }
    }

    fileOut.close();

    cout << "Successfully copied data from file F1.txt to file F2.txt, except for the line with the shortest word." << endl;

    return 0;
}
