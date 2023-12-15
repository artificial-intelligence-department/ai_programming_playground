#include <iostream>
using namespace std;


int main() {

long long H;
long long M;

cin >> H >> M;

for (int i = 0; i < 3; i++ )

{
    long long h, m;
    cin >> h >> m;
    if (m != 0 && h != 0)
    {
        cout << endl << "NO";
        return 0;
    }
    H -= h;
    M -= m;
}
if (M <= 0 || H <= 0 )
{
    cout << endl << "NO";

}
else {

    cout << endl << "YES";

}
return 0;
}
