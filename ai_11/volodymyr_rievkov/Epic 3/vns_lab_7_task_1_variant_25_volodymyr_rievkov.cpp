#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct  point
{
    int x;
    int y;
};

double get_length_by_points(point A, point B)
{
    return sqrt(pow(B.x- A.x, 2) + pow(B.y - A.y, 2));
}

void print_length_by_point(point A, point B)
{
    cout << "Length between points (" << A.x << ", " << A.y << "), (" << B.x << ", " << B.y << ") = " << get_length_by_points(A, B) << endl;
}

double get_triangle_square_by_points(point A, point B, point C)
{
    double a = get_length_by_points(A, B);
    double b = get_length_by_points(A, C);
    double c = get_length_by_points(B, C);
    double half_perimeter = (a + b + c)/2;
    return sqrt(half_perimeter * (half_perimeter - a) * (half_perimeter - b) * (half_perimeter - c));
}

void print_triangle_square_by_points(point A, point B, point C)
{
    cout << "Square of triangle on points (" << A.x << ", " << A.y << "), (" << B.x << ", " << B.y << "), (" << C.x << ", " << C.y << ") = " << get_triangle_square_by_points(A, B, C) << endl;
}

double get_triangle_square_by_max_diagonal(vector<point>points)
{
    int size = points.size();
    point A, B, C;
    double max_diagonal = 0;
    for(int i = 0; i < size; i++)
    {
        for(int y = 0; y < size; y++)
        {
            double length = get_length_by_points(points[i], points[y]);
            if(length > max_diagonal)
            {
                max_diagonal = length;
                A = points[i];
                B = points[y - 1];
                C = points[y];
            }
        }
    }
    return get_triangle_square_by_points(A, B, C);
}

void print_triangle_square_by_max_diagonal(vector<point>points)
{
    cout << "Square of triangle by max diagonal on points ";
    for(int i = 0; i < points.size(); i++)
    {
        cout << "(" << points[i].x << ", " << points[i].y << ")";
        if(i != points.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << " = " << get_triangle_square_by_max_diagonal(points) << endl;
}

int main()
{
    point A, B, C, D, E, F;
    A.x = 0, A.y = 0;
    B.x = 1, B.y = 0;
    C.x = 2, C.y = 1;
    D.x = 1, D.y = 2;
    E.x = 0, E.y = 2;
    F.x = -1, F.y = 1;
    print_length_by_point(A, B);
    print_triangle_square_by_points(C, D, E);
    print_triangle_square_by_max_diagonal({A, B, C, D, E, F});
}