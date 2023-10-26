#include <iostream>
#include <string>
using namespace std;

int main()
{
    double vnesok;
    double time;
    double rate, suma;
    cout << "Please enter deposit ";
    cin >> vnesok;
    suma = vnesok;
    cout << "Please enter years ";
    cin >> time;
    cout << "Please enter rate ";
    cin >> rate;
    string name;
    cout << "Enter your mane ";
    cin >> name;
    for(int i = 0; i< time; i++)
    {
        suma = suma + (suma/100 * rate );
    }
    printf ("Hi %s your summa = %f", name.c_str(), suma); 




    return 0;
}
