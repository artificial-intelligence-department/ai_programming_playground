#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

bool Vowel(char c){
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');//check if the letter is a vowel
}

int countVowels(string surname , int count , int i = 0){//count vowels in surname
    if(i >= surname.length()){
        return count;
    }

    if(Vowel(surname[i])){
        count++;
    }


    return countVowels(surname, count, i + 1);//recursion

}

void AddToFile(int count){//add coint of vowels to a file
    ofstream file;
    file.open("KR2.txt");
    file << count;
    file.close();
}

void ReadFromFile(){//read amount of vowels from the file
    ifstream file;
    file.open("KR2.txt");
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

float WidthOfLetter(int count){//width of letter
    return 0.8 * count;
}

double ft_to_meter(int ft){//convert feet to meters
    return ft * 0.3048;
}

void CentralChars(float WidthOfLetter, double meters , string surname){//print central chars
    float centralLenght = meters;

    float centralStart = (centralLenght - 3.0) / 2.0;
    float centralEnd = centralStart + 3.0;

    for(int i = 0; i < meters; i++){
        float currentPos = i * WidthOfLetter;
        if(currentPos >= centralStart && currentPos <= centralEnd){
            int c = i % surname.length();
            cout << surname[c];
        }
    }
}

string reverse(string surname){//reverse surname
    reverse(surname.begin(), surname.end());
    return surname;

}

void FromLeftToright(float WidthOfLetter, double meters , string reverse_surname){//print central chars from left to right
    float centralLenght = 3.0;//variable with float accuracy

    float centralStart = (centralLenght - WidthOfLetter) / 2.0;
    float centralEnd = centralStart + WidthOfLetter;

    for(int i = reverse_surname.length() - 1; i >= 0; i--){
        float currentPos = (reverse_surname.length() - i - 1) * WidthOfLetter;
        if(currentPos >= centralStart && currentPos <= centralEnd){
            int c = i % reverse_surname.length();
            cout << reverse_surname[c];
        }
    }
}



int main(){
    const int width_of_field = 100;//int const
    const int length_of_field = 130;

    string surname;
    cout << "Enter your surname: ";
    cin >> surname;

    string reverse_surname = reverse(surname);

    AddToFile(countVowels(surname, 0));

    ReadFromFile();

    double meters = ft_to_meter(length_of_field);//variable with double accuracy

    cout << "From left to right: " << endl;
    CentralChars(WidthOfLetter(countVowels(surname, 0)), meters, surname);//overload function

    cout << endl << "From right to left: " << endl;
    CentralChars(WidthOfLetter(countVowels(surname, 0)), meters, reverse_surname);//overload function



    return 0;
}