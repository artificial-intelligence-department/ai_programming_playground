#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double y, z, x;
    double x_max = 3.0;    //3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const double h = 0.5;   //4. в коді використана як мінімум одна константа
    int size = 0;   //1. в коді використана як мінімум одна цілочисельна змінна
    
    x = 0;
    while(x <= x_max){  //9. в коді використаний while цикл
        x = x + h;
        size++;
    }

    double massif_x[size];  //6. в коді використаний одновимірний масив

    x = 0;
    for(int i = 0; i < size; i++){  //10. в коді використаний for цикл
        massif_x[i] = x;
        x = x + h; 
    }

    double print[size][2];  //7. в коді використаний двовимірний масив

    cout << " | " << " x " << " | " << " y " << " | " << endl;
    for(int i = 0; i < size; i++){  //10. в коді використаний for цикл
        x = massif_x[i];
        z = abs(x) + pow(x, 3);
        y = (z * pow(sin(2 + x), 2)) / (2 + x);

        print[i][0] = x; // Заповнюємо перший стовпець x
        print[i][1] = y; // Заповнюємо другий стовпець y

        cout << "-----------------" << endl;
        cout << " | " << print[i][0] << " | " << print[i][1] << " | " << endl;
    }

    return 0;
}
