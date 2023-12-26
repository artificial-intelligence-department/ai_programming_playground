#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    string mas[M];

    for (int i = 0; i < M; i++) {
        cin >> mas[i];
    }

    string path = "Test3.txt";
    ofstream fout(path);

    if (!fout.is_open()) {
        cout << "Помилка при відкритті файлу для запису." << endl;
        return 1;
    } else {
        for (int i = 0; i < M; i++) {
            fout << mas[i] << endl;
        }
        fout.close();
    }

    ifstream fin(path);

    if (!fin.is_open()) {
        cout << "Помилка при відкритті файлу для читання." << endl;
        return 1;
    } else {
        unordered_map<char, int> charCount;
        unordered_set<char> repeatedChars;

        char ch;
        while (fin.get(ch)) {
            if (ch != '\n') {
                charCount[ch]++;

                if (charCount[ch] > N) {
                    repeatedChars.insert(ch);
                }
            }
        }

        if (repeatedChars.size() == 0) {
            cout << "Empty!";
            return 0;
        }

        cout << repeatedChars.size() << endl;

        for (const char &ch : repeatedChars) {
            cout << ch << " ";
        }
        cout << endl;
    }

    fin.close();

    return 0;
}
