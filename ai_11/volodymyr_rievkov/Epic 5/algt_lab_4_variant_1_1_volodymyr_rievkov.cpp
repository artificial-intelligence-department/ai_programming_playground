#include <iostream>
#include <vector>
#include <algorithm>
#include<iterator>

using namespace std;

vector<int> N_M_diff_result;
vector<int> M_N_diff_result;
vector<int> intersection_result;
vector<int> union_result;
vector<int> symm_diff_result;

bool is_number_okay(int number)
{
    return (number >= 1 && number <= 100);
}

bool is_vector_okay(vector<int>& vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        if (!is_number_okay(vector[i]))
        {
            return false;
        }
    }
    return true;
}

void fill_vector(vector<int>& vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cin >> vector[i];
    }
}

void print_result(vector<int>& result)
{
    int vector_size = result.size();
    cout << vector_size << endl;
    for (int i = 0; i < vector_size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;
    if (!is_number_okay(N))
    {
        return 0;
    }
    vector<int> vector_N(N);
    fill_vector(vector_N);
    if (!is_vector_okay(vector_N))
    {
        return 0;
    }
    int M;
    cin >> M;
    if (!is_number_okay(M))
    {
        return 0;
    }
    vector<int> vector_M(M);
    fill_vector(vector_M);
    if (!is_vector_okay(vector_M))
    {
        return 0;
    }
    sort(vector_N.begin(), vector_N.end());
    sort(vector_M.begin(), vector_M.end());
    set_difference(vector_N.begin(), vector_N.end(), vector_M.begin(), vector_M.end(), back_inserter(N_M_diff_result));
    set_difference(vector_M.begin(), vector_M.end(), vector_N.begin(), vector_N.end(), back_inserter(M_N_diff_result));
    set_intersection(vector_N.begin(), vector_N.end(), vector_M.begin(), vector_M.end(), back_inserter(intersection_result));
    set_union(vector_N.begin(), vector_N.end(), vector_M.begin(), vector_M.end(), back_inserter(union_result));
    set_symmetric_difference(vector_N.begin(), vector_N.end(), vector_M.begin(), vector_M.end(), back_inserter(symm_diff_result));
    print_result(N_M_diff_result);
    print_result(M_N_diff_result);
    print_result(intersection_result);
    print_result(union_result);
    print_result(symm_diff_result);
}