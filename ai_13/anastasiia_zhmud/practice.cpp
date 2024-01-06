#include<iostream>
#include<cmath>
#include <cstdlib>
#include<string>
#include <ctime>
#include<fstream>
using namespace std;
int calcul(int i, int j, int a){
    int S=exp(-i*a)*pow(a+1, 0.5)+exp(j*a)*pow(abs(a-3), 0.5);//Вимога 15
    return S;
}
void matrix(int a){//Вимога 14
    int matr[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            matr[10][10]=calcul(i, j, a);//Вимога 7
        }
    }
}
void matrix(int matr[10][10], int a){//Вимога 12
     int temp; //Вимога 1
    for (int k = 0; k < 10 * 10 - 1; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10 - 1; ++j) {
                if (matr[i][j] < matr[i][j + 1]) {
                    temp = matr[i][j];
                    matr[i][j] = matr[i][j + 1];
                    matr[i][j + 1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {//ВИмога 10
        for (int j = 0; j < 10; ++j) {
            cout << matr[i][j] << " ";
        }
        cout<<endl;
    }
}
int sum(int matr[10][10]){//Рахую суму усіх елементів стовпця
    static int sum[10]={0};//Вимога 6
     for (int j = 0; j < 10; ++j){
        for (int i = 0; i < 10; ++i) {
            sum[j]+=matr[i][j];
}int k=sum[j];
return k;}
}
void file(int sum[10],const string FILENAME){//Вимога 16
    ofstream inFile(FILENAME);
    if (inFile.is_open()) { 
        for (int i = 0; i < 10; ++i) {
            inFile << sum[i] << " "; 
}}
inFile.close();}
int openfile(const string FILENAME){//Вимога 16
    ifstream inFile(FILENAME);
    int number;
    int product=1;
    while (inFile >> number) {
            product *= number;
        }
    inFile.close();
    cout<<product;
    return product;
}
void deleteFile(const string FILENAME){
    if (remove(FILENAME.c_str()) == 0) {
        cout<<"Файл успішно видалений";//Вимога 18
}else cout<<"Помилка видалення файлу";
}
int main(){
    const string FILENAME = "F1.txt";
    int matr[10][10], s[10];
    const int a{973}; //Вимога 4
    matrix(a);
    matrix(matr, a);
    for(int i=0; i<10; i++){
        s[i]=sum(matr);
    }
    file(s,FILENAME);
    openfile(FILENAME);
    deleteFile(FILENAME);
}