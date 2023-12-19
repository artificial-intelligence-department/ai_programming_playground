#include <iostream>
#include <string>

using namespace std;

float dujm = 2.54; // metres
float fut = dujm * 12.0;
float yard = fut * 3.0;
float length = 110; // yards

// surname: Vyklyuk

int main()
{
    double shyryna_letters = 3 * 0.8; // metres
    double surname = shyryna_letters * 7;
    float field = length * yard * 100;
    float field0 = field;

    int a = field / 7;
    string sur = "vyklyuk";

    string name;
    int i = 0;

    while (field != 0)
    {
        for (int j = 0; j < 7; ++j)
        {
            name += sur[j];
            field--;
        }
    }

    // Reset field to its original value
    field = field0;

    // Calculate the center index
    int index_centre = (field0 / sur.length()) - 1;

    // Print the 3 characters around the center index
    for (int i = 0; i < 3; ++i)
    {
        cout << sur[index_centre + i];
    }

    return 0;
}
