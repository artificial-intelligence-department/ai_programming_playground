#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Stadium {
    string name;
    string address;
    int capacity;
    string sports; 
};

void toRead(string path){
    ifstream file;
    file.open(path);
    if (path!="structure.txt"){
        cerr << "Critical error" << endl;
        return;
    }

    string content;
    while (getline(file, content)){
        cout << content << endl;
    }
    file.close();
}

void toWrite(string path, Stadium stadiums[3]){
    ofstream file;
    file.open(path);
    if (path!="structure.txt"){
        cerr << "Critical error" << endl;
        return;
    }
    for (int i = 0; i < 3; i++){
        file << stadiums[i].name << "; ";
        file << stadiums[i].address << "; ";
        file << stadiums[i].capacity << "; ";
        file << stadiums[i].sports << "\n";
    }
    file.close();
}

void deleteElement(string path, string nameToDelete, Stadium stadiums[3]){
    ofstream file;
    file.open(path);
    if (path!="structure.txt"){
        cerr << "Critical error" << endl;
        return;
    }
    for (int i = 0; i < 3; i++){
        if(stadiums[i].name!=nameToDelete){
            file << stadiums[i].name << "; ";
            file << stadiums[i].address << "; ";
            file << stadiums[i].capacity << "; ";
            file << stadiums[i].sports << "\n";
        }
    }
    for (int i = 0; i < 3; i++){
        if(stadiums[i].name==nameToDelete){
            for(int j = i; j < 3; j++){
                stadiums[j-1]=stadiums[j];
            }
        }    
    }
    file.close();
    
    toRead(path);
}

void addElements(string path, int twoElements, Stadium stadiums[3], Stadium elementsToAdd[2]){
    ofstream file;
    file.open(path);
    if (path!="structure.txt"){
        cerr << "Critical error" << endl;
        return;
    }
    for (int i = 0; i < 2; i++){
        if((i+1)!=twoElements){
            file << stadiums[i].name << "; ";
            file << stadiums[i].address << "; ";
            file << stadiums[i].capacity << "; ";
            file << stadiums[i].sports << "\n";
        }
        else{
            file << stadiums[i].name << "; ";
            file << stadiums[i].address << "; ";
            file << stadiums[i].capacity << "; ";
            file << stadiums[i].sports << "\n";
            for (int j = 0; j < 2; j++){
                file << elementsToAdd[i].name << "; ";
                file << elementsToAdd[i].address << "; ";
                file << elementsToAdd[i].capacity << "; ";
                file << elementsToAdd[i].sports << "\n";
            }
        }
    }
    file.close();

    toRead(path);
}

int main(){
    Stadium stadiums[3] = {
        {"Stadium1", "Yanukovich 25", 30000, "Football"},
        {"Stadium2", "Lugova 24", 40000, "Soccer"},
        {"Stadium3", "Lukasha 5", 25000, "Hockey"}
    };
    Stadium elementsToAdd[2]{
        {"StadiumNew1", "Bandera 19", 150000, "Basketball"},
        {"StadiumNew2", "Khersonska 2", 1000, "Cybersport"}
    };
    string path = "structure.txt";
    toWrite(path, stadiums);
    toRead(path);
    cout<<endl;
    string deleteName;
    cin>>deleteName;
    cout<<endl;
    deleteElement(path, deleteName, stadiums);
    cout<<endl;
    int twoElements;
    cin>>twoElements;
    cout<<endl;
    addElements(path, twoElements, stadiums, elementsToAdd);
}