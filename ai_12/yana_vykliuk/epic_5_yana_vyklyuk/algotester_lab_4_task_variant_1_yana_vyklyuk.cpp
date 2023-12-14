#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M, number_n, number_m;
    vector <int> n;
    vector <int> m;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> number_n;
        n.push_back(number_n);
    }

    cin >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> number_m;
        m.push_back(number_m);
    }

    sort(n.begin(), n.end());
    sort(m.begin(), m.end());

    vector <int> difference1;

    set_difference(n.begin(), n.end(), m.begin(), m.end(), inserter(difference1, difference1.begin()));

    cout << difference1.size() << endl;
    for(int i = 0; i < difference1.size(); i++)
    {
        cout << difference1[i] << " ";
    }
    cout << endl << "\n";

    vector <int> difference2;

    set_difference(m.begin(), m.end(), n.begin(), n.end(), inserter(difference2, difference2.begin()));

    cout << difference2.size() << endl;
    for(int i = 0; i < difference2.size(); i++)
    {
        cout << difference2[i] << " ";
    }
    cout << endl << "\n";


    vector <int> crossing;

    set_intersection(n.begin(), n.end(), m.begin(), m.end(), inserter(crossing, crossing.begin()));

    cout << crossing.size() << endl;
    for(int i = 0; i < crossing.size(); i++)
    {
        cout << crossing[i] << " ";
    }
    cout << endl << "\n";


    vector <int> unification;

    set_union(n.begin(), n.end(), m.begin(), m.end(), inserter(unification, unification.begin()));

    cout << unification.size() << endl;
    for(int i = 0; i < unification.size(); i++)
    {
        cout << unification[i] << " ";
    }
    cout << endl << "\n";

    
    vector <int> symmetric;

    set_symmetric_difference(n.begin(), n.end(), m.begin(), m.end(), inserter(symmetric, symmetric.begin()));

    cout << symmetric.size() << endl;
    for(int i = 0; i < symmetric.size(); i++)
    {
        cout << symmetric[i] << " ";
    }
    cout << endl << "\n";


    return 0;

}
