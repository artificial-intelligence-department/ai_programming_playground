#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/*
У вас є дорога, яка виглядає як N чисел.
Після того як ви по ній пройдете - вашу втому можна визначити як різницю максимального та мінімального елементу.
Ви хочете мінімізувати втому, але все що ви можете зробити - викинути одне число з дороги, тобто забрати його з масиву.
В результаті цієї дії, яку мінімальну втому ви можете отримати в кінці дороги?
*/

int main() {
    int N;
    cin >> N;
    vector<int> r(N);
    int Min = 1;
    int Max = pow(10 , 5);
    if (Min <= N && N <= Max) {
        for (int i = 0; i < N; i++) {
            cin >> r[i];
        }
        sort(r.begin(), r.end());
        int m = min(r[N-1] - r[1], r[N-2] - r[0]);
        cout << m << endl;
    } else {
        return 1;
}
}