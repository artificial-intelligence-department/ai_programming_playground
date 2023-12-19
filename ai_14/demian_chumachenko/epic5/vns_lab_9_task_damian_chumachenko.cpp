#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N,N1,N2;
    vector<string> myVector;
    int maxLine = 0;
    int maxCount = 0;
    string line, line2;
    int currentLine = 0;
    int currentLine2 = 0;

    cin >> N;
    for(int i = 0; i < 10; i++){
        string a;
        cin >> a;
        myVector.push_back(a);
    }
    cout << endl;
    cin >> N1 >> N2;

    ofstream fileF1("F1.txt");

    for (int i = 0; i < N; ++i) {
        fileF1 << myVector[i] << endl;
    }

    fileF1.close();

    ifstream fileF2("F1.txt");
    ofstream fileF3("F2.txt");

    while (getline(fileF2, line)) {
        ++currentLine;

        if (currentLine >= N1 && currentLine <= N2 && line.back() == 'A') {
            fileF3 << line << '\n';
        }
    }

    fileF2.close();
    fileF3.close();

    ifstream fileF4("F2.txt");

    while (getline(fileF4, line)) {
        ++currentLine2;

        int Count = count(line.begin(), line.end(), 'A');

        if (Count > maxCount) {
            maxCount = Count;
            maxLine = currentLine2;
        }
    }

    fileF4.close();

    cout << "The line in F2 with the most 'A' characters is: " << maxLine << '\n';

    return 0;
}