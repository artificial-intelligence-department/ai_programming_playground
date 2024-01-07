#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void mostUsedA(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int lineNumber = 0;
    int maxCount = 0;
    int currentLine = 0;

    string lineWithMostA;

    string line;
    while (getline(file, line))
    {
        int count = 0;
        for (char ch : line)
        {
            if (ch == 'A' || ch == 'a')
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            lineNumber = currentLine;
            lineWithMostA = line;
        }

        currentLine++;
    }

    file.close();

    cout << "Line with the most occurrences of 'A' or 'a' in file: " << lineWithMostA << endl;
}

void pushToF2(const string &filename, const string &text)
{
    ofstream file(filename, ios::app);
    file << text << endl;
    file.close();
}

void pushTextToFile(const string &filename, const string &text)
{
    ofstream file(filename, ios::app);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    file << text << endl;
    file.close();
}

int main()
{
    const string file1 = "F1.txt";
    const string file2 = "F2.txt";
    int N1, N2;

    ofstream clearFile(file1, ios::trunc);
    clearFile.close();
    ofstream clearFile2(file2, ios::trunc);
    clearFile2.close();

    for (int i = 0; i < 10; i++)
    {
        string text;
        cout << "Type " << i + 1 << " line of text: ";
        getline(cin, text);
        pushTextToFile(file1, text);
    }

    ifstream inputFile(file1);
    if (!inputFile.is_open())
    {
        cerr << "Error opening file: " << file1 << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Type N1 and N2 (0 < N1, N2 < 10): ";
    cin >> N1 >> N2;

    int count = 0;
    cout << "\nLines ending with 'A' or 'a' and placed between " << N1 << " row and " << N2 << " row:\n";
    string line;
    while (getline(inputFile, line))
    {
        if (!line.empty() && (line.back() == 'A' || line.back() == 'a'))
        {
            if (count >= N1 && count < N2 - 1)
            {
                cout << line << endl;
                pushToF2(file2, line);
            }
        }
        count++;
    }
    inputFile.close();

    mostUsedA(file2);

    return 0;
}
