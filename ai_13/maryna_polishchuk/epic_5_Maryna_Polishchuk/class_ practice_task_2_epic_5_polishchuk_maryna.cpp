#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
    ofstream var1("file_from");
    for(int i = 1; i < 3; i++)
    {
        string userwrite;
        cout << "Enter your text";
        getline(cin, userwrite);
        var1 << userwrite << endl;
    } 
    var1.close(); // <- обов'язково закривати файл, щоб потім мати можливість його нормально відкрити заново

    ifstream var3("file_from");
    if (var3.is_open())
    {
        string str;
        //за допомогою getline відкриваємо файл var1, 
        //та записуємо зміст першої стрічки в str
        getline(var3, str);

        while(getline(var3, str))
        {
            cout << str << endl;
        }
        var3.close();
        }
            string line;
    ifstream var4("file_from");
    ofstream var2("file_to");
    for(int i = 1; getline(var4, line); i++)
    {           
        var2 << line << endl;
    }

    var4.close(); var2.close();
    
    remove("nameOfFile.dat");
    rename("temp.dat", "nameOfFile.dat");

    return 0;
}