#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void copyrow(const string& inputFile, const string& outputFile) 
{
    ifstream f1(inputFile);
    ofstream f2(outputFile);

    if (!f1.is_open()) 
    {
        cerr << "Помилка при відкритті файлу F1" << endl;
        return;
    }

    if (!f2.is_open()) 
    {
        cerr << "Помилка при відкритті файлу F2" << endl;
        return;
    }

    set<string> wordsInLastRow;
    string row;

   
    while (getline(f1, row)) 
    {

        size_t start = 0, end;
        while ((end = row.find(' ', start)) != string::npos) 
        {
            wordsInLastRow.insert(row.substr(start, end - start));
            start = end + 1;
        }
        wordsInLastRow.insert(row.substr(start));
    }

    f1.close();  

    
    f1.open(inputFile);


    while (getline(f1, row)) 
    {
        size_t start = 0, end;
        bool hasCommonWords = false;

       
        while ((end = row.find(' ', start)) != string::npos) 
        {
            if (wordsInLastRow.count(row.substr(start, end - start))) 
            {
                hasCommonWords = true;
                break;
            }
            start = end + 1;
        }

        if (wordsInLastRow.count(row.substr(start))) 
        {
            hasCommonWords = true;
        }

        if (hasCommonWords) 
        {
            f2 << row << endl;
        }
    }

    f1.close();  
    f2.close();  
}


int golosni(const string& str) 
{
    int count = 0;
    for (char ch : str) 
    {
        char lowerCh = tolower(ch);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') 
        {
            count++;
        }
    }
    return count;
}


int main() {
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Помилка при створенні файлу F1" << endl;
        return 1;
    }

    f1 << "Cat, book, lamp" << endl;
    f1 << "Tree, river, mountain" << endl;
    f1 << "Car, road, sunset" << endl;
    f1 << "Coffee, chair, window" << endl;
    f1 << "Song, guitar, melody" << endl;
    f1 << "Flower, garden, bee" << endl;
    f1 << "Rain, umbrella, puddle" << endl;
    f1 << "Friend, laughter, memory" << endl;
    f1 << "Sky, cloud, airplane" << endl;
    f1 << "Beach, sand, seashell" << endl;

    f1.close();

    copyrow("F1.txt", "F2.txt");

    ifstream f2("F2.txt");
    if (!f2.is_open()) 
    {
        cerr << "Помилка при відкритті файлу F2" << endl;
        return 1;
    }

    string lastRow, currentRow;
    while (getline(f2, currentRow)) 
    {
        lastRow = currentRow;  
    }

    f2.close(); 

    cout << "Останній рядок файлу F2: " << lastRow << endl;
    cout << "Кількість голосних букв у останньому рядку F2: " << golosni(lastRow) << endl;

    return 0;
}
