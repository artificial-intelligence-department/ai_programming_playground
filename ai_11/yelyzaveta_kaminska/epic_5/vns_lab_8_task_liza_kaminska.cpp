#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Buyer{
    string personal_information;
    string home_adress;
    string home_number;
    string credit_card;
};
int write(Buyer warr[]){
    ofstream wf("user.bin", ios::out | ios::binary);
    if(!wf){
        cout <<"Cannot open the file.";
        return 1;
    }
    for (int i=0; i<4; i++)
        wf.write((char *) &warr[i], sizeof(Buyer));
    wf.close();
    if(!wf.good()) {
        cout << "Error occurred at writing time!" << endl;
        return 1;
    }
    return 0;
}
int read(Buyer rarr[]){
   ifstream rf("user.bin", ios::out | ios::binary);
   if(!rf){
        cout <<"Cannot open the file.";  
        return 1;
    }
    for(int i = 0; i < 4; i++)
        rf.read((char *) &rarr[i], sizeof(Buyer));
    rf.close();
    if(!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return 1;
    }
    return 0;
}
int main() {
    const int SIZE = 4;
    Buyer warr[SIZE];
    warr[0].personal_information = "Kaminska Liza";
    warr[0].home_adress = "Pr.Chervonoi Kalyny 58";
    warr[0].home_number = "063-146-43-02";
    warr[0].credit_card = "123456789";
    warr[1].personal_information = "Spodaryk Sofiia";
    warr[1].home_adress = "Pidgolosko str.";
    warr[1].home_number = "098-678-56-45";
    warr[1].credit_card = "987654321";
    warr[2].personal_information = "Bokalo Yaryna";
    warr[2].home_adress = "Trylovskogo str.";
    warr[2].home_number = "076-675-87-34";
    warr[2].credit_card = "123459876";
    warr[3].personal_information = "Malanchuk Olesia";
    warr[3].home_adress = "Okruzna str.";
    warr[3].home_number = "054-567-57-43";
    warr[3].credit_card = "987612345";
    write(warr);
    Buyer rarr[SIZE];
    read(rarr);

    cout << "Buyer details:" << endl;
    for(int i=0; i < SIZE; i++) {
        cout << "Personal information:" << rarr[i].personal_information << endl;
        cout << "Home adress:" << rarr[i].home_adress << endl;
        cout << "Home number:" << rarr[i].home_number << endl;
        cout << "Credit card:" << rarr[i].credit_card << endl;
        cout << endl;
    }
    Buyer rarr2[4];
    rarr2[0] = rarr[3];
    write(rarr2);
    read(rarr2); 
    cout << "New buyer details:" << endl;
    for(int i =0; i<4; i++){
        cout << "Personal information:" << rarr2[i].personal_information << endl;
        cout << "Home adress:" << rarr2[i].home_adress << endl;
        cout << "Home number:" << rarr2[i].home_number << endl;
        cout << "Credit card:" << rarr2[i].credit_card << endl;
        cout << endl;
    }

    rarr2[1] = rarr[0];
    rarr2[2] = rarr[1];
    rarr2[3] = rarr[2];
    write(rarr2);
    read(rarr2);
    for(int i=0; i < 4; i++) {
        cout << "Personal information:" << rarr2[i].personal_information << endl;
        cout << "Home adress:" << rarr2[i].home_adress << endl;
        cout << "Home number:" << rarr2[i].home_number << endl;
        cout << "Credit card:" << rarr2[i].credit_card << endl;
        cout << endl; 
    }
    return 0;
}