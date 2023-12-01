//
// Created by olehio-h on 11/2/2023.
//
#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    std::vector<std::string> books = {
            "Harry Potter",
            "Lord of the Rings",
            "Bible",
            "Alice in the Wonderlands",
            "Moby Dick",
            "War and Peace",
            "The Odyssey",
            "The Iliad",
            "Heart of Darkness"
    };
    std::vector<bool> books_availability = {
            true, true, true, true, true, true, true, true, true
    };
    std::string menu = """1. [S]how available books\n"
                         "2. [T]ake book\n"
                         "3. [R]eturn book\n"
                         "4. [Q]uit";
    char action = ' ', goOn = ' ', book = ' ';
    std::string availability;
    while(true) {
        home:
        std::cout << menu << std::endl;
        std::cout << ": ";
        std::cin >> action;
        if(action == 'q')
            break;
        do {
            switch (tolower(action)) {
                case 's':
                    for (int i = 0; i < books.size(); i++) {
                        availability = books_availability[i] ? "Available" : "Taken";
                        printf("%2d. %-25s", i + 1, books[i].c_str());
                        printf(" - %s\n", availability.c_str());
                    }
                    break;
                case 't':
                    std::cout << "Enter the book number you want to take or [q] to exit: ";
                    std::cin >> book;
                    while (book != 'q') {
                        if (!books_availability[book - '0' - 1]) {
                            std::cout << "Sorry, but the book is unavailable." << std::endl;
                            std::cout << "Please enter another book number or [q] to exit: ";
                            std::cin >> book;
                        } else {
                            books_availability[book - '0' - 1] = false;
                            break;
                        }
                    }
                    break;
                case 'r':
                    std::cout << "Enter the book number you want to return or [q] to exit: ";
                    std::cin >> book;
                    while (book != 'q') {
                        if (books_availability[book - '0' - 1]) {
                            std::cout << "Sorry, but the book is already returned." << std::endl;
                            std::cout << "Please enter another book number or [q] to exit: ";
                            std::cin >> book;
                        } else {
                            books_availability[book - '0' - 1] = true;
                            break;
                        }
                    }
                    break;
                default:
                    std::cout << "Invalid operation." << std::endl;
                    goto home;
            }
            do {
                std::cout << "Do you want to execute another operation [y]/[n]: ";
                std::cin >> goOn;
            } while((action == 's' && goOn == 'n') || (goOn != 'y' && goOn != 'n'));
        } while(goOn == 'n');
    }
    return 0;
}
