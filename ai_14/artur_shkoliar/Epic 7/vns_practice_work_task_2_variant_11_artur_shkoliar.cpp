#include <iostream>
#include <cmath>

using namespace std;

int main() 
{   
    // 4. в коді використана як мінімум одна цілочисельна константа
    const int pointX = 21; 
    const int pointA = 21; 

     //2. в коді використана як мінімум одна дійсна змінна
    double x1 = 1.0, x2 = 3.0;
    double a1 = 1.0, a2 = 5.0;
    double b = 2.0;
    double k = 0.1;

    //7. в коді використаний двовимірний масив 
    double results2D[pointX][pointA];

    //6. в коді використаний одновимірний масив 
    double results1D[pointX * pointA];

    int index1D = 0; 

    // 10. в коді використаний for цикл
    for (int i = 0; i < pointX + 5; ++i) 
    {   
        // 5. в коді використані умовні оператори та розгалуження

        if (i >= pointX)
        {   
            //11. в коді використано оператори break і continue
            break;
        } 
        double x = x1 + i * k;

        for (int j = 0; j < pointA; ++j) 
        {
            double a = a1 + j * k;

            cout << "x: " << x << ", a: " << a << ", ";

            if (x < b) 
            {
                results2D[i][j] = sin(a * x + pow(2, a));
                results1D[index1D++] = results2D[i][j];
            } 
            else 
            {
                results2D[i][j] = cos(x * a - pow(2, a));
                results1D[index1D++] = results2D[i][j];
            }

            cout << "y = " << results2D[i][j] << endl;
        }
        continue;
    }
}
