#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int countVowels(const string& words) {
    int count = 0;
    for (char letter : words) {
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y') {
            count++;
        }
    }
    return count;
}

int main() {
    string str[] = {"Hello everyone, my name is Yura \nI am glad to meet you"};

    ofstream file("file.txt");
    if (!file.is_open()) return 0;

    for (int i = 0; i < 2; ++i) {
        file << str[i] << endl;
    }
    file.close();

    ifstream file1("file.txt");
    ofstream file2("file2.txt");
    if (!file1.is_open() || !file2.is_open()) return 0;

    string line1;
    while(getline(file1, line1)){
        istringstream iss(line1);   //розбиваємо line1 на слова.
        string word;                //буде використовуватися для зберігання кожного окремого                          
        int wordCount = 0;          // слова під час розбиття рядка.
        while (iss >> word) {       //iss (відокремлений рядок line1) розбивається на                          
            wordCount++;            // окремі слова, які записуються у word
        }
        if (wordCount > 2) {
            file2 << line1 << endl;
        }
    }

    file1.close();
    file2.close();

    ifstream file3("file.txt");
    if (!file3.is_open()) return 0;

    int Vowel = 0;
    int word_index = 0;
    string line2;
    while (getline(file3, line2)) {
        istringstream iss(line2);
        string words;
        int currentWord = 0;
        while (iss >> words) {
            currentWord++;
            int vowelCount = countVowels(words);
            if (vowelCount > Vowel) {
                Vowel = vowelCount;
                word_index = currentWord;
            }
        }
    }
    file3.close();

    cout << "Result: word index - " << word_index << "\t\tmax amount of vowels - " << Vowel << endl;

    return 0;
}