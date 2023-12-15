// ConsoleApplication104.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int arraymaximum(vector<int> array, int size, int& n)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            n = i;
        }
    }

    return max;
}
int arraymaximum(int array[], int size, int& n)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            n = i;
        }
    }

    return max;
}
bool doubleword(string str)
{
    bool dublicate = false;
    vector<string> words;
    words.resize(100);
    int size = str.size();
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        
        if (str[i] != ' ' && str[i] != NULL && str[i] != '.' && str[i] != ',')
        {
            words[j].push_back(str[i]);
        }
        if (str[i] == ' ')
        {
            j++;
        }
    }

    for (int i = 0; i < j; i++)
    {
        for (int m = 0; m < j; m++)
        {
            if (i != m && words[i] == words[m])
            {
                dublicate = true;
            }
        }
    }
    return dublicate;
}
    int aCounter(string str, int& identificator)
    {
        vector<string> words;
        words.resize(100);
        int j = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ' && str[i] != NULL && str[i] != '.' && str[i] != ',')
            {
                words[j].push_back(str[i]);
            }
            if (str[i] == ' ')
            {
                j++;
            }
        }
        vector<int> amount;
        amount.resize(j);
        for (int i = 0; i < j; i++)
        {
            int count = 0;
            for (int m = 0; m < words[i].size(); m++)
            {
                if (words[i][m] == 'a')
                {
                    count++;
                }
            }
            amount[i] = count;
            

        }
        int index = 0;
        int x = arraymaximum(amount, j, index);
        identificator = index;
        return x;

        
            
    }

int main()
{
    ifstream input("file1.txt");
    if (!input)
    {
        cerr << "Can't read the file";
    }
    else
    {
        vector<string> text;
        text.resize(100);
        string str;
        cout << "The text in the file is:" << endl;
        int j = 0;
        while (getline(input, str))
        {
            cout << str << endl;
            text[j] = str;
            j++;

        }
        int rows = j;
        ofstream output("file2.txt");
        if (!output)
        {
            cerr << "Can't open the file for writing";
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                if (doubleword(text[i]))
                {
                    output << text[i] << endl;
                }
            }
            cout << "\033[1;32m" << "The file was written successfully" << "\033[0m" << endl;
        }
        int* maxletters = new int[rows];
        int* counters = new int[rows] {0};
        for (int i = 0; i < rows; i++)
        {
            maxletters[i] = aCounter(text[i], counters[i]);
            cout << "In line #" << i+1 << " the word #"  << counters[i] + 1 << " has the biggest amount of letter a" << endl;
        }

        int identificator = 0;
        int max = arraymaximum(maxletters, rows, identificator);
        cout << "Max letters has the word #" << counters[identificator] + 1 << " in a line #" << identificator+1;
    }
    

    
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
