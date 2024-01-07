#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int N, Q, i, j, x, y;
    int count = 0;
    int iter = 0;
    cin>>N;
    vector<vector<char>> field (N,vector<char>(N));
    

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cin>>field[i][j];
            }
        }
        cin>>Q;
        
    vector<int> coordinates(2*Q);
    
        for(auto &&coord : coordinates)
            cin>>coord;

    while(Q--){
    x = coordinates[iter]-1;
    y = coordinates[iter+1]-1;
        if(field[x][y]!='0'){
            cout<<1<<"\n"<<field[x][y]<<"\n"<<"\n";
            iter+=2;
            continue;
        }
        vector<int> options;
        for(i=1;i<=N;i++)
            options.push_back(i);
        
    
        for(i=0;i<N;i++){
            if(field[x][i]!='0'){
                for(j=0;j<N;j++){
                    if(field[x][i]-48==options[j])
                        options[j]=0;
                }
            }
        }

        for(i=0;i<N;i++){
            if(field[i][y]!='0'){
                for(j=0;j<N;j++){
                    if(field[i][y]-48==options[j])
                        options[j]=0;
                }
            }
        }

        for(i=0;i<N;i++){
            if(options[i]!=0)
                count++;
        }
        if(count==0){
            cout<<0<<"\n";
            iter +=2;
            continue;
        }
        cout<< count<< "\n";
        count = 0;
        for(i=0;i<N;i++){
            if(options[i]!=0)
                cout<<options[i]<<" ";
        }
        cout<<"\n"<<"\n";
        iter += 2;
    }

    return 0;
}
