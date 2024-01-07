#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int countConsonants(const string &str) {
    int count = 0;

    for (char symbol : str) {
        if (isalpha(symbol) && !(symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' || symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U')) {
            count++;
        }
    }

    return count;
}

int main() {
    ofstream File1("File1.txt");
    ofstream File2("File2.txt");
    string buf;
    int row1, row2, maxConsonants = 0, currentLine = 0, maxConsonantsLine = 0;
    bool startCopying = false, endCopying = false;

    // Вводимо 10 рядків в файл File1.
    cout << "Введіть 10 рядків для того, щоб записати його у файл F1:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Рядок " << i + 1 << ": ";
        getline(cin, buf);
        File1 << buf << endl;
    }

    File1.close();

    // Введення row1 та row2
    cout << "Введіть row1 та row2 (межі): ";
    cin >> row1 >> row2;

    // Відкриття файлу F1 для читання
    ifstream in("File1.txt");

    // Копіювання рядків з файлу File1 в File2, які знаходяться між рядками з номерами row1 і row2 і починаються на "A" або "a"
    while (getline(in, buf)) {
        currentLine++;

        if (currentLine >= row1 && currentLine <= row2) {
            if (buf[0] == 'A' || buf[0] == 'a') {
                File2 << buf << endl;
            }
        }

        // Знаходження рядка з максимальною кількістю приголосних букв
        int consonantsCount = countConsonants(buf);
        if (consonantsCount > maxConsonants) {
            maxConsonants = consonantsCount;
            maxConsonantsLine = currentLine;
        }

        // Початок копіювання після рядка row1
        if (currentLine == row1) {
            startCopying = true;
        }

        // Закінчення копіювання після рядка row2
        if (currentLine == row2) {
            endCopying = true;
        }

        // Вихід з циклу після закінчення копіювання
        if (endCopying) {
            break;
        }
    }

    // Закриття файлів
    in.close();
    File2.close();

    cout << "Результат збережено у файлі File2.txt." << endl;
    cout << "Рядок з найбільшою кількістю приголосних у File2.txt: " << maxConsonantsLine << endl;

    return 0;
}
