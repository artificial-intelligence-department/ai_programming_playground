#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Car {
    string brand;
    int year;
    int price;
    string colors; 
};

void toRead(string path){
    ifstream file;
    file.open(path);
    if (path!="structureCar.txt"){
        cerr << "Critical error" << endl;
        return;
    }

    string content;
    while (getline(file, content)){
        cout << content << endl;
    }
    file.close();
}

void toWrite(string path, Car cars[3]){
    ofstream file;
    file.open(path);
    if (path!="structureCar.txt"){
        cerr << "Critical error" << endl;
        return;
    }
    for (int i = 0; i < 3; i++){
        file << cars[i].brand << "; ";
        file << cars[i].year << "; ";
        file << cars[i].price << "; ";
        file << cars[i].colors << "\n";
    }
    file.close();
}

void deleteElement(string path, int apryear, Car cars[3]){
    ofstream file;
    file.open(path);
    if (path!="structureCar.txt"){
        cerr << "Critical error" << endl;
        return;
    }
    for (int i = 0; i < 3; i++){
        if(cars[i].year>=apryear){
            file << cars[i].brand << "; ";
            file << cars[i].year << "; ";
            file << cars[i].price << "; ";
            file << cars[i].colors << "\n";
        }
    }

    file.close();
    
    toRead(path);
}

void addElements(string path, Car cars[3], Car elementsToAdd[1], int apryear){
    ofstream file;
    file.open(path,ofstream::app);
    if (path!="structureCar.txt"){
        cerr << "Critical error" << endl;
        return;
    }
    file << elementsToAdd[0].brand << "; ";
    file << elementsToAdd[0].year << "; ";
    file << elementsToAdd[0].price << "; ";
    file << elementsToAdd[0].colors << "\n";
    
    file.close();

    toRead(path);
}

int main(){
    Car cars[3] = {
        {"Toyota", 2022, 25000, "Red"},
        {"Honda", 2021, 22000, "White"},
        {"Ford", 2023, 27000, "Green"}
    };
    Car elementsToAdd[1]{
        {"Toyota", 2006, 15000, "Silver"}
    };
    string path = "structureCar.txt";
    toWrite(path, cars);
    toRead(path);
    cout<<endl;
    int apryear;
    cin>>apryear;
    cout<<endl;
    deleteElement(path, apryear, cars);
    cout<<endl;
    addElements(path, cars, elementsToAdd, apryear);
}