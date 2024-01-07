#include<iostream>
#include<string>
#include<vector>
std::vector<std::string> libraryInventory = {"Robinson Crusoe D. Dafoe",
                                                "Gulliver's Travels J. Swift",
                                                "Frankenstein M. Shelley",
                                                "Little Women L. May",
                                                "Three man in a Boat J. Jerome"};
std::vector<std::string> libraryInventoryavailibility = {"Availible", "Availible", "Availible", "Availible", "Availible"};
char action;
bool libraryExit = false;
int bookNumber;
bool isContinued;
void PrintLibraryInventoryandAvailibility(std::vector<std::string> books, std::vector<std::string> availibility)
{
    std::cout << "----------Library Inventory----------" << std::endl;
    for(int i = 0; i < size(books); i++)
    {
        for(int y = 0; y < size(availibility); y++)
        {
            if(i == y)
            {
                std::cout << i + 1 <<") " << books[i] << " - " << availibility[y] << std::endl;
            }
        }
    }
}
void GetAction()
{
    PrintLibraryInventoryandAvailibility(libraryInventory, libraryInventoryavailibility);
    std::cout << "Take book(T) \nReturn book(R) \nExit library(E)\nEnter action: ";
    std::cin >> action;

}
void GetNumberOfBook()
{
    PrintLibraryInventoryandAvailibility(libraryInventory, libraryInventoryavailibility);
    std::cout << "Enter number of book: ";
    std::cin >> bookNumber;
}
void TakeBook()
{
    for(int i = 0; i < size(libraryInventoryavailibility); i++)
    {
        if(bookNumber == i + 1 && libraryInventoryavailibility[i] == "Availible")
        {
            libraryInventoryavailibility[i] = "Non Availible";
        }
    }  
}
void ReturnBook()
{
    for(int i = 0; i < size(libraryInventoryavailibility); i++)
    {
        if(bookNumber == i + 1 && libraryInventoryavailibility[i] == "Non Availible")
        {
            libraryInventoryavailibility[i] = "Availible";
        }
    }  
}
void ExitLibrary()
{
    libraryExit = true;
    std::cout << "GoodBye :)" << std::endl;
}
void IsContinued()
{
    std::cout << "Do you want to contine(Y/N): ";
    std::cin >> action;
    if(action == 'Y')
    {
        isContinued = true;
    }
    else
    {
        isContinued = false;
    }
}
int main()
{
    while(!libraryExit)
    {
    mainMenu:
        GetAction();
        switch(action)
        {
            case 'T':  
                do
                {
                    GetNumberOfBook();
                    if((bookNumber < 1 || bookNumber > size(libraryInventory)) || libraryInventoryavailibility[bookNumber - 1] == "Non Availible")
                    {
                        goto mainMenu;
                    }
                    TakeBook();
                    IsContinued();
                }while(isContinued);
                goto mainMenu; 
                break;
            case 'R':      
                do
                {
                    GetNumberOfBook();
                    if((bookNumber < 1 || bookNumber > size(libraryInventory)) || libraryInventoryavailibility[bookNumber - 1] == "Availible")
                    {
                        goto mainMenu;
                    } 
                    ReturnBook();
                    IsContinued();        
                }while(isContinued);
                goto mainMenu; 
                break;
            case 'E': 
                ExitLibrary();
                break;
            default: 
                goto mainMenu; 
                break;
        }
    }
}
