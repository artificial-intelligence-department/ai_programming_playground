#include <iostream> 
#include <cmath> 

using namespace std;
struct Parameters //14. в коді використано структури
{
    double time;
    double speed;
    int distance;
};

double getParameters(double time, int min){
    double sec=(time-min)*100;
    return sec;
}
double getParameters(int distance, double sec){ //12. в коді використано перевантаження функції 
    double speed=distance/sec*60*60/1000;
    return speed;
}
 
int main() {
    Parameters parameters;
    cout<<"Task 1"<<endl;
    int min;
    double sec; //3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    cout<<"Enter the length of the distance (meters) > "; //21. в коді використано оператори виведення та введення даних
    cin>>parameters.distance;
    cout<<"Enter the time (minutes.seconds) > ";
    cin>>parameters.time;
    cout<<"Distance: "<<parameters.distance<<" m"<<endl;
    min=parameters.time; 
    sec=getParameters(parameters.time, min);
    cout<<"Time: " <<min<<" min "<<sec<<" sec = ";
    sec+=min*60;
    cout<<sec<<" sec"<<endl;
    parameters.speed=getParameters(parameters.distance, sec);
    cout<<"Running speed = "<<round(parameters.speed*100)/100<<" km/hour"<<endl;
    cout<<"Task 2"<<endl;
    double V, r, S;
    double pi = 3.14159;
    cout<<"Enter r: ";
    cin>>r;
    V=pi*pow(r,3)*4/3; 
    S=4*pi*pow(r,2);
    cout<<"V="<<round(V*100)/100<<endl;
    cout<<"S="<<round(S*100)/100;
}    