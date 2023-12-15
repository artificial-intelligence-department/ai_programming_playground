#include<iostream>
#include<cmath>
#include<fstream>//бібліотека для роботи з файлами
#include<string>//бібліотека для роботи з рядками
#define e 2.7182 //визначаємо значення числа ейлера (для зручності) 
using namespace std;

int main(){
    float x=0.3;//дійсна змінна
    int count = 0;

    while(x<=5){ //в циклі рахуємо значення функції
        float y = cos(x*x)*pow(e,-x);
        if(y<0){ // якщо значення функції менше нуля - збільшуємо лічильник
            count++;
        }
        x += 0.1;
    }
    
    ofstream f("File_for_number.txt"); //відкриваємо файл для запису
        if(f.bad()){//швидка перевірка на помилки
            cout<<"Error";
            return 0;
        }
    f<<count;//записуємо значення у файл
    f.close();//закриваємо його

    ifstream f2("File_for_number.txt");//відкриваємо файл для читання 
        if(f2.bad()){
            cout<<"Error";
            return 0;
        }

        string line;

        getline(f2, line);// зчитуємо файл

        cout<<line;
        
    f2.close();//закриваємо файл

    return 0;
}
