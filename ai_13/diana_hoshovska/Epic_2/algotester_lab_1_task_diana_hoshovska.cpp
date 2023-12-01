#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int H, M, hi, mi;
    //cout << "Enter the number of hitpoints: ";
    cin >> H;
    while (H<1 || H>pow(10, 12)){
        //cout << "Wrong data, try again: ";
        cin >> H;
    }

    //cout << "Enter the number of mana: ";
    cin >> M;
    while (M<1 || M>pow(10,12)){
        //cout << "Wrong data, try again: ";
        cin >> M; 
    }

    //cout << "Casting a spell three times\n";
    for(int i = 0; i < 3; i++)
        {
            //cout << "Enter hitpoints: ";
            cin >> hi;
            while (hi<0 || hi >pow(10,12)){
                //cout << "Wrong data, try again: ";
                cin >> hi; 
            }

            //cout << "Enter mana: ";
            cin >> mi;
            while (mi<0 || mi >pow(10,12)){
                //cout << "Wrong data, try again: ";
                cin >> mi; 
            }
            H-=hi;
            M-=mi;

            if (hi>0 && mi>0){
                break;
            }
        }
    if (hi>0 && mi>0){
        cout << "NO";
    }
    else if (H>0 && M>0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}