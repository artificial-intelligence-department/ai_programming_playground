#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

struct CAR_OWNER
{
    char name_surname[150];
    char car_numder[11];
    char phone_number[16];
    char techpassport_number[21];
};

CAR_OWNER askData()
{
    CAR_OWNER owner;
    cout << "Enter your name and surname:\n";
    cin.getline(owner.name_surname, 150);
    cout << "Enter the car number:\n";
    cin.getline(owner.car_numder, 11);
    cout << "Enter your phone number:\n";
    cin.getline(owner.phone_number, 16);
    cout << "Enter techpassport number:\n";
    cin.getline(owner.techpassport_number, 21);
    return owner;
}

void saveDataAboutOwnersIntoFile(string filename, vector<CAR_OWNER> info)
{
    FILE *f;

    f = fopen(filename.c_str(), "wb");
    if (f == NULL)
    {
        cout << "mistake";
        exit(1);
    }
    for (int i = 0; i < info.size(); i++)
    {

        fwrite(&info[i], sizeof(CAR_OWNER), 1, f);
        if (ferror(f) != 0)
        {
            cout << "mistake";
            fclose(f);
            exit(1);
        }
    }
    fclose(f);
};

vector<CAR_OWNER> allCarOwners(int ownnersCount)
{
    vector<CAR_OWNER> info;
    for (int i = 0; i < ownnersCount; i++)
    {
        CAR_OWNER owner = askData();
        info.push_back(owner);
    }
    return info;
}

vector<CAR_OWNER> readInfoAboutAllOwners(string filename)
{
    vector<CAR_OWNER> vec;
    FILE *f;
    f = fopen(filename.c_str(), "rb");
    if (f == NULL)
    {
        cout << "mistake";
        exit(1);
    }
    while (!feof(f))
    {
        CAR_OWNER temp_owner;
        size_t readInfo = fread(&temp_owner, sizeof(CAR_OWNER), 1, f);
        if (readInfo > 0)
        {
            vec.push_back(temp_owner);
        }
        else
        {
            break;
        }
    }
    fclose(f);
    return vec;
}

void removeData(string filename, string car_number)
{
    vector<CAR_OWNER> allOwners = readInfoAboutAllOwners(filename);
    for (int i = 0; i < allOwners.size(); i++)
    {
        if (allOwners[i].car_numder == car_number)
        {
            allOwners.erase(allOwners.begin() + i);
            break;
        }
    }
    saveDataAboutOwnersIntoFile(filename, allOwners);
}

void writeInfoBeforeOwner(string filename, string name_surname, const CAR_OWNER &newOwner)
{
    vector<CAR_OWNER> vec = readInfoAboutAllOwners(filename);
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].name_surname == name_surname)
        {
            vec.insert(vec.begin() + i, newOwner);
            break;
        }
    }
    saveDataAboutOwnersIntoFile(filename, vec);
}

void print(string filename)
{
    vector<CAR_OWNER> allOwners = readInfoAboutAllOwners(filename);
    for (int i = 0; i < allOwners.size(); i++)
    {
        cout << " Information about user: " << endl;
        cout << allOwners[i].name_surname << endl;
        cout << allOwners[i].car_numder << endl;
        cout << allOwners[i].phone_number << endl;
        cout << allOwners[i].techpassport_number << endl;
    }
    return;
}

main()
{
    vector<CAR_OWNER> info = allCarOwners(3);
    saveDataAboutOwnersIntoFile("f.dat", info);

    removeData("f.dat", "ss9900tt");
    print("f.dat");

    vector<CAR_OWNER> twoNewOwners = allCarOwners(2);
    writeInfoBeforeOwner("f.dat", "Petro Dub", twoNewOwners[0]);
    writeInfoBeforeOwner("f.dat", "Petro Dub", twoNewOwners[1]);
    print("f.dat");

    return 0;
}