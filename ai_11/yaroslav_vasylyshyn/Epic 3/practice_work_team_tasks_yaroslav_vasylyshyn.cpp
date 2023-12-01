#include <iostream>
#include <string>

using namespace std;

int main(){
    //Задання всіх змінних
    string books[]={"All_the_Bright_Places","One_of_Us_is_Lying","Harry_Potter","Rich_Dad_Poor_Dad"};
    bool availability[]={true,true,true,true};
    int option,index=-1;
    string name_of_the_book;
    checkpoint:
    cout<<"Select an option from the list:\n1:Display list of all books\n2:Return a book\n3:Borrow a book\n4:Quit\nPlease enter your choice:";
    cin>>option;
    //Усі можливі дії(світч)
    switch (option)
    {
        case 1:
            for (int i = 0; i < 4; i++)
            {
            if (availability[i])
                cout<<i+1<<":"<<books[i]<<" is available\n";
            else
                cout<<i+1<<":"<<books[i]<<" is not available\n";
            }
            break;
        case 2:
            checkpoint1:
            cout<<"Enter the name of the book u want to return:";
            cin>>name_of_the_book;
            for (int i = 0; i < 4; i++)
            {
                if(name_of_the_book == books[i])
                    index = i;
            }
            if(index == -1)
            {
                cout<<"Enter an appropriate name of the book next time please)\n";
                goto checkpoint1;
            }else{
                if(!availability[index])
                {
                    cout<<"You've returned the book!\n";
                    availability[index]=true;
                }else
                {
                    cout<<"The Book wasn't borrowed!\n";
                }
                index=-1;
            }
            break;
        case 3:
            checkpoint2:
            cout<<"Enter the name of the book u want to borrow:";
            cin>>name_of_the_book;
            for (int i = 0; i < 4; i++)
            {
                if(name_of_the_book == books[i])
                    index = i;
            }
            if(index == -1)
            {
                cout<<"Enter an appropriate book next time please\n)";
                goto checkpoint2;
            }else
            {
                if(availability[index])
                {
                    cout<<"You've borrowed the book!\n";
                    availability[index]=false;
                }else
                {
                    cout<<"The Book is borrowed\n";
                }
                index=-1;
            }
            break;
        case 4:
            cout<<"Goodbye:)";
            return 0;

        default:
            cout<<"Enter an appropriate number please\n";
            break; 
    } 
    //Продовження і вихід із програми
    char ch;
    cout<<"Do you want to continue?(Y/N)";
    do
    {
    cin>>ch;
    } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
    if (ch == 'y' || ch == 'Y')
    goto checkpoint;
    else 
    cout<<"Goodbye:)";
    
    return 0;
}