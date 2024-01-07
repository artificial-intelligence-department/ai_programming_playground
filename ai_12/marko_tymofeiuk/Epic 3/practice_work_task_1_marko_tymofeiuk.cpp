#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> libraryMain = {"Brave New World", "A Clockwork Orange", "To Kill a Mockingbird",
     "One Flew Over the Cuckoo's Nest", "The Great Gatsby", "The Picture of Dorian Gray", "Fear and Loathing in Las Vegas",
      "The Catcher in the Rye", "Do Androids Dream of Electric Sheep?", "The Adventures of Huckleberry Finn"};
    std::vector<std::string> borrowedLib;

menu:
    std::cout << "Welcome!" << std::endl
              << "0. List all the books available" << std::endl
              << "1. Borrow a book" << std::endl
              << "2. Return a book" << std::endl
              << "3. Quit" << std::endl;
    int choice;
    std::cout << std::endl;
    while (true){
        std::cin >> choice;
        if (std::cin.fail()){
                std::cout << std::endl << "Invalid input. Please try again." << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore();
        }   else {
                break;
            }
    }

    std::cout << std::endl;

    switch (choice)
    {
    case 0:
        for (int i = 0; i < libraryMain.size(); i++)
        {
            std::cout << i << ". " << libraryMain[i] << std::endl;
        }
        std::cout << std::endl
                  << "What's your next move?" << std::endl
                  << "0.Return to menu" << std::endl
                  << "1.Quit" << std::endl
                  << std::endl;
        int casezerochoice;
    while (true){
        std::cin >> casezerochoice;
        if (std::cin.fail()){
                std::cout << std::endl << "Invalid input. Please try again." << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore();
        }   else {
                break;
            } 
    }
        std::cout << std::endl;
        switch (casezerochoice)
        {
        case 0:
            goto menu;
        case 1:
            return 0;
        }
    case 1:
        std::cout << "Which book do you want to borrow?" << std::endl;
        for (int i = 0; i < libraryMain.size(); i++)
        {
            std::cout << i << ". " << libraryMain[i] << std::endl;
        }
        std::cout << std::endl;
        int bbn;
        while (true){
            std::cin >> bbn;
            if (std::cin.fail()){
                std::cout << std::endl << "Invalid input. Please try again." << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }   else {
                    break;
                } 
        }
        if (bbn >= 0 && bbn < libraryMain.size())
        {
            borrowedLib.push_back(libraryMain[bbn]);
            libraryMain.erase(libraryMain.begin() + bbn);
        }
        else
        {
            std::cout << "Invalid book selection." << std::endl;
        }
        std::cout << std::endl
                  << "What's your next move?" << std::endl
                  << "0.Return to menu" << std::endl
                  << "1.Quit" << std::endl
                  << std::endl;
        int caseonechoice;
            while (true){
        std::cin >> caseonechoice;
        if (std::cin.fail()){
                std::cout << std::endl << "Invalid input. Please try again." << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore();
        }   else {
                break;
            } 
    }
        std::cout << std::endl;
        switch (caseonechoice)
        {
        case 0:
            goto menu;
        case 1:
            return 0;
        }
    case 2:
        if (borrowedLib.empty())
        {
            std::cout << "You haven't borrowed any books yet." << std::endl << std::endl;;
            goto menu;
        }
        else
        {
            std::cout << "Which book do you want to return?" << std::endl;
            for (int i = 0; i < borrowedLib.size(); i++)
            {
                std::cout << i << ". " << borrowedLib[i] << std::endl;
            }
            std::cout << std::endl;
            int rrb;
            while (true){
                std::cin >> rrb;
                if (std::cin.fail()){
                        std::cout << std::endl << "Invalid input. Please try again." << std::endl << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                }   else {
                        break;
                    } 
            }
            if (rrb >= 0 && rrb < borrowedLib.size())
            {
                libraryMain.push_back(borrowedLib[rrb]);
                borrowedLib.erase(borrowedLib.begin() + rrb);
            }
            else
            {
                std::cout << "Invalid book selection." << std::endl;
            }
            std::cout << std::endl
                      << "What's your next move?" << std::endl
                      << "0.Return to menu" << std::endl
                      << "1.Quit" << std::endl
                      << std::endl;
            int casetwochoice;
            while (true){
                std::cin >> casetwochoice;
                if (std::cin.fail()){
                    std::cout << std::endl << "Invalid input. Please try again." << std::endl << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }   else {
                        break;
            }
        }
            std::cout << std::endl;
            switch (casetwochoice)
            {
            case 0:
                goto menu;
            case 1:
                return 0;
            }
        }
    case 3:
        return 0;
    default:
        std::cout << "Invalid input. Please try again." << std::endl
                  << std::endl;
        goto menu;
    }
}