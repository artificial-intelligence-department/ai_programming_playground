#include<iostream>
using namespace std;

int main(){
    int Hitpoints, Mana;
    int spell;
    int skillofcharacter[2][3]={0};

cout << "Enter hitpoints:\t";
cin >> Hitpoints;

cout << "Enter Mana:\t";
cin >> Mana;

cout << "Enter skills of character(fireball(1), avalanche(2), nuclear bomb(3))\t(no more than 3):\n";
cout << "\t\tHitpoints \t Mana\n";

for(int line=0; line<3; line++)
{
    cout << "Skill " << line+1 <<" :\t ";
    for(int row=0; row<2; row++){
        cin >> skillofcharacter[line][row];
    }
}

cout << "\n\t\tBattle starts!\v\n";
for(int i=0;i<3; i++)
{
    for(int j=0; j<2; j++){
        cout << skillofcharacter[i][j] << "\t";
    }
    cout << "|\n";
}

for(int count1=1; count1<=3; count1++)
{
cout << "Enter number of spell: ";
cin >> spell;
if(spell==1){
    Hitpoints-=skillofcharacter[0][0]; Mana-=skillofcharacter[0][1];
    }
if(spell==2){
    Hitpoints-=skillofcharacter[1][0]; Mana-=skillofcharacter[1][1];
}

if(spell==3){
    Hitpoints-=skillofcharacter[2][0]; Mana-=skillofcharacter[2][1];
    }
cout << "(Remaining stats) " << "Hitpoints:" << Hitpoints << " Mana: " << Mana;
cout << "\n";
}
if(Mana && Hitpoints > 0){
    cout << "You win!! Best wishes!";
}
else{
    cout << "You lose this game! Game over!";
}
    return 0;
}