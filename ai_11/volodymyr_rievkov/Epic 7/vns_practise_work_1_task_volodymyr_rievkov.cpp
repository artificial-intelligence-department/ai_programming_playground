#include<iostream>
#include<cmath>
using namespace std;

struct Side
{
    double a;
    double b;
    double c;
};

bool is_sides_right(Side s)
{
    if ((s.a + s.b > s.c) && (s.a + s.c > s.b) && (s.b + s.c > s.a)) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

double find_triangle_height(Side s, double side)
{
    double p = (s.a + s.b + s.c) / 2;
    double area = sqrt(p * (p - s.a) * (p - s.b) * (p - s.c));
    return (2 * area) / side;
}

int main()
{
    Side s;
    s.a = 5;
    s.b = 13; 
    s.c = 15;
    if(is_sides_right(s))
    {
        cout << "Height of a: " << find_triangle_height(s, s.a) << endl;
        cout << "Height of b: " << find_triangle_height(s, s.b) << endl;
        cout << "Height of c: " << find_triangle_height(s, s.c) << endl;
    }
    else
    {
        cout << "Error: Wrong side length" << endl;
    }
}