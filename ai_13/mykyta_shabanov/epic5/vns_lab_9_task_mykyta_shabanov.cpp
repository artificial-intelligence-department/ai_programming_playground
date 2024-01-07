#include <fstream>
#include <iostream>

using namespace std;

ofstream CopyFile(int start, int end)
{
    ifstream fin ("F1.txt");
    ofstream fout ("F2.txt");

    if(!fin.is_open())
    {
        cout << "error whily try to open file> " << endl;
        return fout;
    }

    string line;
    for(int i = 0; getline(fin, line); i++)
    {
        if(i < start)
            continue;
        else if(i > end)
            continue;
        
        fout << line << endl;
    }
    
    return fout;
}

bool isConsonant(char chr)
{
    chr = tolower(chr);

    if(chr == 'b' || chr == 'c' || chr == 'd' || chr == 'f' || 
        chr == 'g' || chr == 'h' || chr == 'j' || chr == 'k' || 
        chr == 'l' || chr == 'm' || chr == 'n' || chr == 'p' || 
        chr == 'r' || chr == 's' || chr == 't' || chr == 'v' || 
        chr == 'w' || chr == 'x' || chr == 'y' || chr == 'z' ||
        chr == 'q')
    {
        return true;
    }
    else return false;
}

int CalculateConsonantLetters(string fileName)
{
    ifstream fin(fileName);
    string line;
    int result = 0;

    for (int i = 0; getline(fin, line); i++)
    {
        for (int j = 0; j < line.size(); j++)
        {
            if(isConsonant(line[j]))
                result++;
        }
        
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    ofstream textFile = CopyFile(n, k);

    int result = CalculateConsonantLetters("F2.txt");

    cout << "Кількість приголосних у файлі F2: " << result << endl;

    return 0;
}