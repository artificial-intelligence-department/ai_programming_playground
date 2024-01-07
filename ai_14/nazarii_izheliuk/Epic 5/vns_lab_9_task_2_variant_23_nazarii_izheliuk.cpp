#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void similar_words(){
    ifstream file1("C:/Users/Lenovo Gaming/Desktop/F1.txt");
    ofstream file2("C:/Users/Lenovo Gaming/Desktop/F2.txt");
    string line;

    while (getline(file1, line)) {
        istringstream iss(line);
        string word;
        iss >> word; 
        
        while (iss >> word) {
            size_t found = line.find(word);
            if (found != string::npos && line.find(word, found + 1) != string::npos) {
                file2 << line << endl; 
                break; 
            }
        }
    }
}

int find_A() {
    ifstream file1("C:/Users/Lenovo Gaming/Desktop/F1.txt");
    string line;

    int wordNumber = 0;
    int max_A_count = 0;
    int word_with_most_A_number = 0;

    while (getline(file1, line)) {
        istringstream iss(line);
        string word;
        wordNumber = 0;

        while (iss >> word) {
            int count = 0;

            for (char letter : word) {
                if (letter == 'A' || letter == 'a') {
                    count++;
                }
            }

            wordNumber++; 
            if (count > max_A_count) {
                max_A_count = count;
                word_with_most_A_number = wordNumber;
            }
        }
    }

    return word_with_most_A_number;
}

int main(){
    string text;
    ofstream file1("C:/Users/Lenovo Gaming/Desktop/F1.txt");
    
    for(int i = 0; i < 10; i++){
        getline(cin, text);
        file1 << text;
        file1 << endl;
        text = "";
    }

    similar_words();

    int wordNumberWithMostA = find_A();
    cout << wordNumberWithMostA << endl;
    return 0;
}
