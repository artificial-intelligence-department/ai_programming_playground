#include<iostream>
#include<string>
using namespace std;

int main()
{
    string books[5]={"1984 ","Harry Potter ","Rich dad,Poor dad ","The lord of the rings ","Mainkampf"};
    short status[5]={1,1,1,1,1};
    int chs,chs3,chs4,index=0;
    string chs2;
    

    Menu:
    cout << "       Menu\n" << "1. List all books\n" << "2. Borrow a book\n" << "3. Return a book\n" << "4. Exit\n"<< "Enter your choice: ";
    cin >> chs;
    cout<<endl;

    while(chs!=4)
    {
        if(chs==1)
        {
            for(int i =0;i<5;i++)
            {
                cout<<i+1<<")"<< books[i]<<endl;
            }

            do
            {    
                cout<<"Continue?(y/n)";
                cin>>chs2;
                if(chs2=="y")
                {
                    goto Menu;
                }
                else if(chs2=="n")
                {
                    return 0;
                }
            }while(chs2!="y" || chs2!="n" );

        }
        else if(chs==2)
        {
            cout<<"Which book do you want to borrow?(1-5)"<<endl;
            index=0;
            for(const string& iter : books)
            {
                cout<<iter;
                if (status[index]==1)
                {
                    cout<<" (avaible)"<<endl;
                }
                else
                {
                    cout<<" (unavaible)"<<endl;
                }
                index++;
            }
            cin>>chs3;
            if(status[chs3-1]==0)
            {
                cout<<"You already borrowed it"<<endl;
            }
            status[chs3-1]=0;
            
            do
            {    
                cout<<"Continue?(y/n)";
                cin>>chs2;
                if(chs2=="y")
                {
                    goto Menu;
                }
                else if(chs2=="n")
                {
                    return 0;
                }
            }while(chs2!="y" || chs2!="n" );
        }
        else if(chs==3)
        {
            cout<<"Which book do you want to return?(1-5)"<<endl;
            index=0;
            for(const string& iter2 : books)
            {
                cout<<iter2;
                if (status[index]==1)
                {
                    cout<<" (avaible)"<<endl;
                }
                else
                {
                    cout<<" (unavaible)"<<endl;
                }
                index++;
            }
            cin>>chs4;
            if(status[chs4-1]==1)
            {
                cout<<"You already returned it"<<endl;
            }
            status[chs4-1]=1;           
            
            do
            {    
                cout<<"Continue?(y/n)";
                cin>>chs2;
                if(chs2=="y")
                {
                    goto Menu;
                }
                else if(chs2=="n")
                {
                    return 0;
                }
            }while(chs2!="y" || chs2!="n" );
        }
        else
        {
            cout<<"Your input was incorrect :(";
            goto Menu;
        }
    }

}