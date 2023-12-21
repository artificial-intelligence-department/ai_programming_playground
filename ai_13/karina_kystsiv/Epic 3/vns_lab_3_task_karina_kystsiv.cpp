#include <iostream>
#include <cmath>

const double pi = 3.1415;

int main(){
    const int n = 50;
    const double epsilon = 0.0001;
    const int k = 10;
    const double a = 0.1;
    const double b = 0.8;

  for (double x=a; x<=b; x+= (b - a) / k) {

        // Обчислення суми за фіксованою кількістю членів n
        double sn = 0;
        for (int l = 1; l <= n; ++l) {
            sn += std::cos(2 * l * x) / (4 * l * l - 1);
        }
      // Обчислення суми з точністю epsilon
        int i = 1;
        double se = 0;
        double function;
        do {
            function=std::cos(2 * i * x) / (4 * i * i - 1);
        se+=function;
        i++;
        }while (abs(function)>epsilon);
       
          // Точне значення функції
        double y = 0.5 - (pi / 4) * std::abs(std::sin(x));

        std::cout << "X=" << x << " SN=" << sn << " SE=" << se << " Y=" << y << "\n";
    }

    return 0;
}