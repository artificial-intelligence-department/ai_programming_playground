#include <iostream> 
#include <cmath> 

using namespace std; 
int main() {
    cout<<"Task 1"<<endl;
    int min, distance;
    double sec, time, speed;
    cout<<"Enter the length of the distance (meters) > ";
    cin>>distance;
    cout<<"Enter the time (minutes.seconds) > ";
    cin>>time;
    cout<<"Distance: "<<distance<<" m"<<endl;
    min=time; // since min is an integer value, only the number of minutes is remembered when accepting a value time
    sec=(time-min)*100;
    cout<<"Time: " <<min<<" min "<<sec<<" sec = ";
    sec+=min*60;
    cout<<sec<<" sec"<<endl;
    speed=distance/sec*60*60/1000;
    cout<<"Running speed = "<<round(speed*100)/100<<" km/hour"<<endl;
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