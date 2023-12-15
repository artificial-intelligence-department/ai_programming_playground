#include <iostream>
#include <vector>

using namespace std;

void sort_vector(vector<int> &vector, int size);
void remove_duplicates(vector<int> &vector, int &size);
void rotate_vector(vector<int> &vector, int size, int k);

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    sort_vector(array, n);
    remove_duplicates(array, n);

    cout << n << endl;
    rotate_vector(array, n , k);

    return 0;
}

void sort_vector(vector<int> &vector, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
            
        }
    }
}

void remove_duplicates(vector<int> &vector, int &size)
{
    int counter = 0;

    for(int i = 0; i < size; i++)
    {
        if(counter == 0 || vector[i] != vector[counter - 1])
        {
            vector[counter++] = vector[i];
            
        }
    }
    size = counter;
}

void rotate_vector(vector<int> &vector, int size, int k)
{
    k %= size;
    
    for (int i = k; i < size; i++)
    {
        cout << vector[i] << " ";
    }

    for(int i = 0; i < k; i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}