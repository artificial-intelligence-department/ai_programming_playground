#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int countOfConsonants(const string& word)
{
    int count = 0;
    for(char c : word)
    {
        if(isalpha(c) && !strchr("aeiouAEIOU", c))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    ofstream F1_output("F1.txt");
    
    F1_output << "My name is Yana" << endl;
    F1_output << "Student" << endl;
    F1_output << "Programming is my passion" << endl;
    F1_output << "Christmas is coming" << endl;
    F1_output << "AI" << endl;
    F1_output << "Let is snow" << endl;
    F1_output << "Some information" << endl;
    F1_output << "The great Gatsby" << endl;
    F1_output << "Winter" << endl;
    F1_output << "Night" << endl;

    F1_output.close();


    ifstream F1_input("F1.txt");
    ofstream F2_output("F2.txt");

    string STRING;
    int currentNumberOfWord = 0;
    int maximum = 0;
    int numberOfWord = 0;

    while (getline(F1_input, STRING)) // поки зчитка з файлу успішна
    {
        cout << "Read: " << STRING << endl;

        bool oneWord = true; 
        for (char w : STRING)
        {
            if (w == ' ')
            {
                oneWord = false;
                break; 
            }
        }

        if(oneWord)
        {
            currentNumberOfWord++;
            int numberOfConsonants = countOfConsonants(STRING);

            if(numberOfConsonants > maximum)
            {
                maximum = numberOfConsonants;
                numberOfWord = currentNumberOfWord;
            }


            F2_output << STRING << endl;
        }
    }

    F1_input.close();
    F2_output.close();

    cout << endl;
    ifstream F2_input("F2.txt");
    
    string line;
    while (getline(F2_input, line))
    {
        cout << line << endl;
    }

    F2_input.close();

    cout << endl;
    cout << "The number of word with the biggest count of consonants: " << numberOfWord << endl;
    
    return 0;
}
