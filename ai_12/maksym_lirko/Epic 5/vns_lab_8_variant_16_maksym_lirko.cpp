#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct Car_Owner {
    string SurName;
    string Name;
    string MiddleName;
    string CarNumber;
    string Phone;
    string CarPassport;
};

void toFile(const vector<Car_Owner>& owners) {
    ofstream File("car_owners.bin", ios::binary);

    if (!File.is_open()) {
        cout << "ERROR OPENING FILE!" << endl;
        return;
    }

    for (const Car_Owner& owner : owners) {
        File.write(reinterpret_cast<const char*>(&owner), sizeof(owner));
    }

    File.close();
    cout << "Data wrote to file successfully!" << endl;
}

void Output(const Car_Owner& owner) {
    cout << "Surname: " << owner.SurName << endl;
    cout << "Name: " << owner.Name << endl;
    cout << "Middle name: " << owner.MiddleName << endl;
    cout << "Car number: " << owner.CarNumber << endl;
    cout << "Phone: " << owner.Phone << endl;
    cout << "Car passport: " << owner.CarPassport << endl;
    cout << endl;
}

bool addNewOwner(vector<Car_Owner>& own) {
    Car_Owner newOwner;

    cout << "Enter the information about a car owner you want to add:\n";
    cout << "Surname: ";
    getline(cin, newOwner.SurName);

    cout << "Name: ";
    getline(cin, newOwner.Name);

    cout << "Middle name: ";
    getline(cin, newOwner.MiddleName);

    cout << "Car number: ";
    getline(cin, newOwner.CarNumber);

    cout << "Phone: ";
    getline(cin, newOwner.Phone);

    cout << "Car passport: ";
    getline(cin, newOwner.CarPassport);

    own.push_back(newOwner);

    return true;
}

int main() {
    string choice;
    vector<Car_Owner> own = {
        {"Vasyan", "Vasyl" , "Vasulovuch" , "VS1234" , "0988087773" , "tp123456" },
        {"Black" , "Vlad" , "Petrovuch" , "VD1245" , "0988881323" , "pd133456" },
        {"Kurnuk" , "Ivan" , "Volodumurovuch" , "VP7518" , "5091359113" , "hd198519"},
    };
    
    cout<<endl;
    for (int i = 0; i < own.size(); i++)
    {
        Output(own[i]);
        }

    cout << "Enter a car number which you want to delete: " << endl;
    getline(cin, choice);

    cout<<endl<<endl;

    bool finder;


    int i2 = 0;
    while (i2 < own.size()) 
    {
        if(own[i2].CarNumber == choice)
        {
            own.erase(own.begin() + i2);
            finder = true;
            break;
        }
        i2++;
    }
    cout<<"Car number successfully deleted! "<<endl;

    if (finder!= true) {
        cout << "You entered a wrong car number!" << endl;
        return 0;
    }

    else if(finder == true){
     for (int i = 0; i < own.size(); i++) {
            Output(own[i]);
        }
    }

    addNewOwner(own);

    cout<<endl;
    for (int i = 0; i < own.size(); i++)
    {
        Output(own[i]);
    }

    toFile(own);
    
    return 0;
}