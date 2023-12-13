#include <iostream>
using namespace std;
int main(){
    int n;
    int s = 0;
    cout << "Введіть кількість чисел для підсумовування: ";
    cin >> n;
    if (n <= 0){
        cout << "Кількість чисел повинна бути додатним цілим числом." << endl;
        return 1;
    }
    for (int i = 1; i <= n; ++i){
        s += i;
    }
    cout << "Сума перших " << n << " цілих додатних чисел: " << s << endl;
    return 0;
}


