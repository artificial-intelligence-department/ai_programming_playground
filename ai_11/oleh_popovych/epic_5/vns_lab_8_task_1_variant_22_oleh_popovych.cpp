//
// Created by olehio-p on 12/6/2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


struct CarOwner{
    std::string firstName;
    std::string lastName;
    std::string carNumber;
    std::string techPassportNumber;
    std::string registrationNumber;
};

void deleteByCarNumber(std::vector<CarOwner>&, const std::string&);
void print(const std::vector<CarOwner>&);
void addOwner(std::vector<CarOwner>&, const std::string&, const CarOwner&, const CarOwner&);

int main() {
    std::vector<CarOwner> carOwners = {
            {"Ivanov", "Ivan", "ABC123", "TP123", "Division1"},
            {"Petrov", "Petr", "XYZ789", "TP456", "Division2"},
            {"Oleh", "Oleh", "ABD252", "TA225", "Division3"}
    };

    std::ofstream outFile("file1.bin", std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open this file" << std::endl;
        return -1;
    }

    outFile.write(reinterpret_cast<const char*>(carOwners.data()), carOwners.size() * sizeof(CarOwner));
    outFile.close();


    std::ifstream inFile("file1.bin", std::ios::binary);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open this file" << std::endl;
        return -1;
    }

    std::vector<CarOwner> readOwners;
    CarOwner tempOwner;

    while (inFile.read(reinterpret_cast<char*>(&tempOwner), sizeof(CarOwner))) {
        readOwners.push_back(tempOwner);
    }
    inFile.close();

    std::cout << "Content of file: " << std::endl;
    print(readOwners);

    deleteByCarNumber(readOwners, "XYZ789");

    CarOwner newOwner1 = {"New1", "Ivanovich", "123ABC", "TP456", "Division3"};
    CarOwner newOwner2 = {"New2", "Ivanovich", "456DEF", "TP789", "Division4"};
    addOwner(readOwners, "Ivanov", newOwner1, newOwner2);

    std::ofstream outResFile("file1.bin", std::ios::binary);
    if (!outResFile.is_open()) {
        std::cerr << "Unable to open this file" << std::endl;
        return -1;
    }

    outResFile.write(reinterpret_cast<const char*>(readOwners.data()), readOwners.size() * sizeof(CarOwner));
    outResFile.close();

    std::cout << "Updated content of file:" << std::endl;
    std::ifstream inResFile("file1.bin", std::ios::binary);
    if (!inResFile.is_open()) {
        std::cerr << "Unable to open this file" << std::endl;
        return -1;
    }

    std::vector<CarOwner> newOwners;

    while (inResFile.read(reinterpret_cast<char*>(&tempOwner), sizeof(CarOwner))) {
        newOwners.push_back(tempOwner);
    }
    inResFile.close();
    print(newOwners);

    return 0;
}


void print(const std::vector<CarOwner>& owners) {
    for (const auto& owner : owners) {
        std::cout << "First name: " << owner.firstName << std::endl;
        std::cout << "Second name: " << owner.lastName << std::endl;
        std::cout << "Car number: " << owner.carNumber << std::endl;
        std::cout << "Tech passport number: " << owner.techPassportNumber << std::endl;
        std::cout << "Registration number: " << owner.registrationNumber << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }
}

void addOwner(std::vector<CarOwner>& owners,
              const std::string& targetLastName,
              const CarOwner& newOwner1,
              const CarOwner& newOwner2) {

    const std::vector<CarOwner>::iterator &it = std::find_if(owners.begin(), owners.end(),
                                                             [&targetLastName](const CarOwner &owner) {
                                                                 return owner.lastName == targetLastName;
                                                             });

    owners.insert(it, newOwner1);
    owners.insert(it, newOwner2);
}


void deleteByCarNumber(std::vector<CarOwner>& owners, const std::string& targetNumber) {

    const std::vector<CarOwner>::iterator &it = remove_if(owners.begin(), owners.end(),
                                                          [&targetNumber](const CarOwner& owner) {
                                                              return owner.carNumber == targetNumber;
                                                          });
    owners.erase(it, owners.end());
}
