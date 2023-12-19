#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int length_yard = 110;
const char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

float YardsToMeters (int yard);
int countVowels(string str, int index, int counter);
int findIntersection(string surname, float length, float letter_length);

struct Length
{
    float m;
    float yards;
};

int main()
{
    string surname;
    Length field;
    field.yards = length_yard;

    cout << "Enter surname: ";
    cin >> surname;

    field.m  = YardsToMeters(length_yard);

    double letter_length = 0.8 * countVowels(surname, 0, 0);
    double surname_length = letter_length * surname.length();

    cout << "surname_length = " << surname_length << endl;
    cout << "field.m = " << field.m << endl;
    
    cout << "1)";
    cout << findIntersection(surname, field.m, letter_length);


    return 0;
}
float YardsToMeters(int yard)
{
    return yard * 3 * 12 * 2.54 / 100;
}
int countVowels(string str, int index, int counter)
{
    if(index == str.length())
    {
        return counter;
    }

    for(const auto vowel : vowels)
    {
        if(vowel == str[index])
        {
            counter++;
            break;
        }
        else
        {
            continue;
        }
    }

    return countVowels(str, index + 1, counter);
}
int findIntersection(string surname, float length, float letter_length)
{
    int counter = 0;
    double middle = (length - 3) / 2;
    int index = int(middle / letter_length) % surname.length();
    double temp = letter_length * int(round(middle / letter_length));
    
    while (temp < middle + 3);
    {
        temp += letter_length;
        counter++;
    } 
    

    return counter;
}
