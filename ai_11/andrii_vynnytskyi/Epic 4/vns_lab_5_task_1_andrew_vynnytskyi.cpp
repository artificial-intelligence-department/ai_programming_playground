#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int max(vector<int> matrix)
{
    int max = 0;
    for(int i = 0; i < matrix.size(); i++)
    {
        if(max < matrix[i])
        {
            max = matrix[i];
        }
    }
    return max;
}


vector<vector<int>> generate_matrix(int size)
{
    vector<vector<int>> matrix;
    for(int i = 0; i < size; i++)
    {
        matrix.emplace_back(size);
        for(int j = 0; j < size; j++)
        {

            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}
void print_matrix(vector<vector<int>> matrix)
{
    for(int i = 0; i < matrix.size(); i++)
    {

        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout<< matrix[i][j]<<" ";
        }
        cout << endl;
    }
}
int sum(vector<vector<int>> matrix)
{
    int sum_n = 0;
    for(int i = 0;i < matrix.size();i++)
    {
        for(int j = 0;j < i;j++) {
            sum_n += matrix[i][j];
        }

    }
    return sum_n;
}



int main()
{

    srand(time(0));
    vector<int> sums;
    int number;
    int size;
    cout<<"Enter number of matrixes: ";
    cin>> number;
    cout <<"Enter size of matrixes: ";
    cin>> size;
    for(int i = 0;i < number;i++)
    {
        vector<vector<int>> matrix = generate_matrix(size);
        cout<<"Number "<< i + 1<< " matrix "<<endl;
        print_matrix(matrix);
        sums.push_back(sum(matrix));
        cout<<"Sum under the diagonal:" <<sum(matrix)<<endl;
    }
    cout<<"Max sum: "<< max(sums);
    return 0;
}
