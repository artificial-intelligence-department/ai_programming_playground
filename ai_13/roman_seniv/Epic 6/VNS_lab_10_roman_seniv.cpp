#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class MyListHandler {
private:
    std::vector<int> myVector;

public:
    void createList() {
        myVector.clear();
    }

    void addElement(int element) {
        myVector.push_back(element);
    }

    void removeElement(int element) {
        auto it = std::find(myVector.begin(), myVector.end(), element);
        if (it != myVector.end()) {
            myVector.erase(it);
        } else {
            std::cout << "Element " << element << " not found in the list." << std::endl;
        }
    }

    void printList() {
        std::cout << "Current list: ";
        for (int element : myVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    void writeToFile(const std::string& filename) {
        std::ofstream outFile(filename, std::ios::binary);
        if (outFile.is_open()) {
            for (int element : myVector) {
                outFile.write(reinterpret_cast<const char*>(&element), sizeof(element));
            }
            std::cout << "List has been written to file " << filename << "." << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }

    void destroyList() {
        myVector.clear();
        std::cout << "List has been cleared." << std::endl;
    }

    void restoreFromFile(const std::string& filename) {
        std::ifstream inFile(filename, std::ios::binary);
        if (inFile.is_open()) {
            myVector.clear();
            int element;
            while (inFile.read(reinterpret_cast<char*>(&element), sizeof(element))) {
                myVector.push_back(element);
            }
            std::cout << "List has been restored from file " << filename << "." << std::endl;
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }
};

int main() {
    MyListHandler myListHandler;

    myListHandler.createList();
    myListHandler.addElement(1);
    myListHandler.addElement(2);
    myListHandler.addElement(3);
    myListHandler.printList();

    myListHandler.writeToFile("my_list.bin");

    myListHandler.destroyList();
    myListHandler.printList();

    myListHandler.restoreFromFile("my_list.bin");
    myListHandler.printList();

    return 0;
}
