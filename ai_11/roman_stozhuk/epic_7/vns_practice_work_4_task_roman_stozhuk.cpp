#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Number {
    //Вимога #14 - в коді використано структури
    double value;
};

double calculating_process(char *file, int cur_index) {
    ifstream in(file, ios::binary);
    double tmp, sum = 0;
    for (int i = 0; i<=cur_index; i++) {in >> tmp;}
    //Вимога #20 - в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    in.close();
    if (cur_index < 4) {sum += calculating_process(file, cur_index+1);}
    //Вимога #15 - в коді використано рекурсивну функцію
    return sum + tmp;
}

double calculate_arithmetic_mean(char *name) {
    //Вимога #16 - в коді використано параметри та аргументи функції
    double tmp = calculating_process(name, 0);
    //Вимога #16 - в коді використано параметри та аргументи функції
    return tmp/5;
}

int main() {
    cout << "Enter 5 numbers to find their arithmetic mean: ";
    char file_name[] = "test.dat";
    ofstream out(file_name, ios::binary);
    for(int i = 0; i<5; i++) {
        //Вимога #10 - в коді використаний for цикл
        Number matrix[5][5] = {{0},{0},{0},{0},{0}};
        //Вимога #7 - в коді використаний двовимірний масив
        cin >> matrix[i][i].value;
        out << matrix[i][i].value << "\n";
        //Вимога #19 - в коді використано функції роботи з файлами, для того, щоб записати у файл
    }
    out.close();
    std::cout << "Result: " << calculate_arithmetic_mean(file_name);
    return 0;
}