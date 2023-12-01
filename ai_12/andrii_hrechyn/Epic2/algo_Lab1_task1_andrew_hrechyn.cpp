#include<iostream>
using namespace std;

int main(){
    int Hitpoint, Mana;
    int spell;
    int skills[2][3]={0};

cout << "Enter hitpoints:\t";
cin >> Hitpoint;

cout << "Enter Mana:\t";
cin >> Mana;

cout << "Enter skills of character(fireball(1), avalanche(2), nuclear bomb(3))\t(no more than 3):\n";
cout << "\t\tHitpoints \t Mana\n";

for(int line=0; line<3; line++)
{
    cout << "Skill " << line+1 <<" :\t ";
    for(int row=0; row<2; row++){
        cin >> skills[line][row];
    }
}

cout << "\n\t\tBattle starts!\v\n";
for(int i=0;i<3; i++)
{
    for(int j=0; j<2; j++){
        cout << skills[i][j] << "\t";
    }
    cout << "|\n";
}

for(int count=1; count<=3; count++)
{
cout << "Enter spell: ";
cin >> spell;
if(spell==1){
    Hitpoint-=skills[0][0]; Mana-=skills[0][1];
    }
if(spell==2){
    Hitpoint-=skills[1][0]; Mana-=skills[1][1];
}

if(spell==3){
    Hitpoint-=skills[2][0]; Mana-=skills[2][1];
    }
cout << "(Remaining stats) " << "Hitpoints:" << Hitpoint << " Mana: " << Mana;
cout << "\n";
}
if(Mana && Hitpoint > 0){
    cout << "YOU WIN! FINISH HIM!!!";
}
else{
    cout << "STUPID NOOB! HOW COULD YOU LOSE!? LOL XXXXD L+Ratio+SkillIssue";
}
    return 0;
}