#include <iostream>
#include <string>
#include <vector>
using namespace std;
void show(vector<string> b,vector<bool> a);
void take(vector<string>& b, vector<bool>& a, string book);
void ret(vector<string>& b, vector<bool>& a, string book);
int main() {
    bool running = true;
    string command;
    vector<string> books = {"book1","book2","book3"};
    vector<bool> availability{true, true, true};
    cout << "Manual:\n"
            "exit\n"
            "show\n"
            "take <book>\n"
            "return <book>\n";
    while(running){
        MainMenu:
        cout << "Enter command: ";
        cin >> command;
        if(command=="show"){
            show(books,availability);
            do{cout << "Wanna continue? (y/n)\n";
                cin >> command;
                if(command=="n"){
                    running = false;
                    goto End;
                }else if(command=="y") goto End;
            }while(command!="n"||command!="y");
        }else if(command=="exit"){
            running=false;
            continue;
        }else if(command=="take"){
            string name;
            cout << "Book name:  (0 to back)";
            cin >> name;
            if(name!="0")take(books,availability,name);
            else goto MainMenu;
            do{cout << "Wanna continue? (y/n)\n";
                cin >> command;
                if(command=="n"){
                    running = false;
                    goto End;
                }else if(command=="y") goto MainMenu;
            }while(command!="n"||command!="y");
        }else if(command=="return"){
            string name;
            cout << "Book name:  (0 to back)";
            cin >> name;
            if(name!="0")ret(books,availability,name);
            else goto MainMenu;
            do{cout << "Wanna continue? (y/n)\n";
                cin >> command;
                if(command=="n"){
                    running = false;
                    goto End;
                }else if(command=="y") goto MainMenu;
            }while(command!="n"||command!="y");
        }
        End:
    }
    return 0;
}
void show(vector<string> b,vector<bool> a){
    int l = b.size();
    for(string i:b) cout << i << '\n';
}
void take(vector<string>& b, vector<bool>& a, string book){
    int l = b.size();
    int b_i = -1;
    for(int i=0;i<l;i++) if(b[i]==book) b_i = i;
    if(b_i==-1){
        cout << "no such book\n";
    }else{
        if(a[b_i]) a[b_i]=false;
        else cout << "book is not available\n";
    }
}void ret(vector<string>& b, vector<bool>& a, string book){
    int l = b.size();
    int b_i = -1;
    for(int i=0;i<l;i++) if(b[i]==book) b_i = i;
    if(b_i==-1){
        cout << "no such book\n";
    }else{
        if(!a[b_i]) a[b_i]=true;
        else cout << "book is already in the library\n";
    }
}