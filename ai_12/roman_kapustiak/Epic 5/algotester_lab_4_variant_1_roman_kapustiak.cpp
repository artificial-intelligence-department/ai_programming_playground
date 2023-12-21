#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>::iterator s_difference(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first);
vector<int>::iterator s_intersection(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first);
vector<int>::iterator s_union(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first);
vector<int>::iterator s_symmetric_difference(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first);

int main()
{
    int N, M;

    cin >> N;

    int arrN[N];

    for(int i = 0; i < N; i++)
    {
        cin >> arrN[i];
    }

    cin >> M;

    int arrM[M];

    for(int i = 0; i < M; i++)
    {
        cin >> arrM[i];
    }

    vector<int> v(N+M);
    vector<int>::iterator it;

    sort(arrN, arrN + N);
    sort(arrM, arrM + M);

    // difference N-M
    // it = set_difference(arrN, arrN + N, arrM, arrM + M, v.begin());
    it = s_difference(arrN, arrN + N, arrM, arrM + M, v.begin());
    v.resize(it-v.begin());

    cout << v.size() << endl;
    for (it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << "\n\n";

    // difference M-N
    v.resize(N+M);
    // it = set_difference(arrM, arrM + M, arrN, arrN + N, v.begin());
    it = s_difference(arrM, arrM + M, arrN, arrN + N, v.begin());
    v.resize(it-v.begin());

    cout << v.size() << endl;
    for (it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << "\n\n";    

    // intersection
    v.resize(N+M);
    // it = set_intersection(arrM, arrM + M, arrN, arrN + N, v.begin());
    it = s_intersection(arrM, arrM + M, arrN, arrN + N, v.begin());
    v.resize(it-v.begin());

    cout << v.size() << endl;
    for (it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << "\n\n";

    // union
    v.resize(N+M);
    // it = set_union(arrM, arrM + M, arrN, arrN + N, v.begin());
    it = s_union(arrM, arrM + M, arrN, arrN + N, v.begin());
    v.resize(it-v.begin());

    cout << v.size() << endl;
    for (it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << "\n\n";

    // symmetric difference
    v.resize(N+M);
    // it = set_symmetric_difference(arrM, arrM + M, arrN, arrN + N, v.begin());
    it = s_symmetric_difference(arrM, arrM + M, arrN, arrN + N, v.begin());
    v.resize(it-v.begin());

    cout << v.size() << endl;
    for (it=v.begin(); it != v.end(); it++)
        cout << *it << ' ';

    return 0;
}
vector<int>::iterator s_difference(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first)
{
    while (first1 != last1)
    {
        if (first2 == last2)
            return copy(first1, last1, d_first);
 
        if (*first1 < *first2)
            *d_first++ = *first1++;
        else
        {
            if (! (*first2 < *first1))
                ++first1;
            ++first2;
        }
    }

    return d_first;
}
vector<int>::iterator s_intersection(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first)
{
    while (first1 != last1 && first2 != last2)
    {
        if (*first1 < *first2)
            ++first1;
        else
        {
            if (!(*first2 < *first1))
                *d_first++ = *first1++; // *first1 and *first2 are equivalent.
            ++first2;
        }
    }
    return d_first;
}
vector<int>::iterator s_union(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first)
{
    for (; first1 != last1; ++d_first)
    {
        if (first2 == last2)
            return copy(first1, last1, d_first);
 
        if (*first2 < *first1)
            *d_first = *first2++;
        else
        {
            *d_first = *first1;
            if (!(*first1 < *first2))
                ++first2;
            ++first1;
        }
    }
    return copy(first2, last2, d_first);
}
vector<int>::iterator s_symmetric_difference(int *first1, int *last1, int *first2, int *last2, vector<int>::iterator d_first)
{
    while (first1 != last1)
    {
        if (first2 == last2)
            return copy(first1, last1, d_first);
 
        if (*first1 < *first2)
            *d_first++ = *first1++;
        else
        {
            if (*first2 < *first1)
                *d_first++ = *first2;
            else
                ++first1;
            ++first2;
        }
    }
    return copy(first2, last2, d_first);
}
