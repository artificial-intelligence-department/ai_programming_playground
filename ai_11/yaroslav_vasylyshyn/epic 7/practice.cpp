#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void creation(float a[10][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = pow(i, 2) + pow(j, 2);
        }
    }
}

void creationint(int a[10][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //математичні операції
            a[i][j] = pow(i, 2) + pow(j, 2);
        }
    }
}

//перевантаження фунції параметри та аргументи
void perevantazh(float a[10][10], const int variant){
    for (int j = 0; j < 10; ++j){
        for (int i = 0; i < 10 - 1; ++i){
            for (int k = 0; k < 10 - i - 1; ++k){
                if (a[k][j] > a[k + 1][j])                   
                    swap(a[k][j], a[k + 1][j]);
            }
        }
    }
}

void perevantazh(int a[10][10], const int variant){
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10 - 1; ++j){
            for (int k = 0; k < 10 - j - 1; ++k){
                if (a[i][k] < a[i][k + 1])
                    swap(a[i][k], a[i][k + 1]);
            }
        }
    }
}

void show(float a[10][10]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << '\n';
    }
}

int* calculateSums(float a[10][10]) {
    int* sums = new int[10];//одновимірний масив
    srand(time(nullptr));
    for (int j = 0; j < 10; ++j) {
        //одна цілочисельна змінна дійсна змінна  з подвійною точністю
        int sum = 0;
        double a;
        float a;
        for (int count = 0; count < 4; ++count) {
            int randomRow = rand() % 10;
            sum += static_cast<int>(a[randomRow][j]);
        }
        sums[j] = sum;
    }
    return sums;
}

void showSums(int* sums) {
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << '\t';
    }
    cout << '\n';
}
//функції роботи з файлами
bool write(string& name_of_the_file, int* a){
    ofstream file_stream1(name_of_the_file, ios::out);
    if (file_stream1.is_open()) 
    {
        for (int i = 0; i < 10; i++)
        {
            file_stream1 << a[i] << '\n';
        }
        file_stream1.close();
        return true;
    }else
        cout << "Error while opening" << endl;
        return false;
}
//для того щоб зчитати
int read(string& name_of_the_file, int* a){
    ifstream file_stream2(name_of_the_file);
    if (file_stream2.is_open()) 
    {
        int product = 1;
        int value;
            //while loop
        while (file_stream2 >> value){
            product *= value;
        }
        cout<<product;
        file_stream2.close();
        return product;
    }else 
        cout << "Error while opening" << endl;
        return 0;
}

void show(int a[10][10]){
    for (int i = 0; i < 10; i++)// for циул
    {
        for (int j = 0; j < 10; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << '\n';
    }
}
void deleteFile(string name_of_the_file){
    //умовний оператор
    if (remove(name_of_the_file.c_str()) == 0) {
        cout << "File deleted successfully." << endl;
    } else {
        cerr << "Error deleting the file." << endl;
    }
}

int main(){
    //цілочисельна константа
    const int a = 944;
    float myMatrixFloat[10][10];//двовимірний
    int myMatrixInt[10][10];

    creation(myMatrixFloat);
    creationint(myMatrixInt);
    show(myMatrixFloat);
    cout<<'\n';
    show(myMatrixInt);
    perevantazh(myMatrixFloat, a);
    perevantazh(myMatrixInt, a);
    show(myMatrixFloat);
    cout<<'\n';
    show(myMatrixInt);
    cout<<'\n';
    int* sum = calculateSums(myMatrixFloat);
    showSums(sum);
    string file_name = "practice.txt";
    write(file_name, sum);
    int sum1 = read(file_name, sum);
    //вивід
    cout<<'\n';
    //do while loop
    do{
        cout<<"Bye";
    }while(a>1000);
    deleteFile(file_name);

    return 0;
}