#include<iostream>
#include<cmath>
using namespace std;

void set_distance(double &distance)
{
    cout << "Enter distance: ";
    cin >> distance;
}

void convert_time_to_seconds(double &time)
{
    int minutes = time;
    double after_point = time - minutes;
    string after_point_s = to_string(after_point);
    int length = after_point_s.length();
    string seconds_s;
    int i;
    for(i = 2; i < length - 1; i++)
    {
        seconds_s += after_point_s[i];
    }
    length = seconds_s.length();
    for(i = length - 1; i > 0; i--)
    {
        if(seconds_s[i] != '0')
        {
            break;
        }
        else
        {
            seconds_s.erase(i, 1);
        }
    }
    time = (minutes * 60) + stod(seconds_s);
}

void set_time(double &time)
{
    cout << "Enter time: ";
    cin >> time;
    convert_time_to_seconds(time);
}

double calculate_velocity(double &distance, double &time)
{
    return (distance / 1000) / (time / 60 / 60);
}

void set_radius(double &radius)
{
    cout << "Enter radius: ";
    cin >> radius;
}

double calculate_volume(double & radius)
{
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double calculate_square(double &radius)
{
    return 4.0 * M_PI * pow(radius, 2);
}

int main()
{
    double distance;
    double time;
    set_distance(distance);
    set_time(time);
    cout << " - Distance: " << distance << " m" << endl << " - Time: " << time << " s" << endl << " - Velocity: " << calculate_velocity(distance, time) << " km/h" << endl;
    double radius;
    set_radius(radius);
    cout << "Volume of sphere with radius '" << radius << "': " << calculate_volume(radius) << endl; 
    cout << "Square of sphere with radius '" << radius << "': " << calculate_square(radius) << endl; 
}






