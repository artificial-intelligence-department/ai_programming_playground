#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string results;
    cin >> results;

    int kolya_score = 0, vasya_score = 0;
    int kolya_wins = 0, vasya_wins = 0;

    for (char result : results) 
    {
        if (result == 'K') 
        {
            kolya_score++;
        } 
        else 
        {
            vasya_score++;
        }

        if ((kolya_score >= 11 || vasya_score >= 11) && abs(kolya_score - vasya_score) >= 2) 
        {
            if (kolya_score > vasya_score) 
            {
                kolya_wins++;
            } 
            else 
            {
                vasya_wins++;
            }
            
            kolya_score = 0;
            vasya_score = 0;
        }
    }

    cout << kolya_wins << ":" << vasya_wins << endl;

    if (kolya_score > 0 || vasya_score > 0) 
    {
        cout << kolya_score << ":" << vasya_score << endl;
    }

    return 0;
}
