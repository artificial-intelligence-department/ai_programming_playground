#include <iostream>
#include <fstream>
#include <string>


using namespace std;

bool isConsonant(char symbol) 
{
    symbol = tolower(symbol);
    return (symbol >= 'a' && symbol <= 'z' && symbol != 'a' && symbol != 'e' && symbol != 'i' && symbol != 'o' && symbol != 'u');
}

void copyLinesFromF1ToF2(const string& f1, const string& f2, int startLine, int endLine)
{
    ifstream file1(f1);
    ofstream file2(f2);
    if (!file1 || !file2) {
        cerr << "File didn't open!" << endl;
        return;
    }

    string line;
    int currentLine = 0;

    while (getline(file1, line)) 
    {
        if (currentLine >= startLine && currentLine <= endLine && line[0] == 'A')
        {
            file2 << line << endl;
        }

        if (currentLine == endLine)
        {
            break;
        }
        currentLine++;
    }

    file1.close();
    file2.close();
}

int findMaxConsonantLine(const string& userfile) {

    ifstream file(userfile);

 
    if (!file) {
        cerr << "File didn't open!" << endl;
        return -1;
    }

    
    int maxConsonantCount = 0;// Лічильник максимальної кількості приголосних 
    
    int maxConsonantLine = 0;// Номер рядка з максимальною кількістю приголосних 

   
    int currentLine = 1; // Номер поточного рядка

    char symbol;

    while (file.get(symbol)) {
       
        if (symbol == '\n') {
            
            currentLine++;
        }
        else if (isConsonant(symbol)) {
            
            int currentConsonantCount = 1;//лічильник приголосних

      
            while (file.get(symbol) && symbol != '\n') 
            {
                if (isConsonant(symbol)) 
                {
                    currentConsonantCount++;
                }
            }


            if (currentConsonantCount > maxConsonantCount) 
            {
                maxConsonantCount = currentConsonantCount;
                maxConsonantLine = currentLine;
            }
        }
    }


    file.close();


    return maxConsonantLine;
}


int main() {
    string f1 = "F1.txt";
    string f2 = "F2.txt"; 
    int startLine, endLine;

    cout << "Enter the starting line: ";
    cin >> startLine;
    cout << "Enter the ending line: ";
    cin >> endLine;

    copyLinesFromF1ToF2(f1, f2, startLine, endLine);
    cout << "Lines copied from F1 to F2 from line " << startLine << " to line " << endLine << endl;

    int consonantCount = findMaxConsonantLine(f2); 
    if (consonantCount != -1) {
        cout << "Max Number of consonants in (line) file F2: " << consonantCount << endl;
    }

    return 0;
}