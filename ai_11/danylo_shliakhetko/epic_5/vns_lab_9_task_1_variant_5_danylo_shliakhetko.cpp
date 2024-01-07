#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string PATH = "C:/files/university/programming-paradigms/data/";

const string F1 = "F1.txt";
const string F2 = "F2.txt";

void read(string path)
{
    ifstream file;
    file.open(path, ios_base::app);
}

void copyF1ToF2(string path, int k)
{
    int max = k + 5;
    if (k < 0 || max > 10)
    {
        cout << "Enter valid k";
        return;
    }
    vector<string> output;
    string currentLine;
    ifstream readFile;
    readFile.open(path + F1, ios_base::app);
    if (!readFile)
    {
        cout << "File doesn't exist\n";
        return;
    }
    cout << "Reading file F1...\n\n";
    while (getline(readFile, currentLine))
    {
        cout << currentLine << "\n";
        output.push_back(currentLine);
    }
    readFile.close();
    cout << "\nRead file F1"
         << "\n";

    ofstream deleteFile(path + F2, ios::trunc);
    deleteFile.close();

    ofstream writeFile;
    writeFile.open(path + F2, ios_base::app);
    if (!writeFile)
    {
        cout << "File doesn't exist\n";
        return;
    }
    for (; k < max; k++)
    {
        writeFile << output[k] << "\n";
    }
    writeFile.close();
    cout << "Write file F2"
         << "\n\n";
}

void countVowels(string path)
{
    string output;
    string currentLine;
    ifstream readFile;
    readFile.open(path + F2, ios_base::app);
    if (!readFile)
    {
        cout << "File doesn't exist\n";
        return;
    }
    cout << "Reading file F2...\n\n";
    while (getline(readFile, currentLine))
    {
        cout << currentLine << "\n";
        output += currentLine;
    }
    readFile.close();
    cout << "\nRead file F2"
         << "\n";
    int count = 0;
    for (int i = 0; i < output.size(); i++)
    {
        char c = output[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
        {
            count++;
        }
    }
    cout << "In file F2 there are " << count
         << " vowels\n";
}

int main()
{
    int input;
    cout << "Enter k:\n";
    cin >> input;
    copyF1ToF2(PATH, input);
    countVowels(PATH);
    return 0;
}