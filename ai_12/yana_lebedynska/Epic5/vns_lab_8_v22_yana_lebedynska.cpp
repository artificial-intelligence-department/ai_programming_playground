#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct OwnerOfCar
{
    string lastName;
    string firstName;
    string middleName;
    string numOfCar;
    long numOfTechPassport;
    int numOfRegistraionOffice;
};

void printInformation(vector<OwnerOfCar>& owner)
{
    cout << endl;

    for(auto& OWNER : owner)
    {
        cout << "The last name: " << OWNER.lastName << endl;
        cout << "The first name: " << OWNER.firstName << endl;
        cout << "The middle name: " << OWNER.middleName << endl;
        cout << "The car number: " << OWNER.numOfCar << endl;
        cout << "The technical passpor number: " << OWNER.numOfTechPassport << endl;
        cout << "The num of registration office: " << OWNER.numOfRegistraionOffice << endl;
        cout << "---------------------------------------------------" << endl;
    }   
}

void deleteFromOwner(vector<OwnerOfCar>& owner, string& numberOfCarToDelete)
{
    cout << endl;

    for(auto i = owner.begin(); i < owner.end(); i++)
    {
        if((*i).numOfCar == numberOfCarToDelete)
        {
            i = owner.erase(i); //тепер i вказує на наступний елемент після видаленого
            break;
        }
    }
}

void insertOwners(vector<OwnerOfCar>& owner, string& LASTname, OwnerOfCar&  owner1, OwnerOfCar& owner2)
{
    cout << endl;

    for(auto i = owner.begin(); i < owner.end(); i++)
    {
        if((*i).lastName == LASTname)
        {
            i = owner.insert(i, owner1);
            i = owner.insert(i, owner2);
            break;
        }
    }
}

int main()
{
    vector<OwnerOfCar> carOwners;

    ifstream file("owners.txt");

    if(file.is_open())
    {
        OwnerOfCar tempOwner;
        while(file >> tempOwner.lastName >> tempOwner.firstName >> tempOwner.middleName >> tempOwner.numOfCar >> tempOwner.numOfTechPassport >> tempOwner.numOfRegistraionOffice)
        {
            carOwners.push_back(tempOwner);
        }

        file.close();
    }
    else
    {
        cout << "File coldn't be opened. Creating new file.";
        cout << endl;
    }

    OwnerOfCar owner1 = {"Lebedynska", "Yana", "Olexandrivna", "BC4326", 232535577, 2};
    OwnerOfCar owner2 = {"Brychko", "Maria", "Ihorivna", "BC7455", 753855112, 23};

    carOwners.push_back(owner1);
    carOwners.push_back(owner2);

    ofstream file_output("OWNERS.txt");
    if(file_output.is_open())
    {
        for(auto& Owners : carOwners)
        {
            file_output << Owners.lastName << " " << Owners.firstName << " " << Owners.middleName << " " << Owners.numOfCar << " " << Owners.numOfTechPassport << " " << Owners.numOfRegistraionOffice << endl;
        }

        file_output.close();
    }

    cout << "The list before editing" << endl;
    printInformation(carOwners);

    string CarNumToDelete;
    cout << "Enter car number to delete: ";
    cin >> CarNumToDelete;
    deleteFromOwner(carOwners, CarNumToDelete);

    cout << "The list after deleting" << endl;
    printInformation(carOwners);

    OwnerOfCar newOwner1 = {"Borsch", "Anastasia", "Ihorivna", "BC1199", 243647999, 5};
    OwnerOfCar newOwner2 = {"Yankiv", "Olesia", "Semenivna", "BC4312", 655578000, 21};

    string lastNameToInsertBefore;
    cout << "Enter the last name from list to insert before two new owners: ";
    cin.ignore();
    getline(cin, lastNameToInsertBefore);
    insertOwners(carOwners, lastNameToInsertBefore, newOwner1, newOwner2);
    
    cout << "The list after adding new owners: ";
    printInformation(carOwners);

    return 0;
}
