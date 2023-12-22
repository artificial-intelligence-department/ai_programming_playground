#include <iostream>
#include <cmath>
using namespace std;

int main()
{
double sd, su, v, td, tu;

    cin>>sd>>su>>v; //Відстань до першої та другої локацій, звичайна швидківсть геймерів
    if (sd<0 || sd>pow(10, 5) || su<0 || su>pow(10, 5) || v<0 || v>pow(10, 5))
    {
        return 0;
    }
    td = sd / (2 * v);
    tu = su / (v / 2);

    if(tu<td)
    {
        cout<<"Up";
    }
    else if(td<tu)
    {
        cout<<"Down";
    }
    else
    {
        cout<<"Never mind";
    }

return 0;
}