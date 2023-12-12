#include <iostream> // used a library iostream to output and input value. This do with function std::cout and std::cin
#include <cmath> //used a library cmath to use mathematical functions such as sqrt and round

using namespace std; // a directive that tells the compiler to use a namespace named std
int main() { // create a function named main
    double ha, hb, hc; // creating variables that are responsible for the results of the heights of their corresponding sides. Type double use to fractional number
    int a = 6, b = 5, c = 3; // creating sides variables. Type int use to whole numbers
    double p; // the variable sum of the sides of the triangle is divided by two
    p = (a + b + c) / 2; //calculation of the value of p according to the formula
    ha = round((2.0 / a) * sqrt(p * (p - a) * (p - b) * (p - c)) * 10) / 10; // calculation of the value of height drawn from the side a according to the formula
    hb = round((2.0 / b) * sqrt(p * (p - a) * (p - b) * (p - c)) * 10) / 10; // calculation of the value of height drawn from the side b according to the formula
    hc = round((2.0 / c) * sqrt(p * (p - a) * (p - b) * (p - c)) * 10) / 10; // calculation of the value of height drawn from the side c according to the formula
    cout << "Side of triangle are: 5, 7 and 6" << endl;
    cout << "The length of the height drawn from the side a: " << ha << endl; // output height drawn from the side a
    cout << "The length of the height drawn from the side b: " << hb << endl; // output height drawn from the side b
    cout << "The length of the height drawn from the side c: " << hc << endl; // output height drawn from the side c
    //function round use to round a number, sqrt use to found the root of a number, cout to output information, cin to input information, endl to new line
}