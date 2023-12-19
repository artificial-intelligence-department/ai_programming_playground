#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

string CleanWord(string &word)
{
    string cleaned;
    for (char c : word)
    {
        if (isalnum(c))
        {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

int main()
{
    string text[] = 
    {"Binary files store data in a compact format, using sequences of bytes.\n",
    "Text files, in contrast, contain readable text encoded in ASCII or Unicode.\n",
    "Reading and writing binary files require dealing with raw data at a byte level.\n",
    "Text files, being human-readable, are commonly used for documents and configuration files.\n",
    "Binary files are suitable for preserving complex structures and non-textual data.\n",
    "Handling text files involves operations on strings and characters.\n",
    "When working with binary files, attention to data representation and endianness is crucial.\n",
    "Textual content in files facilitates easier comprehension and editing by humans.\n",
    "The <fstream> library in C++ offers classes for file handling tasks.\n",
    "Understanding the differences between these file types aids in selecting the appropriate format for specific tasks.\n"};

    ofstream fout1("F1.txt");
    if (!fout1)
    {
        cerr << "An error occurred" << endl;
        return 1;
    }
    for (const string str : text)
    {
        fout1 << str;
    }
    string line, word;
    fout1.close();

    ifstream fin1("F1.txt");
    ofstream fout2("F2.txt");
    if (!fin1 || !fout2)
    {
        cerr << "An error occurred" << endl;
        return 1;
    }
    while(getline(fin1, line))
    {
        vector<string> line_words;
        istringstream iss(line);
        bool unique = true;
        while (iss >> word)
        {
            line_words.push_back(CleanWord(word));
        }
        for (int i = 0; i < line_words.size() && unique; i++)                            
        {
            for (int j = i + 1; j < line_words.size(); j++)
            {
                if (line_words[i] == line_words[j])
                {
                    unique = false;
                    break;
                }
            }
        }
        if (unique)
        {
            fout2 << line << endl;
        }
    }
    fout2.close(), fin1.close();

    ifstream fin2("F2.txt");
    if (!fin2)
    {
        cerr << "An error occurred" << endl;
        return 1;
    }
    string first_line;
    int vowels = 0;
    getline(fin2, first_line);
    for (char c : first_line)
    {
        if (c = tolower(c) && (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u' || c == 'y')) vowels++;
    }
    fin2.close();

    cout << "There are " << vowels << " vowels in the first line\n";
    return 0;
}