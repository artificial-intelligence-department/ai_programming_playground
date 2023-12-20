# include <iostream>
using namespace std;

int main (){

    int N, M;
    cin >> N >> M;
    char arr[N][M];


    for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cin >> arr[i][j];
            }
        }

    for(int i = N-1; i >= 0; i--)
        {
            for(int j = 0; j < M; j++){
                if(arr[i][j]=='O'){
                    for (int k=i; k>= 0; k--){
                        if (arr[k][j]=='S'){
                            arr [i][j]='S';
                            arr [k][j]='O';
                            break;
                        }
                        else if (arr[k][j]=='X'){
                            break;
                        }
                    }
                }
            }
        }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << arr[i][j];
        }
       cout <<  endl;      
    }
    return 0;
}
