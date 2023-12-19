#include <iostream>
#include <string>
using namespace std;

double word(string word){
    double k=0;
    for(int i=0; i<word.length(); i++){//Використання циклу for
        char a=tolower(word[i]);
        if(a=='y'||a=='o'||a=='e'||a=='u'||a=='a'||a=='i'){//Використання оператора розгалуженння
            k++;
    }
}
    k=k*0.8*word.length();
    return k;
}

void central(string surname, bool fromLeftToRight) {
    int length = surname.length();
    int start = (length - 3) / 2;
    if (fromLeftToRight)
        cout << "Lefto to right: ";
    else
        cout << "Right to left: ";

    if (fromLeftToRight) {
        for (int i = start; i < start + 3; i++) {
            cout << surname[i];
        }
    } else {
        for (int i = start + 2; i >= start; i--) {
            cout << surname[i];
        }
    }
    cout << endl;
}

int main() {
    string surname;
    double Length, letterW;
    cout << "Enter your surname:  ";
    cin >> surname;

    Length = 120.0;

    letterW = word(surname);
    double minLength = Length * 0.9144; 
    cout << "Minimal length:   " << minLength << endl;

    central(surname, true); 
    central(surname, false); 

    return 0;
}