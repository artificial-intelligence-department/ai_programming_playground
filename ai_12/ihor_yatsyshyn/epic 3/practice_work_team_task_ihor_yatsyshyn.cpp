#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    std::vector<bool> availability = {true, true, true, true};
    int operation, take, ret;
    std::string continueWork;

    while(true){
        std::cout << "LIBRARY MANAGEMENT" << std::endl;
    tryAgain:
        std::cout << "Please choose an operation:" << std::endl;
        std::cout << "1. List all books" << std::endl;
        std::cout << "2. Borrow a book (if available)" << std::endl;
        std::cout << "3. Return the book" << std::endl;
        std::cout << "4. Exit the program" << std::endl;
        std::cin >> operation;

        if(operation == 1){
            for(int i = 0; i < 4; i++){
                std::cout << i + 1 << "." << books[i] << std::endl;
            }
        }else if(operation == 2){
            for(auto element: availability){
                if(element){
                    std::cout << "is avaliable \n";
                }else {
                    std::cout << "is not avaliable \n";
                }
            }
            std::cout << "Enter the number of book you want to borrow" << std::endl;
            std::cin >> take;
            if(availability[take - 1] = false) {
                std::cout << "Sorry, this book has already been borrowed" << std::endl;
            }else {
                availability[take - 1] = false;
                std::cout << "The book has been borrowed successfully" << std::endl;
            }
        }else if(operation == 3){
            for(auto element: availability){
                if(element){
                    std::cout << "is in library \n";
                }else {
                    std::cout << "must be returned \n";
                }
            }
            std::cout << "Enter the number of book you want to return" << std::endl;
            std::cin >> ret;
            if(availability[ret - 1] = true) {
                std::cout << "This book is already in library" << std::endl;
            }else{
                availability[ret - 1] = true;
                std::cout << "Thanks for returning the book" << std::endl;
            }
        }else if(operation == 4){
            break;
        }else{
            std::cout << "Sorry, such operation doesn't exist" << std::endl;
            goto tryAgain;
        }

        do{
           std::cout << "Do you want to continue? (Enter 'yes' or 'no')" << std::endl;
           std::cin >> continueWork;

           if(continueWork == "no"){
                return 0;
           }else{
                break;
           }
        }while (continueWork == "yes");
    }

    return 0;
}