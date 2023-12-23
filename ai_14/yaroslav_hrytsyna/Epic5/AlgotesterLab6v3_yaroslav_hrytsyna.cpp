#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;

int main()
{

    cin >> N;
    int grid[N][N];
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < N; j++){
           grid[i][j]=temp[j] - '0';
        }
    }
    int Q;
    cin >> Q;
    int k[Q][2];
    for (int i = 0; i < Q; i++)
    {
        cin >> k[i][0];
        cin >> k[i][1];
        k[i][0]--, k[i][1]--;
    }
    
    for(int i = 0; i < Q; i++)
    {
        int nums[N];
        for(int i = 0; i < N; i++){
            nums[i]=(i+1);
        }
        int c=N;
        if (grid[k[i][0]][k[i][1]] != 0)
        {
            cout << '1' << endl;
            cout << grid[k[i][0]][k[i][1]] << endl<<endl;
            continue;
        }
        for (int j = 0; j < N; ++j) {
            int f=0;
            if (grid[k[i][0]][j] != 0  && nums[grid[k[i][0]][j]-1]!=0) {
                nums[grid[k[i][0]][j]-1]=0;
                c--;
            }
            if (grid[j][k[i][1]] != 0 && nums[grid[j][k[i][1]]-1]!=0){
                nums[grid[j][k[i][1]]-1]=0;
                if (grid[j][k[i][1]]!=grid[k[i][0]][j]){
                    c--;
                }
            }
        }
        if (c>0){
            cout <<c << endl;
            for (int j = 0; j < N; j++) {
            if (nums[j]!=0){
                cout << j+1 << " ";
            }
        }
        }
        else{
            cout <<0 << endl;
        }
        
        cout << endl;
        cout << endl;
    }

}

