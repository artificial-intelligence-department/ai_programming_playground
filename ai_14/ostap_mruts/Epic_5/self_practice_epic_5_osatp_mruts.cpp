#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words = {
        "Definitely", "Separate", "Occurred", "Accommodate", "Embarrass",
        "Receive", "Weird", "Occasion", "Privilege", "Conscious"
    };

    std::ofstream file("C:\\Users\\MAHINA\\Desktop\\MyE5\\words.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    bool incorrectWritten = false;
    
    file << "Correct words:" << std::endl;
    for (const std::string& word : words) {
        std::string userInput;
        std::cout << "Please enter the word '" << word << "': ";
        std::cin >> userInput;

        if (userInput == word) {
            file << word << std::endl;
        } else {
            if (!incorrectWritten) {
                file << std::endl;
                file << "UnCorrect words:" << std::endl;
                file << std::endl;
                incorrectWritten = true;
            }
            file << userInput << std::endl;
        }
    }

    file.close();

    std::cout << "Check the file for the results." << std::endl;

    return 0;
}