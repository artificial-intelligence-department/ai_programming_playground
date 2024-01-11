#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, M;

    cin >> N;
    vector<int> array_1(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> array_1[i];
    }

    cin >> M;
    vector<int> array_2(M);

    for (int i = 0; i < M; ++i) 
    {
        cin >> array_2[i];
    }

     std::sort(array_1.begin(), array_1.end());
      std::sort(array_2.begin(), array_2.end());

    vector<int> difference_N;

    set_difference(array_1.begin(), array_1.end(), array_2.begin(), array_2.end(), back_inserter(difference_N));
    cout << difference_N.size() << endl;
    for (int i = 0; i < difference_N.size(); ++i) 
    {
        cout << difference_N[i] << " ";
    }
    cout << endl;

    vector<int> difference_M;

    set_difference(array_2.begin(), array_2.end(), array_1.begin(), array_1.end(), back_inserter(difference_M));
    cout << difference_M.size() << endl;
    for (int i = 0; i < difference_M.size(); ++i) 
    {
        cout << difference_M[i] << " ";
    }
    cout << endl;

    vector<int> intersection;

    set_intersection(array_1.begin(), array_1.end(), array_2.begin(), array_2.end(), back_inserter(intersection));
    cout << intersection.size() << endl;
    for (int i = 0; i < intersection.size(); ++i) 
    {
        cout << intersection[i] << " ";
    }
    cout << endl;

    vector<int> unionise;

    set_union(array_1.begin(), array_1.end(), array_2.begin(), array_2.end(), back_inserter(unionise));
    cout << unionise.size() << endl;
    for (int i = 0; i < unionise.size(); ++i) 
    {
        cout << unionise[i] << " ";
    }
    cout << endl;

    vector<int> symmetric_difference;

    set_symmetric_difference(array_1.begin(), array_1.end(), array_2.begin(), array_2.end(), back_inserter(symmetric_difference));
    cout << symmetric_difference.size() << endl;
    for (int i = 0; i < symmetric_difference.size(); ++i) 
    {
        cout << symmetric_difference[i] << " ";
    }
    cout << endl;

    return 0;
}