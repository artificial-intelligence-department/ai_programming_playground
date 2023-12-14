#include <iostream> 
#include <cmath> 
#include <fstream>

using namespace std;

int main(){
//Вимога 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double m =2.1; 
    double t = 1.02; 
    double P; 
    double K; 
//Вимога 1. в коді використана як мінімум одна цілочисельна змінна   
    int c = -1; 

//Вимога 20. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    ofstream File_1("Result.txt");
//Вимога 5. в коді використані умовні оператори та розгалуження
 if (!File_1.is_open()) {
        cout << "Unable to open the input file." << endl;
        return 1;
    }    
File_1 << m << t << c;
File_1.close();

ifstream File_2("Result.txt");
File_2 >> m >> t >> c;

//Вимога 17. в коді використано математичні операції та математичні функції
    P = cbrt(m * tan(t)+fabs(c * sin(t)));
    K = (pow(cos(t),2) - m)/cbrt(fabs(pow(m,2)-pow(t,2)));
File_2.close();
//Вимога 21. в коді використано оператори виведення та введення даних
    cout << "RESULT FOR P: " << P << endl; 
    cout << "RESULT FOR K: " << K << endl;
    
}