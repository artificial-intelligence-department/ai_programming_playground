#include <iostream>
#include <vector>

using namespace std;

int main() {
    long N, a, b, c;
    cin >> N;

    vector<long> r(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> r[i];
    }

    cin >> a >> b >> c;

    vector<long> newVector;
    bool elementToDeletePresent = false;

    for (int i = 0; i < N; i++) 
    {
        if (r[i] == a || r[i] == b || r[i] == c) 
        {
            elementToDeletePresent = true;
        } 
        else 
        {
            newVector.push_back(r[i]);
        }
    }

    long M = newVector.size();
    if (M <= 1) 
    {
        cout << 0;
    } 
    else 
    {
        cout << M - 1 << endl;

        if (M > 1) {
            vector<long> sum;
            if (M - 1 > 0) 
            {
                sum.resize(M - 1);
                for (int i = 0; i < M - 1; i++) 
                {
                    sum[i] = newVector[i] + newVector[i + 1];
                }
            }

            for (int i = 0; i < M - 1; i++) 
            {
                cout << sum[i] << " ";
            }
        }
    }

    return 0;
}
