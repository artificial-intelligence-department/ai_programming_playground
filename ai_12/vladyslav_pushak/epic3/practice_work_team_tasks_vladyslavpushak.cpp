#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> book = {"1984", "The Catcher in the Rye", "Moby-Dick", "The Odyssey"};

    std::vector<bool> isAvailable = {true, true, true, true}; 

    char option;
    do {
        std::cout << "Options:" << std::endl
         << "1. Show all books" << std::endl
          << "2. Borrow a book" << std::endl
         << "3. Return a book" << std::endl
          << "4. Quit" << std::endl
          << "Choose an option: "<<std::endl;
        std::cin >> option;

        switch (option) {
            case '1': 
                std::cout << "All books" << std::endl;
                for (const auto& title : book) { 
                    std::cout << title << std::endl;
                }
                break;
            case '2': { 
                std::cout << "Select a book by its number: " << std::endl;
                for (int i = 0; i < book.size(); ++i) {
                    std::cout << i + 1 << ". " << book[i] << " - ";
                    std::cout << (isAvailable[i] ? "available" : "unavailable") << std::endl;  
                }
                int bookIndex;
                std::cout << "Book number: ";
                std::cin >> bookIndex;

                if (bookIndex >= 1 && bookIndex <= book.size()) {
                    if (isAvailable[bookIndex - 1]) {
                        isAvailable[bookIndex - 1] = false;
                        std::cout << "You borrowed the book '" << book[bookIndex - 1] << "'" << std::endl;
                    } else {
                        std::cout << "This book has already been borrowed" << std::endl;
                    }
                } else {
                    std::cout << "Invalid book number" << std::endl;
                }
                break;
            }
            case '3': { 
                std::cout << "Select a book by its number: " << std::endl;
                for (int i = 0; i < book.size(); ++i) {
                    std::cout << i + 1 << ". " << book[i] << " - ";
                    std::cout << (isAvailable[i] ? "available" : "unavailable") << std::endl;
                }
                int bookIndex;
                std::cout << "Book number: ";
                std::cin >> bookIndex;

                if (bookIndex >= 1 && bookIndex <= book.size()) {
                    if (!isAvailable[bookIndex - 1]) {     
                        isAvailable[bookIndex - 1] = true;
                        std::cout << "You returned the book '" << book[bookIndex - 1] << "'" << std::endl;
                    } else {
                        std::cout << "This book is already in the library" << std::endl;
                    }
                } else {
                    std::cout << "Invalid book number" << std::endl;
                }
                break;
            }
            case '4': 
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again!" << std::endl;
                break;
        }
    } while (option != '4');

    return 0;
}
