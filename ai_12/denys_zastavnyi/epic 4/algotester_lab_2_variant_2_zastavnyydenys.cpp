#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> r(N);
    for (int i = 0; i < N; ++i)
    {
    cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

   
    r.erase(std::remove(r.begin(), r.end(), a), r.end());
    r.erase(std::remove(r.begin(), r.end(), b), r.end());
    r.erase(std::remove(r.begin(), r.end(), c), r.end());


vector<int> sum_array;
for (int i = 0; i < r.size() - 1; ++i)
{
    if(r.size() == 0||r.size() == 1){
      
        break;
    }
    sum_array.push_back(r[i] + r[i + 1]);
}

 int M = sum_array.size();
cout << M << endl;
for (int i = 0; i < M; ++i)
{
    cout << sum_array[i] << " ";
}

return 0;
}