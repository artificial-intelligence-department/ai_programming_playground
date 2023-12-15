#include<iostream>
#include<cmath>
#include<stdarg.h>


//Так як за умовами задачі не сказано,де розташований центр кола,буду вважати,що він знаходиться у початку координат

bool IsInCircle(double x, double y, double rad){
    double DistanceToCenter = std::sqrt(pow(x,2)+pow(y,2));
    bool ans = (DistanceToCenter <= rad) ? true : false;
    return ans;
}

int HowManyOfThemInCircle(double radius, int PointsNumber, ...){
    va_list coordinates;
    va_start(coordinates,PointsNumber);

    int counter = 0;

    for(int i = 0;i < PointsNumber;i += 2){
        double x = va_arg(coordinates,double);
        double y = va_arg(coordinates,double);

        if(IsInCircle(x, y, radius))
            counter += 1;
    }

    return counter;
}

int main(){
    using namespace std;

    double CircleRadius = 10;

    cout << HowManyOfThemInCircle(CircleRadius, 3, 7, 1, 2, 4.5, 3.4, 10);
    cout << HowManyOfThemInCircle(CircleRadius, 9, 1, 2, 3, 4, 5.2, 6, 7.1, 8, 9);
    cout << HowManyOfThemInCircle(CircleRadius, 11, 1.2, 2.3, 3.1, 4.7, 5.3, 6.6, 7.1, 8, 9.9, 10, 1);
    
    return 1;
}