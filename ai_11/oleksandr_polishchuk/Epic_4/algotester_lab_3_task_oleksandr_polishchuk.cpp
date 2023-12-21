#include <iostream>
#include <vector>

using namespace std;

int main()
{   
    int N, M, common=0, unique=0;
    
    cin >> N;
    int arr1[N];
    for (int i=0; i<N; i++)
    {
        cin >> arr1[i];
    }
    cin >> M;
    int arr2[M];
    for (int k=0; k<M; k++)
    {
        cin >> arr2[k];
    }
        
         for (int x=0; x<N; x++)
            {   
                for(int r=0; r<M; r++)
                {   
                    if (arr1[x]==arr2[r])
                    {
                        common++;
                        
                    }
                }   

            }
    vector <int> sum;
    for (int e=0; e<N; e++)
    {
        sum.push_back(arr1[e]);
    }
    for (int g = 0; g < M; g++)
    {
        bool isUnique = true;
        for (int x = 0; x < N; x++)
        {
            if (arr2[g] == arr1[x])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            sum.push_back(arr2[g]);
        }
    }
    unique=sum.size();
    cout << "\n"<< common << "\n" << unique;
    return 0;
}

