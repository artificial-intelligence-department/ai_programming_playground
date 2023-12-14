#include <iostream>
#include <cmath>
using namespace std;
int main()
{

    double Mx, My;
    cout << "Type coordinates of M dot" << endl;
    cin >> Mx >> My;
    double x1, y1, x2, y2, x3, y3;
    cout << "Type coordinates of dot A of the triangle" << endl;
    cin >> x1 >> y1;
    cout << "Type coordinates of dot B of the triangle" << endl;
    cin >> x2 >> y2;
    cout << "Type coordinates of dot C of the triangle" << endl;
    cin >> x3 >> y3;

    double AB, BC, CA;
    AB = pow(((pow((x2 - x1), 2) + pow((y2 - y1), 2))), 0.5);
    BC = pow(((pow((x3 - x2), 2) + pow((y3 - y2), 2))), 0.5);
    CA = pow(((pow((x1 - x3), 2) + pow((y1 - y3), 2))), 0.5);

    double AM, BM, CM;

    AM = pow(((pow((Mx - x1), 2) + pow((My - y1), 2))), 0.5);
    BM = pow(((pow((Mx - x2), 2) + pow((My - y2), 2))), 0.5);
    CM = pow(((pow((Mx - x3), 2) + pow((My - y3), 2))), 0.5);

    double Sabc;
    double p;
    p = ((AB + BC + CA) / 2);
    Sabc = pow(p * (p - AB) * (p - BC) * (p - CA), 0.5);
    Sabc = (int)Sabc;

    double Samb;
    double p1;
    p1 = ((AB + BM + AM) / 2);
    Samb = pow(p1 * (p1 - AB) * (p1 - BM) * (p1 - AM), 0.5);

    double Sbmc;
    double p2;
    p2 = ((BM + CM + BC) / 2);
    Sbmc = pow(p2 * (p2 - BM) * (p2 - CM) * (p2 - BC), 0.5);

    double Scma;
    double p3;
    p3 = ((CM + AM + CA) / 2);
    Scma = pow(p3 * (p3 - CM) * (p3 - AM) * (p3 - CA), 0.5);

    double s;

    s = Samb + Sbmc + Scma;

    s = (int)s;

    if (Sabc == s)
    {

        cout << "true \n";
    }
    else
    {
        cout << "false";
    }
}
