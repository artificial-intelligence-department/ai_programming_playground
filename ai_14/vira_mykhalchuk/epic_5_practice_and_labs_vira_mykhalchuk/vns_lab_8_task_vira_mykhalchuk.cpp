#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxOwners = 100;

struct OwnerOfCar
{
    string lastName;
    string firstName;
    string fathersName;
    string plateOfCar;
    long numberOfTechPassport;
    int numberOfRegistraionOffice;
};

void printInformation(OwnerOfCar owners[], int size)
{
    cout << '\n';

    for (int i = 0; i < size; ++i)
    {
        cout << "The last name: " << owners[i].lastName << '\n';
        cout << "The first name: " << owners[i].firstName << '\n';
        cout << "The middle name: " << owners[i].fathersName << '\n';
        cout << "The car plate: " << owners[i].plateOfCar << '\n';
        cout << "The technical passport number: " << owners[i].numberOfTechPassport << '\n';
        cout << "The number of registration office: " << owners[i].numberOfRegistraionOffice << '\n';
        cout << "\n";
    }
}

void deleteOwner(OwnerOfCar owners[], int& size, const string& plateOfCarToDelete)
{
    cout << '\n';

    for (int i = 0; i < size; ++i)
    {
        if (owners[i].plateOfCar == plateOfCarToDelete)
        {
            for (int j = i; j < size - 1; ++j)
            {
                owners[j] = owners[j + 1];
            }
            --size;
            break;
        }
    }
}

void addOwners(OwnerOfCar owners[], int& size, const string& LastName, const OwnerOfCar& owner1, const OwnerOfCar& owner2)
{
    cout << '\n';

    for (int i = 0; i < size; ++i)
    {
        if (owners[i].lastName == LastName)
        {
            for (int j = size - 1; j >= i; --j)
            {
                owners[j + 2] = owners[j];
            }
            owners[i] = owner1;
            owners[i + 1] = owner2;
            size += 2;
            break;
        }
    }
}

int main()
{
    OwnerOfCar carOwners[maxOwners];
    int numberOfOwners = 0;

    ifstream file("car_owners");

    if (file.is_open())
    {
        OwnerOfCar tempOwner;
        while (file >> tempOwner.lastName >> tempOwner.firstName >> tempOwner.fathersName >> tempOwner.plateOfCar >> tempOwner.numberOfTechPassport >> tempOwner.numberOfRegistraionOffice)
        {
            carOwners[numberOfOwners++] = tempOwner;
        }

        file.close();
    }
    else
    {
        cout << "File wasn't opened. New file was created.\n";
    }

    OwnerOfCar owner1 = {"Ivanov", "Ivan", "Ivanovych", "BC1111KK", 123456, 1};
    OwnerOfCar owner2 = {"Petrov", "Petro", "Petrovych", "BC5656CC", 234567, 2};
    OwnerOfCar owner3 = {"Mykhalchuk", "Dmytro", "Ivanivna", "BC6504OE", 000001, 100};

    carOwners[numberOfOwners++] = owner1;
    carOwners[numberOfOwners++] = owner2;
    carOwners[numberOfOwners++] = owner3;

    ofstream file_output("car_owners");
    if (file_output.is_open())
    {
        for (int i = 0; i < numberOfOwners; ++i)
        {
            file_output << carOwners[i].lastName << " " << carOwners[i].firstName << " " << carOwners[i].fathersName << " "
                        << carOwners[i].plateOfCar << " " << carOwners[i].numberOfTechPassport << " " << carOwners[i].numberOfRegistraionOffice << '\n';
        }

        file_output.close();
    }

    cout << "\nThe list of car owners before editing:\n";
    printInformation(carOwners, numberOfOwners);

    string carPlateToDelete;
    cout << "Enter car plate to delete: ";
    cin >> carPlateToDelete;
    deleteOwner(carOwners, numberOfOwners, carPlateToDelete);

    cout << "The list after deleting\n";
    printInformation(carOwners, numberOfOwners);

    OwnerOfCar newOwner1 = {"Romanov", "Roman", "Romanovych", "BC1025DD", 345678, 5};
    OwnerOfCar newOwner2 = {"Mykolov", "Mykola", "Mykolovych", "BC2923AA", 456789, 21};

    string lastNameToInsertAfter;
    cout << "Enter the last name from the list to insert after new two owners: ";
    cin.ignore();
    getline(cin, lastNameToInsertAfter);
    addOwners(carOwners, numberOfOwners, lastNameToInsertAfter, newOwner1, newOwner2);

    cout << "The final list: ";
    printInformation(carOwners, numberOfOwners);

    ofstream finalOutputFile("car_owners");

    if (finalOutputFile.is_open())
    {
    for (int i = 0; i < numberOfOwners; ++i)
    {
        finalOutputFile << carOwners[i].lastName << " " << carOwners[i].firstName << " " << carOwners[i].fathersName << " "
                        << carOwners[i].plateOfCar << " " << carOwners[i].numberOfTechPassport << " " << carOwners[i].numberOfRegistraionOffice << '\n';
    }

    finalOutputFile.close();
    cout << "The final list has been saved in the 'car_owners' file." << endl;
    }
    else
    {
    cout << "Error: Unable to open the file for writing." << endl;
    }

    return 0;
}