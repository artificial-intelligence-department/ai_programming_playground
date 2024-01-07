//vns 3 task 2 variant 7
#include <iostream>
using namespace std;

int main()
{
    // Ініціалізація змінних для розмірів коробки та кількості болтів
    double height = 0.0, width = 0.0, depth = 0.0;
    int bolts = 0;
    const double BOLT_VOLUME = 0.000002; // Об'єм одного болта

    // Введення висоти, ширини та глибини коробки
    cout<<"Enter the height of the box (m): "<<endl;
    cin>>height;

    cout<<"Enter the width of the box (m): "<<endl;
    cin>>width;

    cout<<"Enter the depth of the box (m): "<<endl;
    cin>>depth;
    // Розрахунок об'єму коробки
    double boxVolume = height*width*depth;

    // Розрахунок кількості болтів, які помістяться в коробці
    bolts = boxVolume/BOLT_VOLUME;
    cout<<"The amount of bolts in the box is "<<bolts<<endl;

    return 0;
}
