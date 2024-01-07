//Вам дана стрічка s.
//Ваше завдання зробити компресію стрічки, тобто якщо якась буква йде більше одного разу підряд у стрічці замінити її на букву + кількість входжень підряд.
#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::cin >> word;
    std::string new_string = "";
    int counter;
    for (int i = 0; i < word.size(); i++)
    {
        counter = 1;

        for (int j = i + 1; j < word.size(); j++)
        {
            if (word[i] != word[j])
            {
                break;
            }
            counter += 1;
            word.erase(j, 1);
            j--;
        }

        if (counter > 1)
        {
            new_string += word[i];
            new_string += std::to_string(counter);
        }
        else
        {
            new_string += word[i];
        }
    }
    std::cout << new_string;
    return 0;
}