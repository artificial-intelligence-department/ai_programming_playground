#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() 
{
    char text[250];
    cout << "Enter text separated by spaces -" << endl;
    cin.getline(text, 250);

    regex identyficatorRegex("[^A-Za-z0-9]+");
    string result = regex_replace(text, identyficatorRegex, " ");

    cout << "Result: " << result << endl;

    return 0;
}
