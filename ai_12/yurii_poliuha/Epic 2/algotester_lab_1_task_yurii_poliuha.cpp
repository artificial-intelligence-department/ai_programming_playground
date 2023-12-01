#include <iostream>
#include <cmath>
using namespace std;

//Функція для перевірки на обмеження
long long limit(){
    long long a;
    bool review = false;
    cin>>a;
    while(review == false){
        if(a < 0 || a > pow(10, 12)) cin>>a;
        else review = true;
    }
    return a;
}

//Функція для знаходження максимального значення
long long MAX(long long a, long long b, long long c, long long d){
    long long max = a;
    if(max < b) max = b;
    if(max < c) max = c;
    if(max < d) max = d;
    return max;
}

//Функція для знаходження мінімального значення
long long MIN(long long a, long long b, long long c, long long d){
    long long min = a;
    if(min > b) min = b;
    if(min > c) min = c;
    if(min > d) min = d;
    return min;
}

int main(){
    long long h1, h2, h3, h4; //Довжини ніжок стола
    long long d1, d2, d3, d4; //Довжини, які будемо відпилювати від відповідних ніжок стола
    long long max, min;
    short rev = 0; //rev - кількість перевертань стола
    h1 = limit();
    h2 = limit();
    h3 = limit();
    h4 = limit();
    d1 = limit();
    d2 = limit();
    d3 = limit();
    d4 = limit();

    h1 = h1 - d1;
    max = MAX(h1, h2, h3, h4);
    min = MIN(h1, h2, h3, h4);
    if(max >= 2 * min && max >= 0 && min >= 0) rev++;

    h2 = h2 - d2;
    max = 0;
    min = 0;
    max = MAX(h1, h2, h3, h4);
    min = MIN(h1, h2, h3, h4);
    if(max >= 2 * min && max >= 0 && min >= 0) rev++;

    h3 = h3 - d3;
    max = 0;
    min = 0;
    max = MAX(h1, h2, h3, h4);
    min = MIN(h1, h2, h3, h4);
    if(max >= 2 * min && max >= 0 && min >= 0) rev++;

    h4 = h4 - d4;
    max = 0;
    min = 0;
    max = MAX(h1, h2, h3, h4);
    min = MIN(h1, h2, h3, h4);
    if(max >= 2 * min && max >= 0 && min >= 0) rev++;

    if(h1 > 0 && h2 > 0 && h3 > 0 && h4 > 0 && rev == 0) cout<<"YES"<<endl;
    else if(h1 < 0 || h2 < 0 || h3 < 0 || h4 < 0 ) cout<<"ERROR"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}