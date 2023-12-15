#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void copying (const string& enter_filename, const string& output_filename, char start_copy, int raw_1, int raw_2) 
{
    ifstream enter_file (enter_filename);
    ofstream outputFile (output_filename);

    if (!enter_file.is_open() || !outputFile.is_open()) 
    {
        cerr << "Помилка відкриття файлів." << endl;
        return;
    }

    vector <string> lines;
    string line;

    // Читаємо всі рядки з файлу
    while (getline (enter_file, line)) 
    {
        lines.push_back(line);
    }

    // Копіюємо рядки, які починаються на 'A' і розташовані між 1 і N2
    for (int i = raw_1 - 1; i < raw_2 && i < lines.size(); ++i) 
    {
        if (!lines[i].empty() && lines[i][0] == start_copy) 
        {
            cout << lines[i] << endl;
            outputFile << lines[i] << endl;
        }
    }

    // Додаємо всі рядки від N2+3 до останнього
    for (int i = raw_2 + 2; i < lines.size(); ++i) 
    {
        cout << lines[i] << endl;
        outputFile << lines[i] << endl;
    }

    enter_file.close();
    outputFile.close();
}

int main() 
{
    string enter_text;
    string output_filename_1, output_filename_2;
    char start_copy;
    int raw_1, raw_2;

    cout << "Введіть текст файлу (введіть '0' для переходу далі):\n";

    // Ввід тексту для файла
    while (true) 
    {
        string line;
        getline(cin, line);

        if (line == "0") 
        {
            break;
        }

        enter_text += line + '\n';
    }

    cout << "Введіть назву першого файлу: ";
    cin >> output_filename_1;

    // Збереження введеного тексту в перший файл
    ofstream inputFile(output_filename_1);
    
    inputFile << enter_text;
    inputFile.close();

    cout << "Введіть назву другогофайлу: ";
    cin >> output_filename_2;

    // Введення рядка N1
    cout << "Введіть номер рядка N1: ";
    cin >> raw_1;

    // Введення рядка N2
    cout << "Введіть номер рядка N2: ";
    cin >> raw_2;

    // Введення символу, з якого починаємо копіювання
    cout << "Введіть символ, з якого починаємо копіювання: ";
    cin >> start_copy;

    // Викликаємо функцію для копіювання та додавання рядків
    copying (output_filename_1, output_filename_2, start_copy, raw_1, raw_2);

    return 0;
}
