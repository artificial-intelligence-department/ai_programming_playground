#include <iostream> // Використовую директиву include, щоб використати cout та cin із  заголовкового файлу <iostream>
#include <cmath>// Використовую директиву include, для використання pow,sin,cos,atan із  заголовкового файлу <cmath>
using namespace std;//Використовую простір імен std
int main(){
    //оголошення й ініціалізація змінних типу double
    double x=0.25;  
    double y=0.79;
    double z=0.81;
    //Використання додаткових змінних, для зручності обчислень 
    double numerator=1+(pow(sin(x+1),2));  
    double module=abs(x-((2*pow(x,3))/(1+pow(x,2)*pow(y,3))));
    double denumerator= 2+ module;
    double P= (numerator/denumerator) + pow(x,4); 
    double arctang= atan(1/z);
    double Q= pow(cos(arctang),2);
    // Вивід результатів
    cout<<"Result of calculating P expression : "<<P<<endl;
    cout<<"Result of calculating Q expression : "<<Q<<endl;

    return 0;
}