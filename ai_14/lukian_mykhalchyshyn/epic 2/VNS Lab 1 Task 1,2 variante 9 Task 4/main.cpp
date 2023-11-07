#include <iostream>

using namespace std;

int main()
{
    int m, n, s;
    cout << "Введіть значення m та n\n";
    cin >> m >> n;

    s = ++n * ++m;
    cout << "s = " << s << endl;

    if (m++ < n)
    {
        cout << "m++ <n: " << true << endl;
    }
    else
        cout << "m++ <n: " << false << endl;

    if (n++ > m)
    {
        cout << "n++ > m: " << true << endl;
    }
    else
    {
        cout << "n++ > m: " << false << endl;
    }

    return 0;
}