#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct Info {
    char symbol;
    int position;
};

    int main(){
        string lastName = "Bachyk";

        int MinFieldLen;
        float LetWidth;
        double minLength;

        const double inchTocm = 2.54;
        
        // Обчислення голосних
        string golosni = "aeiouyAEIOUY";
        int golosniCount = 0;

        for(char letter : lastName){
            size_t found = golosni.find(letter);
            if(found != -1){
                golosniCount++;
            }
        }
        // Розрахунок інтервалів
        LetWidth = golosniCount * 0,8;
        // Розрахунок найменшої довжини поля
        minLength = ceil((lastName.length() * LetWidth / 12) * 3);

        cout << "Min length of pitch with banner" << LetWidth << endl;

        // Обчислення симовлів які будуть у 3 центральних метрах
        int centralChars = int(3 / inchTocm * 100);
        int indxLeft = (lastName.length() - centralChars / 2);
        int indxRight = (lastName.length() - centralChars + indxLeft);

        Info symbolsLeft[centralChars];
        Info symbolsRight[centralChars];

        for(int i = 0; i < centralChars; ++i){
            symbolsLeft[i].symbol = lastName[indxLeft + i];
            symbolsRight[i].symbol = lastName[indxRight - i - 1];
            symbolsLeft[i].position = indxLeft + i;
            symbolsRight[i].position = indxRight - i - 1;
        }
        
        cout << "Symbols in central 3m(from left to right): " << endl;
        for (int i = 0;i < centralChars;++i){
            cout << symbolsLeft[i].symbol << endl;
        }

        cout << "Symbols in central 3m(from right to left): " << endl;
        for (int i = 0;i < centralChars;++i){
            cout << symbolsRight[i].symbol << endl;
        }
    ofstream outFile("banner.txt");
    outFile << "Banner: " << lastName << endl;
    outFile.close();

    return 0;
}

