#include <iostream>
#include <sstream>
using namespace std;

int main(){

    //ask for first num
    cout << "Enter the first num\n";
    int num1;
    cin>>num1;
    if (num1 != static_cast<int>(num1)){
        cout << "Please type number!!!\n";
        return 0;
    }

    // ask for second num
    cout << "Enter the second num\n";
    int num2;
    cin>>num2;

    cout << "Your`s numbers: " << num1 << " " << num2 << endl;

    //ask for kind of calculation

    cout << "What kind of calculation do? (-, +, *, /, %)\n";
    string kindOfCalculation;
    cin>>kindOfCalculation;
    //const auto test = string(kindOfCalculation);
    //cout << kindOfCalculation << endl;
    if (kindOfCalculation == "-")
    {
        int resultOfMinus = num1 - num2;
        cout << "result is: " << resultOfMinus << endl;
    } else
     if (kindOfCalculation == "+")
    {
        int resultOfPlus = num1 + num2;
        cout << "result is: " << resultOfPlus << endl;
    }
    else if (kindOfCalculation == "*")
    {
        int resultOfMultipli = num1 * num2;
        cout << "result is: " << resultOfMultipli << endl;
    }
    else if (kindOfCalculation == "/", num2 != 0)
    {   
        double dnum1 = static_cast<double>(num1);
        double dnum2 = static_cast<double>(num2);
        double result = dnum1 / dnum2;
        ostringstream oss;
        oss << result;
        string resultOfDivision = oss.str();
        resultOfDivision.resize(7);
        cout << "result is: " << resultOfDivision << endl;
    }
    
    else if (kindOfCalculation == "%")
    {
        double resultOfdouble = num1 % num2;
        cout << "result is: " << resultOfdouble << endl;
    }
    else {
        cout << "Error of calculation, try again!";
    }
}