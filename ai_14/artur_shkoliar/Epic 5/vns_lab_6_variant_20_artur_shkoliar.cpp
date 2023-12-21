#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string enter;

    cout << "Введіть рядок: ";
    getline(cin, enter);

    
    if (enter.back() != '.')
    enter += ".";

    size_t lenghtofword = 0;
    size_t wordlenght = 0;

    
    for (char ch : enter) {
        if (isspace(ch) || ch == '.') 
        {
            
            if (wordlenght > lenghtofword) 
            {
                lenghtofword = wordlenght;
            }
            wordlenght = 0; 
        } 
        else 
        {
        
            wordlenght++;
        }
    }

    
    cout << "Довжина найдовшого слова: " << lenghtofword << " букв" << endl;

    return 0;
}
