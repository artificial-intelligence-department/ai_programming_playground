#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(){
    long long hitpoint,mana;
    long long h1,m1,h2,m2,h3,m3;

    cout << "Enter the points:";
    cin >> hitpoint >> mana;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;
    while(hitpoint <1 || hitpoint > pow(10,12)){
        cout << "Hitpoint's number is wrong\n";
        cout << "Write correct answer:";
        cin >> hitpoint;
    }
    while(mana <1 || mana > pow(10,12)){
        cout << "Mana's number is wrong\n";
        cout << "Write correct answer:";
        cin >> mana;
    }
    while(h1 <0 || h1 > pow(10,12)){
        cout << "The number of h1 is wrong\n";
        cout << "Write correct answer:";
        cin >> h1;
    }
    while(m1 <0 || m1 > pow(10,12)){
        cout << "The number of m1 is wrong\n";
        cout << "Write correct answer:";
        cin >> m1; 
    }
     while(h2 <0 || h2 > pow(10,12)){
        cout << "The number of h2 is wrong\n";
        cout << "Write correct answer:";
        cin >> h2;
    }
    while(m1 <0 || m1 > pow(10,12)){
        cout << "The number of m2 is wrong\n";
        cout << "Write correct answer:";
        cin >> m2; 
    }
     while(h3 <0 || h3 > pow(10,12)){
        cout << "The number of h3 is wrong\n";
        cout << "Write correct answer:";
        cin >> h3;
    }
    while(m3 <0 || m3 > pow(10,12)){
        cout << "The number of m3 is wrong\n";
        cout << "Write correct answer:";
        cin >> m3; 
    }
    
    if(h1>0 && m1>0){
        cout << "no";
    }
    else if(h2>0 && m2>0){
        cout << "no";
    }
    else if(h3>0 && m3>0){
        cout << "no";
    }
    else if(h1>hitpoint || h2>hitpoint || h3>hitpoint){
        cout << "no";
    }
    else if(m1>hitpoint || m2>hitpoint || m3>hitpoint){
        cout << "no";
    }
    else if(hitpoint>0 && mana>0){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
    

}



