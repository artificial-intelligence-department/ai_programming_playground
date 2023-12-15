#include <iostream>
#include <cmath>

using namespace std;

struct Result { // 14. В коді використано структури
    double first;
    double second;
    Result() {
        first = 0;
        second = 0;
    }
};

void outputResult(Result result) { // 16. В коді використано параметри та аргументи функції
    cout << "Result for Z is: " << result.first << endl; // 21. В коді використано оператори введення та виведення даних
    cout << "Result for S is: " << result.second << endl;
}

int main() {
    float m = 0.7; // 2. В коді використана як мінімум одна дійсна змінна
    double x = 1.77; // 3. В коді використана як мінімум одна дійсна з подвійною точністю змінна
    float a = 0.5;
    double b = 1.08;
    double e = 2.71828;
    Result result;
    result.first = sin(x)/(sqrt(1 + pow(m, 3) * pow(sin(x), 2))) - m * x * log(m * x); // 17. В коді використано математичні операції та математичні функції
    result.second = pow(e, -a * x) * sqrt(x+1) + pow(e, b * x) * sqrt(abs(x-3));
    outputResult(result);

    return 0;
}
