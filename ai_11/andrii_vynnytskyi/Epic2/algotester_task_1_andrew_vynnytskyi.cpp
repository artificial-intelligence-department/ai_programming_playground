#include<iostream>
using namespace std;


int main()
{
    long long int hitpoints , mana, buff_hitpoints, buff_mana;
    string vic = "YES";

    cin>> hitpoints >> mana;
    for (int i = 0; i < 3; i++){

        cin>> buff_hitpoints>> buff_mana;
        if (buff_mana != 0 && buff_hitpoints != 0 || vic == "NO"){
            vic = "NO";
        }

        hitpoints -= buff_hitpoints;
        mana -= buff_mana;

    }
    if (hitpoints > 0 && mana > 0 && vic == "YES")
    {
        cout<< vic;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}