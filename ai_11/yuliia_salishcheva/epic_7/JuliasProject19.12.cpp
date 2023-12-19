#include <iostream>
#include <string>

using namespace std;

int main() {
    // ¬вед≥ть ваше пр≥звище
    string surname = "Salishcheva";
    const double hundredcores = 91.44;
    int footballFieldLengthYards = 100;//за вар≥антом
    //  ≥льк≥сть голосних букв у пр≥звищ≥
    int vowels = 0;
    for (char c : surname) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
            vowels++;
    }

    // Ўирина букви разом з ≥нтервалом
    double letterWidth = vowels * 0.8;  // довжина слова у метрах
    double letterWidthCore = vowels * 0.8 * 3.2808; // довжина слова у фунтах 
    double letterWidthcoreYards = vowels * 0.8 * 3.2808 * 3;// довжина слова у €драх
    cout << "The shortest length of the banner: " << letterWidthcoreYards << endl;
    cout << "When writing the surname from the left edge of the field Ч> to the right: \n";
    while(footballFieldLengthYards > 0)
    {
        if (footballFieldLengthYards > letterWidthcoreYards)
        {
            for (int i = 0; i < surname.size(); i++)
            {
                cout << surname[i];
            }
        }
        else
        {
            for (int i = 0; i < footballFieldLengthYards; i++)
            {
                cout << surname[i];
            }
        }
        footballFieldLengthYards -= (int)letterWidthcoreYards;
    }
    footballFieldLengthYards = 100;
    cout << endl << endl;
    string reversedSurname;
    reversedSurname.reserve(surname.size());
    for (int i = surname.size() - 1; i >= 0; i--) {
        reversedSurname.push_back(surname[i]);
    }
    cout << "When writing the surname from the right edge of the field < Ч to the left: \n";
  /*  while (footballFieldLengthYards > 0)
    {
        if (footballFieldLengthYards > letterWidthcoreYards)
        {
            for (int i = surname.size() - 1; i >= 0; i--)
            {
                cout << surname[i];
            }
        }
        else
        {
            for (int i = footballFieldLengthYards - 1; i >= 0; i--)
            {
                cout << surname[i];
            }
        }
        footballFieldLengthYards -= (int)letterWidthcoreYards;
    }*/

    while (footballFieldLengthYards > 0)
    {
        if (footballFieldLengthYards > letterWidthcoreYards)
        {
            for (int i = 0; i < reversedSurname.size(); i++)
            {
                cout << reversedSurname[i];
            }
        }
        else
        {
            for (int i = 0; i < footballFieldLengthYards; i++)
            {
                cout << reversedSurname[i];
            }
        }
        footballFieldLengthYards -= (int)letterWidthcoreYards;
    }
    footballFieldLengthYards = 100;
    cout << endl << endl;
    cout << endl << endl;
}

