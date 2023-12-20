#include <iostream>
#include<algorithm>
#include <vector>

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

vector<int> set_diff(vector<int>& vector_1, vector<int>& vector_2)
{
    vector<int> diff_result;
    for (int i = 0; i < vector_1.size(); i++)
    {
        bool found = false;
        for (int y = 0; y < vector_2.size(); y++)
        {
            if (vector_1[i] == vector_2[y])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            diff_result.push_back(vector_1[i]);
        }
    }
    return diff_result;
}

vector<int> set_intersection(vector<int>& vector_1, vector<int>& vector_2)
{
    vector<int> intersection_result;
    for (int i = 0; i < vector_1.size(); i++)
    {
        for (int y = 0; y < vector_2.size(); y++)
        {
            if (vector_1[i] == vector_2[y])
            {
                intersection_result.push_back(vector_1[i]);
                break;
            }
        }
    }
    return intersection_result;
}

vector<int> set_union(vector<int>& vector_1, vector<int>& vector_2)
{
    vector<int> union_result = vector_1;
    for (int i = 0; i < vector_2.size(); i++)
    {
        bool found = false;
        for (int y = 0; y < union_result.size(); y++)
        {
            if (vector_2[i] == union_result[y]) 
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            union_result.push_back(vector_2[i]);
        }
    }
    return union_result;
}
    
vector<int> set_symm_diff(vector<int>& vector_1, vector<int>& vector_2)
{
    vector<int> symm_diff_result;
    for (int i = 0; i < vector_1.size(); i++)
    {
        bool found = false;
        for (int y = 0; y < vector_2.size(); y++)
        {
            if (vector_1[i] == vector_2[y]) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            symm_diff_result.push_back(vector_1[i]);
        }
    }
    for (int i = 0; i < vector_2.size(); i++)
    {
        bool found = false;
        for (int y = 0; y < vector_1.size(); y++)
        {
            if (vector_2[i] == vector_1[y]) 
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            symm_diff_result.push_back(vector_2[i]);
        }
    }
    return symm_diff_result;
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

    N_M_diff_result = set_diff(vector_N, vector_M);
    M_N_diff_result = set_diff(vector_M, vector_N);
    intersection_result = set_intersection(vector_N, vector_M);
    union_result = set_union(vector_N, vector_M);
    symm_diff_result = set_symm_diff(vector_N, vector_M);

    print_result(N_M_diff_result);
    print_result(M_N_diff_result);
    print_result(intersection_result);
    print_result(union_result);
    print_result(symm_diff_result);
}