#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Human
{
    string personInitials;
    string yearOfBirth;
    string height;
    string weight;
};

vector<string> parseStringToStringArr(string input)
{
    vector<string> arr;
    string buff;

    for (int i = 0; i < input.size(); i++)
    {
        bool isSeparator = false;
        if (input[i] == ';')
        {
            isSeparator = true;
        }

        if (isSeparator)
        {
            arr.push_back(buff);
            buff = "";
        }
        else
        {
            buff += input[i];
        }
    }
    return arr;
}

vector<Human> parseStringArrToHumanArr(vector<string> parsedData)
{
    vector<Human> data;
    for (int i = 0; i < parsedData.size() - 1; i += 4)
    {
        Human buff = {parsedData[i], parsedData[i + 1], parsedData[i + 2], parsedData[i + 3]};
        data.push_back(buff);
    }
    return data;
}

vector<Human> deleteElementFromArr(vector<Human> arr, string height, string weight)
{
    vector<Human> newArr;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].height != height && arr[i].weight != weight)
        {
            newArr.push_back(arr[i]);
        }
    }
    return newArr;
}

void writeLine(string path, Human data)
{
    ofstream file;
    file.open(path, ios_base::app);
    if (!file)
    {
        cout << "File doesn't exist\n";
        return;
    }
    file << data.personInitials << ";"
         << data.yearOfBirth << ";"
         << data.height << ";"
         << data.weight << ";\n";
    file.close();
}

string readAll(string path)
{
    string output;
    string currentLine;
    ifstream file;
    file.open(path, ios_base::app);
    if (!file)
    {
        return "File doesn't exist\n";
    }
    while (getline(file, currentLine))
    {
        output += currentLine;
        cout << currentLine << "\n";
    }

    file.close();
    return output;
}

void deleteFileContents(string path)
{
    ofstream file(path, ios::trunc);
    file.close();
}

const string PATH = "C:/files/university/programming-paradigms/data/data.txt";

int main()
{
    deleteFileContents(PATH);
    writeLine(PATH, {"Shliakhetko Danylo Vitaliovych", "2006", "188", "72"});
    writeLine(PATH, {"Vinnyk Andrew Olehovych", "2007", "185", "67"});
    writeLine(PATH, {"Chuma David Serhiyovych", "2005", "180", "75"});
    writeLine(PATH, {"Pediak Uliana Viktorivna", "2002", "174", "50"});
    writeLine(PATH, {"Kozlovskyi Anatolii Stepanovych", "2000", "195", "120"});

    cout << "Created file contents:\n";
    string contents = readAll(PATH);
    vector<Human> arr = parseStringArrToHumanArr(parseStringToStringArr(contents));

    cout << "Enter person's height to delete: ";
    string height;
    cin >> height;
    cout << "Enter person's weight to delete: ";
    string weight;
    cin >> weight;

    arr = deleteElementFromArr(arr, height, weight);
    deleteFileContents(PATH);
    writeLine(PATH, {"Sabdyliuk Marko Vasylovych", "2004", "174", "62"});
    writeLine(PATH, {"Zinoviev Volodymyr Alexandrovych", "2003", "190", "80"});
    for (int i = 0; i < arr.size(); i++)
    {
        writeLine(PATH, {arr[i].personInitials, arr[i].yearOfBirth, arr[i].height, arr[i].weight});
    }
    cout << "New file contents:\n";
    readAll(PATH);

    return 0;
}