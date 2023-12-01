//
//#include <iostream>
//
//int main()
//{
//    int a = 1000;
//    float b = 0.0001;
//    
//    float result = 0;
//    float value1 = pow(a + b, 3);
//    float value2 = (pow(a, 3) + 3 * a * a * b);
//    float value3 = 3 * a * b * b + pow(b, 3);
//
//    result = (value1 + value2) / value3;
//    printf("%f", result);
//
//
//}

#include <iostream>

int main()
{
    int a = 1000;
    double b = 0.0001;

    double result = 0;
    double value1 = pow(a + b, 3);
    double value2 = (pow(a, 3) + 3 * a * a * b);
    double value3 = 3 * a * b * b + pow(b, 3);

    result = (value1 + value2) / value3;
    printf("%f", result);


}


