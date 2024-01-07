#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
    // Функція обрахування довжини відрізка за координатами

    int X1, X2, Y1, Y2;

    cout << "Write coordinates of first dot" << endl;
    cin >> X1 >> Y1;

    cout << "Write coordinates of second dot" << endl;
    cin >> X2 >> Y2;

    int vectorx = X2 - X1;
    int vectory = Y2 - Y1;

    double side;
    side = pow((pow(vectorx, 2) + pow(vectory, 2)), 0.5);

    cout << side << endl;

    // Функція вичислення чи знаходиться задана точка в трикутнику
}