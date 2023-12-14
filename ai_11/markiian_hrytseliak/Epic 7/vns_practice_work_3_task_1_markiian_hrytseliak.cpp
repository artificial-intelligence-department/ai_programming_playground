#include <iostream>
#include <cmath>

using namespace std;

double speed(double dist, float time)
{
    const int km = 1000;
    const int hour = 3600;
    double mps;
    mps= dist/time;
    float kph;
    kph= mps*hour/km;
    return kph;
}

int main()
{
    double dist;
    double time;
    double min,sec;
    cout<<"Обчислення швидкості бігу"<<endl;
    cout<<"Введіть довжину дистанції (метрів) > ";
    cin>>dist;
    cout<<"Введіть час (хвилин.секунд) > ";
    cin>>time;
    sec = modf(time, &min);
    int converted_time = min*60+sec*100;
    cout<<"Дистанція: "<<dist<<endl;
    cout<<"Час: "<<min<<" хвилин "<<sec*100<<" секунд = "<<converted_time<<endl;
    printf("Швидкість бігу: %.2f",speed(dist,converted_time));
    return 0;
}
