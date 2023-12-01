#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Creating and enetering number
    int number;
    printf("Enter number, which you want to raise to a power: ");
    scanf("%d", &number);

    //Creating and enetering power
    int power;
    printf("Enter power: ");
    scanf("%lf", &power);

    //Creating answer which will be chnaged during loop
    int answer = 1;

    //For loop, which multiplies answer by power times
    for (int i = 0; i < power; i++)
    {
        answer *= number;
    }

    // Output result value
    printf("After you raised %d to power %d, you get %d", number, power, answer);
    return 0;
}
