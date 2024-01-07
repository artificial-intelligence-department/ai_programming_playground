#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
struct book{
    string name;
    string author;
    int year;
    int pages;
    book(string n,string a, int y, int p){
        name = n;
        author = a;
        year = y;
        pages = p;
    }
};
void add(book &b){
    ofstream file;
    file.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/text.txt", ios::app);
    file << b.name << ' ' << b.author << ' ' <<  b.year << ' ' << b.pages << '\n';
    file.close();
}
void del(string &name){
    ifstream file1;
    file1.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/text.txt");
    ofstream file2;
    file2.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/text2.txt", ios::out);
    string sold;
    while(true){
        string s1, s2, s3, s4;
        file1 >> s1 >> s2 >> s3 >> s4;
        if(sold==s1) break;
        if(s1!=name){
            file2 << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << '\n';
        }
        sold = s1;
    }
    file1.close();
    file2.close();
    ifstream file4;
    file4.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/text2.txt");
    ofstream file3;
    file3.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/text.txt", ios::out);
    while(true){
        string s1, s2, s3, s4;
        file4>> s1 >> s2 >> s3 >> s4;
        if(sold==s1) break;
        if(s1!=name){
            file3 << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << '\n';
        }
        sold = s1;
    }
    file3.close();
    file4.close();
}
void show(){
    ifstream file;
    file.open("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/text.txt");
    string s1, s2, s3, s4;
    printf("       name          author       year pages\n");
    int i=0;
    string sold;
    Inp:
    file >> s1 >> s2 >> s3 >> s4;
    if(sold!=s1) cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << '\n';
    i++;
    if(!s1.empty()&&sold!=s1){sold = s1;goto Inp;}
    file.close();
}
int main(){
    book b1("Мітяй_халамитник","Дмитро_Корольчук", 2023, 121);
    book b2("Повість_про_чупапіка","Марко_Кучерявий",2023,69);
    book b3("Пригоди_бабиджона_Яріка","Ярослав_Василишин",2023,529);
    book b4("Поляки_не_люди","Данило_Квіт",2023,1326);
    add(b1);
    add(b2);
    add(b3);
    add(b4);
    show();
    while(true){
        string c;
        cout << "command (add/del/q/show): ";
        cin >> c;
        if(c=="q") break;
        if(c == "add"){
            string name, author;
            int year,pages;
            cout << "enter:  name   author   year   pages";
            cin >> name >> author >> year >> pages;
            book bn(name,author,year,pages);
            add(bn);
        }
        if(c == "del"){
            string name;
            cout << "name: ";
            cin >> name;
            del(name);
        }
        if(c=="show"){
            show();
        }
    }
    return 0;
}