#include<iostream>  
#include<cmath>     //підключив бібліотеки 
#include<cstdio>    
using namespace std;     

int main(){
double phi, epsi, m = 2, c = 1, x = 1.2, b = 0.7;   //ініціалізував змінні, надав їм значення

phi = sqrt(m*tan(x)+ abs(c*sin(x)));        //обчислюю за формулою phi

epsi = m*cos(b*x+sin(x))+pow(c,3);          //обчислюю за формулою epsi

cout << "Result of phi: " << phi << endl;       //виводжу стрічку та значення phi
cout << "Result of epsi: " << epsi << endl;     //виводжу стрічку та значення epsi
    return 0;
}