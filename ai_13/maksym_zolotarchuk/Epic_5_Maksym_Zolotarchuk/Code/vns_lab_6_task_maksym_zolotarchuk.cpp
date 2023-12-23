#include <iostream>
#include <string>
#include <sstream> // istringstream
using namespace std;



int main() 
{
    string token;

    cout << "Enter a string: " << endl;


    getline(cin, token);

    istringstream iss(token);
    string word;
    int numbers = 0;

    while (iss >> word)
    {
        for (int c : word) 
        {
            if (isdigit(c)) 
            {
                ++numbers;
            }
        }
    }
    if (numbers == 1) 
    {
        cout << word;
    }
    else
    {
        cout << "This word doesn't have number" << endl;
    }

    

    return 0;
}
