#include <iostream>
using namespace std;

int countVowels(string str) 
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) 
    {
        char ch = std::tolower(str[i]);  // Convert to lowercase for case-insensitivity
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') 
        {
            count++;
        }
    }

    return count;
}

int main() 
{
    const double lenghtPole = 109.728;

    string myLastName;
    cin>>myLastName;
    const int vowelsCount = countVowels(myLastName);
    const double widthPerVowel = 0.8;

    int nameLength = 0;
    for (int i = 0; myLastName[i] != '\0'; ++i) {
        nameLength++;
    }

    double letterWidth = vowelsCount * widthPerVowel;
    double bannerLength = nameLength * (letterWidth);



    std::cout << "lenght of banner : " << bannerLength << " m" << std::endl;

    return 0;
}