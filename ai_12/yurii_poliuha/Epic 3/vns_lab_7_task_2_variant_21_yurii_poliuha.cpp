#include <iostream> 
#include <string>
#include <cctype>
using namespace std;

void Show(int array[], int size){
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) count++;
        else continue;
    }
    cout << "Amount of negative elements of the array is: " << count << endl;
}

void Show(string str){
    int Size = str.size();
    str += ' ';
    int count = 0;
    char first_letter = '\0';
    bool StartOfTheWord = false;
    for (int i = 0; i < Size; i++) {
        str[i] = tolower(str[i]);
        if (str[i] != ' ' && str[i] != ',') {
            if (StartOfTheWord == false) {
                first_letter = str[i];
                StartOfTheWord = true;
            }
            else continue;
        }
        else if (str[i] == ' ' || str[i] == ',') {
            if (StartOfTheWord == true) {
                StartOfTheWord = false;
                if (first_letter == str[i - 1]) count++;
            }
        }
    }
    cout << "Amount of words starting and ending with the same letter is: " << count << endl;
}

int main(){
    int size;
    cout << "Enter length of array: ";
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << "   ";
    }
    cout << endl;
    string sentence = "Hello World, my name is Yura assssa, Geggedgahdg, vevev usdhau ";

    cout << endl;
    Show(array, size);
    cout << endl;
    Show(sentence);

    return 0;
}