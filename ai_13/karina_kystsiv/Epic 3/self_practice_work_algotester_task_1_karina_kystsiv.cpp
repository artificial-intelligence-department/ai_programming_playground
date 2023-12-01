#include <iostream>
using namespace std;

int main()
{
    int rockM = 0, pprM = 0, scrsM = 0; 
    cin >> rockM >> scrsM >> pprM;

    int rockZ = 0, pprZ = 0, scrsZ = 0; 
    cin >> rockZ >> scrsZ >> pprZ;

    int win = 0;
    while (rockM > 0 && scrsZ > 0) {
        win++;
        rockM--; scrsZ--;
    }
    while (pprM > 0 && rockZ > 0) {
        win++;
        pprM--; rockZ--;
    }
    while (scrsM > 0 && pprZ > 0) {
        win++;
        scrsM--; pprZ--;
    }
    cout <<  win;
    return 0;
}
