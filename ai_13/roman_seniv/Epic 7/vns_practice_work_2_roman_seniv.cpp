#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    double initialX = 1.0;
    double initialA = -0.3;
    double ha = 0.2;
    double hx = 0.5;
    double max = 4.0;

    // Використовую динамічні масиви  для збереження значень x, a та z
    vector<double> x_values;
    vector<double> a_values;
    vector<double> z_values;
    // використовую цикл for для обчислення 
    for (double x = initialX, a = initialA; x <= max; x += hx, a += ha) {
        double z = (sqrt(x - 1.5) + pow(x, a)) / pow(x - 2, 1.0 / 3);

        
        x_values.push_back(x);
        a_values.push_back(a);
        z_values.push_back(z);
    }
 // використовую цикл for для виведення результатів
    for (size_t i = 0; i < x_values.size(); ++i) {
        cout << "x: " << x_values[i] << "; a: " << a_values[i] << "; z = " << z_values[i] << endl;
    }

    return 0;
}
