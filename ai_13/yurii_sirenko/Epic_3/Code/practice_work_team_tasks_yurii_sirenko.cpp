#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    string option;
    string book;
    vector<string>list_initial;
    vector<string>list={"book1","book2","book3","book4"};
    for(int i = 0;i<list.size();i++)
    {
        list_initial.push_back(list[i]);
    }
    list = list_initial;
    cout<<"Welcome to the Yura's library.";
    while(option != "exit")
    {   
        menu:
        cout<<"\nChoose option to do: \n -(list) of books\n -(take) book\n -(return) book \n -(exit)\n";
        cin>>option;
        if(option == "list")
        {
            for(int i = 0;i<list.size();i++)
            {
                cout <<" -"<< list[i]<<"- \n";
            }
            cout << "\nenter - to move to main menu\nenter (exit) to exit library\n";
            cin>>option;
            if(option == "exit")
            {
                break;
            }
            goto menu;
        } 
        if(option == "take")
        {
            cout<<"What book do you want to take?\n";
            cin>>book;
            for(int i = 0;i<list.size();i++)
            {
                if(book == list[i])
                {
                    list.erase(list.begin()+i);
                    cout<<"Succes. Now book -"<<book<<"- is yours!\nenter - to move to main menu\nenter (exit) to exit library\n";
                    cin>>option;
                    if(option == "exit")
                    {
                        break;
                    }
                    goto menu;
                } 
            }
            for(int i = 0;i<list_initial.size();i++)
            {
                if(book == list_initial[i])
                {
                    list.erase(list.begin()+i);
                    cout<<"Sorry, there is no -"<<book<<"- at this moment.\nenter - to move to main menu\nenter (exit) to exit library\n";
                    cin>>option;
                    if(option == "exit")
                    {
                        break;
                    }
                    goto menu;
                } 
            }
            cout<<"There is no -"<<book<<"- in our library at all.\n\n\nenter - to move to main menu\nenter (exit) to exit library\n";
            cin>>option;
            if(option == "exit")
            {
                return 0;
            }
            goto menu;
        }
        if(option == "return")
        {
            cout<<"What book do you want to return?\n";
            cin>>book;
            for(int i = 0;i<list.size();i++)
            {
                if(book == list[i])
                {
                    cout<<"It looks like this book is in library right now\n";
                    goto menu;
                } 
            }
            for(int i = 0;i<list_initial.size();i++)
            { 
                if(book == list_initial[i])
                {
                    list.push_back(book);
                    cout<<"Succes. Now book -"<<book<<"- is in library again!\nenter - to move to main menu\nenter (exit) to exit library\n";
                    cin>>option;
                    if(option == "exit")
                    {
                        break;
                    }
                    goto menu;
                }
            }
                
                
            cout<<"Do you want to share with us your new book?\n type (y) for yes, (n) for no\n";
                
            cin>>option;
            if(option == "y")
            {
                list.push_back(book);
                list_initial.push_back(book);
                cout<<"Succes. Now book -"<<book<<"- is in library again!\nenter - to move to main menu\nenter (exit) to exit library\n\n";
                cin>>option;
                if(option == "exit")
                {
                    break;
                }
                goto menu;
            }
            else if(option == "n")
            {
                goto menu;
            }
                
            
        }
    }
}