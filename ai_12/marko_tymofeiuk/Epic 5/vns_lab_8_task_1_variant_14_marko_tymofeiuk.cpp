#include <iostream>
#include <fstream>
#include <string>   
#include <vector>

struct Stadium {
    char name[100];
    char address[100];
    int capacity;
    char sportTypes[100];
};

void printStadiums(const Stadium &stadium){
            std::cout << "Name: " << stadium.name << std::endl;
            std::cout << "Address: " << stadium.address << std::endl;
            std::cout << "Capacity: " << stadium.capacity << std::endl;
            std::cout << "Sport Types: " << stadium.sportTypes << std::endl;
            std::cout << "----------------------" << std::endl;

}

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(std::vector<Stadium>& data) {
    std::ofstream outputFile("Stadiums.dat", std::ios::binary);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: Stadiums.dat" << std::endl;
        return Failure;
    }
    for (const Stadium &stadium : data){
        outputFile.write(reinterpret_cast<const char*>(&stadium), sizeof(Stadium));
    }
    outputFile.close();
    return Success;
}

FileOpResult read_from_file() {
    std::ifstream inputFile("Stadiums.dat", std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: Stadiums.dat" << std::endl;
        return Failure;
    }

    Stadium stadium;
    while (inputFile.read(reinterpret_cast<char*>(&stadium), sizeof(Stadium))) {
        printStadiums(stadium);
    }

    inputFile.close();
    return Success;
}

FileOpResult deleteStadium(std::string &choice, std::vector<Stadium> &data){
    int i = 0, check = 0;
    for (const auto& elem : data){
        if (elem.name == choice){
            data.erase(data.begin() + i);
            check++;
        }
        i++;
    }
    if (check == 0){
        std::cerr << "There's been an error. Please restart the program.";
        return Failure;
    }
    std::cout << "Stadium deleted successfully." << std::endl <<std::endl;
    write_to_file(data);
    read_from_file();
    return Success;
}

FileOpResult addStadium(int x, std::vector<Stadium> &data){
    Stadium newStad1 = {"Arena Lviv", "Lviv", 34915, "football"};
    Stadium newStad2 = {"NSC Olimpiyskiy", "Kyiv", 70050, "football, athletics"};

    if (x != 1 && x != 2 && x != 3 && x != 4){
        std::cerr << "There's been an error. Please restart the program.";
        return Failure;
    }

    data.insert(data.begin() + x, newStad1);
    data.insert(data.begin() + x + 1, newStad2);
    std::cout << "Stadiums added successfully." << std::endl << std::endl;
    write_to_file(data);
    read_from_file();
    return Success;

}

int main() {
    std::vector<Stadium> stadiums = {
        {"Wembley Stadium", "London", 90000, "football, rugby, boxing, wrestling"},
        {"Old Trafford", "Manchester", 74310, "football, rugby"},
        {"Emirates Stadium", "London", 60260, "football"},
        {"Etihad Stadium", "Manchester", 54300, "football"},
        {"Anfield", "Liverpool", 53394, "football, rugby"}
    };

    // Write data to the file
    FileOpResult writeResult = write_to_file(stadiums);
    if (writeResult == Success) {
        std::cout << "File was written successfully." << std::endl;
    } else {
        std::cout << "File write failed. Sorry." << std::endl;
    }

    read_from_file();

    std::cout << "Choose an element to delete and enter its name: ";
    std::string choice;
    std::getline(std::cin, choice);

    FileOpResult deleteresult = deleteStadium(choice, stadiums);
    if (deleteresult == Failure){
        return 0;
    }

    std::cout << "Choose the number of a stadium to add new ones after it: ";
    size_t chosenIndex;
    while(chosenIndex!= 1 && chosenIndex != 2 && chosenIndex)
    std::cin >> chosenIndex;


    FileOpResult addresult = addStadium(chosenIndex, stadiums);

    return 0;
}