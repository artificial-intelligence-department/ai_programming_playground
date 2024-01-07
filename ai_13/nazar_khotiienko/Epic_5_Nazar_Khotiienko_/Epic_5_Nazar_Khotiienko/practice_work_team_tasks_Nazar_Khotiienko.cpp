#include <iostream>
#include <fstream>
using namespace std;

using namespace std;

int main()
{
    string path = "Myfiile.txt";
    ofstream fout;
    fout.open(path);
    cout <<"Напишіть імя ";
    string N;
    cin >>N;

    if (!fout.is_open()){ // якщо не получилося відкрити
    cout << "Помилка";
    }
    else{
        fout <<N;
        cout << "Файл створено";
    }

   fout.close();

      return 0;
}