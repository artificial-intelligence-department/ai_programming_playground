#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    cin.ignore();

    int counter = 0;
    for (int i = 0; i < N; i++){
        string linewords;
        getline(cin, linewords);

        for (int  j = 0; j < linewords.size(); j++){
            char symbol = linewords[j];

            if(symbol == '#' && linewords[j+1] != '#'){
                counter++;
            }
        }
    }

    cout << counter;
    return 0;
}



