#include <iostream>
#include <cmath>
#include <algorithm>
int main(){
    using namespace std;
// Вводим змінні 
// довжина ніжків
long long int a[4];


//довжина відрізання
long long int l[4];

// скануєм довжину ніжків
for(int i = 0;i < 4; i++){
cin >> a[i];
}

// скануєм довжину скільки потрібно відрізати
for(int i = 0;i < 4; i++){
cin >> l[i];
}


//виводим Error в разі неможливих даних
if(a[0]< l[0] ||a[1]< l[1] ||a[2]< l[2] ||a[3]< l[3]){
    cout <<"ERROR";
    return 0;

}

// вводим зміну міннімальна довжина 
long long int minl = a[0];

//вводим зміну максимальної довжини
long long int maxl = a[0];


for(int j = 0; j < 4; j++){
   
    //відрізаєм кожну ножку по порядку
        a[j] = a[j]-l[j];
        
    //шукаєм найменшу довжину в масиві
     minl = *min_element(a, a+4);


    //шукаєм найбільшу довжину в масиві
    maxl = *max_element(a, a+4);

    //порівнюєм довжини
    if(maxl>= minl*2 || minl == 0){
        cout <<"NO";
        return 0;
}

}


cout <<"YES";


return 0;
}