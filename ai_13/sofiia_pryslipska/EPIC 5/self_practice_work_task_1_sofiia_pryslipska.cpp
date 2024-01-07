#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Відкриття файлу для запису
    ofstream file("text.txt");


    // Перевірка, чи вдалося відкрити файл
    if (!file.is_open()) {
        
        cout << "Error opening file for writing." <<endl;
        return 1; 
    }
    

   int n;
   string wish;
   cin>>n;
    cin.ignore(); 
cout<<"enter your wishes:"<<endl;
file<<"                     MY WISHLIST"<<endl;
    for (size_t i = 1; i <= n; i++)
    {
    getline(cin, wish);
        file << "wish № "<<i<<"\t"<<wish<<endl;

    }
    
    // Закриваємо файл
    file.close();

    
    cout << "The file has been successfully created and data has been written to it." << endl;

    return 0; 
}
