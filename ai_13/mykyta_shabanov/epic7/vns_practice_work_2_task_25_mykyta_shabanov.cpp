#include <math.h>

float TaskCondition(float x, int i)
{
    return pow(x, i) / i;
}

float FindSumOfRow(float x, int end = 10, int i = 1)
{
    float result = 0;

        //using do-while
    do
    {
        result += TaskCondition(x, i);
    } while (i++ < end);
        
    return result;
}

    //overload function
float FindSumOfRow(int x, int end = 10, int i = 1)
{
    float result = 0;

    do
    {
        result += TaskCondition(x, i);
    } while (i++ < end);
        
    return result;
}

#include <iostream>
int main()
{
    float input;

    std::cin >> input;

    std::cout << "result of calculation: " << FindSumOfRow(input);

    return 0;
}