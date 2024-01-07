#include<iostream>

using namespace std;
double pow(double number, int count)
{

    if(count == 1 ){
        return number;
    }
    return number * pow(number, count - 1);

}
int factorial(int number)
{
    if(number == 1)
    {
        return number;
    }
    return number * factorial(number - 1);

}

double sum(int number)
{
    double sum = 0.0;
    for(int i = 1;i <= number; i++)
    {
        sum += pow(10, i ) /factorial(i);
    }
    return sum;
}


int main()
{
    int number_of_part;
    cin >> number_of_part;
    printf ("Result: %.4f%"  , sum(number_of_part));
    return 0;
}
