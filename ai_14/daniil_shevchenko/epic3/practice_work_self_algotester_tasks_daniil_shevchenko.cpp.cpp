
#include <iostream>
using namespace std;

int main()
{
    long  N;
    cin >> N;
    long difference = N;
    long a500 = difference / 500;
    difference = difference % 500;
    long a200 = difference / 200;
    difference = difference % 200;
    long a100 = difference / 100;
    difference = difference % 100;
    long a50 = difference / 50;
    difference = difference % 50;
    long a20 = difference / 20;
    difference = difference % 20;
    long a10 = difference / 10;
    difference = difference % 10;
    long a5 = difference / 5;
    difference = difference % 5;
    long a2 = difference / 2;
    difference = difference % 2;
    long a1 = difference / 1;
    long count = a500 + a200 + a100 + a50 + a20 + a10 + a5 + a2 + a1;
    cout << count;
}