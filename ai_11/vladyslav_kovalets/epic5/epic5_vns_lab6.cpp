#include <iostream>
#include <string>
#include <sstream>

int main() 
{
    std::string input;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, input);

    // використовується для розбиття введеного рядка на окремі слова які можна потім обробити окремо.
    std::istringstream iss(input); //  клас для створення лінії який можна використовувати для читання з рядка
    std::string token;

    while (iss >> token) 
    // код який виконується для кожного слова в лінії 'iss'
    {
        bool hasVowel = false;
        for (char c : token)
        // код який виконується для кожного символу в змінній 'token'
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
            {
                hasVowel = true;
                break;
            }
        }

        if (!hasVowel) 
        {
            std::cout << token << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
