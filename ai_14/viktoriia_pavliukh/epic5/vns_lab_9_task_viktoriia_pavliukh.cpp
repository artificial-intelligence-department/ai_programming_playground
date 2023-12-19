#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int countVowels(const string& word) {
    int vowelCount = 0;
    for (char ch : word) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
            vowelCount++;
        }
    }
    return vowelCount;
}

int main() {
    string str[] =
            {  "Maids table.\n",
               "Music.\n",
               "Hand dear so we hour to. He we be hastily offence effects he service.\n",
               "Sympathize it projection ye insipidity celebrated my pianoforte indulgence.\n",
               "Point.\n",
               "Elegance exercise as laughing proposal mistaken if.\n",
               "We up precaution an it solicitude acceptance invitation.\n",
               "Am terminated it excellence invitation projection as.\n",
               "Supply.\n",
               "Design for are edward regret met lovers.\n"
            };

    // Writing to F1.txt
    ofstream file1("F1.txt");
    if (!file1) {
        cerr << "An error occurred " << endl;
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        file1 << str[i] << endl;
    }
    file1.close();

    // Task 1:
    ifstream file1_1("F1.txt");
    ofstream file2("F2.txt");
    if (!file1_1 || !file2) {
        cerr << "An error occurred" << endl;
        return 1;
    }

    string line1;
    while (getline(file1_1, line1)) {   //Зчитується кожен рядок з файлу "F1.txt"
                                            // і зберігається в рядку line1.
        istringstream iss(line1); //розбиваємо line1 на слова.
        string word;       //буде використовуватися для зберігання кожного окремого
                            // слова під час розбиття рядка.
        int wordCount = 0;
        while (iss >> word) {  //iss (відокремлений рядок line1) розбивається на
                                // окремі слова, які записуються у word
            wordCount++;
        }
        if (wordCount > 2) {
            file2 << line1 << endl;
        }
    }
    file2.close();
    file1_1.close();

    // Task 2:
    ifstream file2_2("F2.txt");
    if (!file2_2) {
        cerr << "An error occurred" << endl;
        return 1;
    }

    int maxVowelCount = 0;
    int wordNumber = 0;
    string line2;
    while (getline(file2_2, line2)) {
        istringstream iss(line2);
        string word;
        int currentWordNumber = 0;
        while (iss >> word) {
            currentWordNumber++;
            int vowelCount = countVowels(word);
            if (vowelCount > maxVowelCount) {
                maxVowelCount = vowelCount;
                wordNumber = currentWordNumber;
            }
        }
    }
    file2_2.close();

    cout << "The word with the most vowels is at position " << wordNumber << " with " << maxVowelCount << " vowels." << endl;

    return 0;
}