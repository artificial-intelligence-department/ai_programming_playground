#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    // the first task
    // float calculation
    float a, b;
    cout << "Please, enter the values \n";
    cin >> a;
    cin >> b;
    float float_formula = ( pow((a-b), 3) - (pow(a, 3) - 3 * pow(a, 2) * b ) ) / ( pow(b, 3) - 3 * a * pow(b, 2) );
    cout << "Your answer is " << float_formula << "\n";
    // double calculation
    double x, y;
    cout << "Please, enter the values \n";
    cin >> x;
    cin >> y;
    double double_formula = ( pow((x-y), 3) - (pow(x, 3) - 3 * pow(x, 2) * y ) ) / ( pow(y, 3) - 3 * x * pow(y, 2) );
    cout << "Your answer is " << double_formula << "\n";
    // the second task
    int answer_one = ++double_formula * ++float_formula;
    bool answer_two = float_formula++ < double_formula;
    bool answer_three =  double_formula++ > float_formula;
    cout << "The first answer: " << answer_one << "\n";
    cout << "The second answer: " << answer_two << "\n";
    cout << "The third answer: " << answer_three << "\n";
}