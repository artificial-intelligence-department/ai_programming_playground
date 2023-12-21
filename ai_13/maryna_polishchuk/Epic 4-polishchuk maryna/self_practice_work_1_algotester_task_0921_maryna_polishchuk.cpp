//
# include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;  

int main (){
    int a,b;
    cin >> a;
    cin >> b;
        if (a==b){
        return 0;
    } 
    if (a > b) {
         srand(time(nullptr));
    int random_number = b + 1 + rand() % (a - b - 1);
        a-b > 1 ? cout << random_number : cout << "-1";
    }
    if (b > a){
         srand(time(nullptr));
    int random_number = a + 1 + rand() % (b - a - 1);
        b-a > 1 ? cout << random_number : cout << "-1";
    }
return 0;
}
