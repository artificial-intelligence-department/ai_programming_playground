#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int c , counter = 0 , len = 0;
    string storyupd;


    cin >> c;
    char letter = '#';

    vector<string> story(c);

    for (int i = 0; i < c; i++){
        cin.ignore();
        getline(cin , story[i]);
    }
        for (int i = 0; i < story.size(); i++){
            for (int j = 0; j < story[i].size(); j++){
                if (story[i][j] == letter && story[i][j + 1] != letter )    
                    counter++;
            }
        }


    cout << counter;

}
