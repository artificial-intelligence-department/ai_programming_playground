#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Stadium{
    char name[30];
    char address[30];
    int capacity;
    char sportstypes[40];
};

void formFile(Stadium& stadium);
void printFile();
void deleteEl(const char* name);
void addEl(Stadium& stadium, int number);

int main(){
    Stadium Donbas;
    Donbas = {"Donbas Arena", "Donetsk", 52187, "football"};
    formFile(Donbas);
    Stadium Lviv;
    Lviv = {"Arena Lviv", "Lviv", 30000, "karting, football"};
    formFile(Lviv);
    Stadium Olympic;
    Olympic = {"Olympic", "Kyiv", 24255, "football, athletics"};
    formFile(Olympic);
    printFile();

    cout << "enter the name of stadium, ehich you wnat to delete" << endl;
    char name_to_del[30];
    //cin.ignore();
    cin.getline(name_to_del, sizeof(name_to_del));
    deleteEl(name_to_del);
    cout << "stadiums after deleting" << endl;
    printFile();

    Stadium Shakhtar;
    Shakhtar = {"Shakhtar Chervonograd", "Chervonograd", 2425, "football, athletics, tennis"};
    addEl(Shakhtar, 1);
    printFile();

    Stadium newStad;
    cout << "enter the info about new stadium" << endl;
    cin.getline(newStad.name, sizeof(newStad.name));
    cin.getline(newStad.address, sizeof(newStad.address));
    cin >> newStad.capacity;
    cin.ignore();
    cin.getline(newStad.sportstypes, sizeof(newStad.sportstypes));
    cout << "enter the after position" << endl;
    int pos;
    cin >> pos;
    addEl(newStad, pos);
    printFile();

    fstream file("stadiums.dat", fstream::out | fstream::trunc | fstream::binary);
    file.close();
    return 0;
}

void formFile(Stadium& stadium){
    fstream oFile("stadiums.dat", fstream::out | fstream::app | fstream::binary);

    if(oFile.is_open()){
        oFile.write((char*)&stadium, sizeof(Stadium));
        oFile.close();
    }else{
        cout << "error opening file" << endl;
        return;
    }
}
void printFile(){
    fstream iFile("stadiums.dat", fstream::in | fstream::binary);
    if(iFile.is_open()){
        Stadium stadium;
        cout << "   Stadiums" << endl;
        while(iFile.read((char*)&stadium, sizeof(Stadium))){
            cout << "Name: " << stadium.name << endl;
            cout << "Address: " << stadium.address << endl;
            cout << "Capacity: " << stadium.capacity << endl;
            cout << "Sports types: " << stadium.sportstypes << endl;
            cout << "**********" << endl;
        }
        iFile.close();
    }else{
        cout << "error opening file" << endl;
        return;
    }
}
void deleteEl(const char* name){
    fstream iFile("stadiums.dat", fstream::binary | fstream::in);
    fstream oFile("out.dat", fstream::binary | fstream::out);

    if(iFile.is_open() && oFile.is_open()){
        Stadium stadium;
        bool founded = false;
        while (iFile.read((char*)&stadium, sizeof(Stadium))){
            if(strcmp(stadium.name, name)!=0){
                oFile.write((char*)&stadium, sizeof(Stadium));
            } else{
                founded = true;
            }
        }
        iFile.close();
        oFile.close();
        if(founded){
            fstream iFile("stadiums.dat", fstream::binary | fstream::out);
            fstream oFile("out.dat", fstream::binary | fstream::in);
            if(oFile.is_open() && iFile.is_open()){
                while(oFile.read((char*)&stadium, sizeof(Stadium))){
                    iFile.write((char*)&stadium, sizeof(Stadium));
                }
                oFile.close();
                iFile.close();
            }else{
                cout << "error2 opening file" << endl;
                return;
            }
        }else{
            cout << "there is no stadiums with this name" << endl;
            return;
        }
    }else{
        cout << "error opening files" << endl;
        return;
    }
    return;
}
void addEl(Stadium& stadium, int number){
    fstream iFile("stadiums.dat", fstream::binary | fstream::in);
    fstream oFile("out.dat", fstream::binary | fstream::out);

    if(iFile.is_open() && oFile.is_open()){
        int current_number = 0;
        Stadium stad;
        while(iFile.read((char*)&stad, sizeof(Stadium))){
            if(current_number==number){
                oFile.write((char*)&stadium, sizeof(Stadium));
            }
            oFile.write((char*)&stad, sizeof(Stadium));
            current_number++;
        }
        if(current_number==number){
            oFile.write((char*)&stadium, sizeof(Stadium));
        }
        iFile.close();
        oFile.close();
        fstream iFile("stadiums.dat", fstream::binary | fstream::out);
        fstream oFile("out.dat", fstream::binary | fstream::in);
        if(oFile.is_open() && iFile.is_open()){
            while(oFile.read((char*)&stadium, sizeof(Stadium))){
                iFile.write((char*)&stadium, sizeof(Stadium));
            }
            oFile.close();
            iFile.close();
        }else{
            cout << "error2 opening file" << endl;
            return;
        }
    }else{
        cout << "error opening files" << endl;
        return;
    }
}