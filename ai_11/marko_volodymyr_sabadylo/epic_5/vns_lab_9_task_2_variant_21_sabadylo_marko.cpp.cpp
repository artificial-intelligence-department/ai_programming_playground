#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <random>

using namespace std;

// Функція для підрахунку голосних букв у слові
int countVowels(const string& word) {
    int count = 0;
    for (char c : word) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            count++;
        }
    }
    return count;
}

// Функція для генерації випадкових слів
string generateRandomWord(int length) {
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    string word;
    for (int i = 0; i < length; ++i) {
        word += alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    return word;
}

int main() {
    // Створення файлу F1 та запис 10 рядків у нього
    ofstream fileF1("F1.txt");
    if (!fileF1.is_open()) {
        cerr << "Unable to open F1.txt\n";
        return 1;
    }

    srand(time(nullptr));  // Ініціалізація генератора випадкових чисел

    for (int i = 0; i < 10; ++i) {
        fileF1 << generateRandomWord(5) << " " << generateRandomWord(4) << " " << generateRandomWord(6) << endl;
    }
    fileF1.close();

    // Створення файлу F2 для запису рядків
    ofstream fileF2("F2.txt");
    ifstream readFile("F1.txt");

    if (!fileF2.is_open() || !readFile.is_open()) {
        cerr << "Unable to open one of the files.\n";
        return 1;
    }

    string line;
    int wordNumberWithMaxVowels = -1;
    int maxVowelCount = 0;

    while (getline(readFile, line)) {
        istringstream iss(line);
        string word;
        vector<string> words;

        while (iss >> word) {
            words.push_back(word);
        }

        if (words.size() > 2) {
            fileF2 << line << endl;

            for (size_t i = 0; i < words.size(); ++i) {
                int vowelCount = countVowels(words[i]);
                if (vowelCount > maxVowelCount) {
                    maxVowelCount = vowelCount;
                    wordNumberWithMaxVowels = i + 1;  // Номер слова починається з 1
                }
            }
        }
    }

    readFile.close();
    fileF2.close();

    if (wordNumberWithMaxVowels != -1) {
        cout << "The word number with the most vowels is: " << wordNumberWithMaxVowels << endl;
    } else {
        cout << "No words with vowels found.\n";
    }

    return 0;
}