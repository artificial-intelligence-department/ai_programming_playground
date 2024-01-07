#include <iostream>
#include <cmath>
using namespace std;

void load_to_array(double arr[2][3],const double arr1[3], const double arr2[3]){ //параметри та аргументи функції
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i == 0) { //умовні оператори та розгалуження
                arr[i][j] = arr1[j];
            }
            else {
                arr[i][j] = arr2[j];
            }
        }
    }
}

struct sample{ //Приклад структури
    int a;
    double b;
};

int main() {
    float duym = 2.54; //дійсна змінна
    double foot = 12*duym; //дійсний з подвійною точністю змінна
    double yard = 3*foot;
    double size = 130*yard;
    string lastname;
    cin >> lastname;
    const int letter_size = 3*80; //цілочисельна константа
    int lastname_size = lastname.length()*letter_size;
    double space = (size-lastname_size)/2;
    double min_size = size - space*2;
    cout << "Minimum size for lastname: " << min_size << endl;
    double center_left[3]; //одновимірний масив
    int j = -150;
    for (int i = 0; i < 3; ++i) {
        center_left[i] = min_size/2 + j;
        j += 100;
    }
    double letter_nums_left[3];
    int i = 0;
    while (i < 3){
        letter_nums_left[i] = round(center_left[i]/letter_size);
        i++;
    }
    i = 0;
    do {
        cout << lastname[letter_nums_left[i]-1] << " ";
        i++;
    } while (i < 3);
    cout << endl;
    double center_right[3];
    j = 150;
    for (int k = 0; k < 3; k++) { //for цикл
        center_right[k] = min_size/2 + j;
        j -= 100;
    }
    double letter_nums_right[3];
    i = 0;
    while (i < 3){ //while цикл
        letter_nums_right[i] = round(center_right[i]/letter_size); //математичні операції та математичні функції
        i++;
    }
    i = 0;
    do { //do while цикл
        cout << lastname[letter_nums_right[i]-1] << " ";
        i++;
    } while (i < 3);
    cout << endl;
    double letter_nums[2][3]; //двовимірний масив
    load_to_array(letter_nums, letter_nums_left, letter_nums_right);
    //Букви повторюються, тому що одна з них випала на межу центрального метра і по факту знаходиться на двох центральних метрах одразу
    return 0;
}
