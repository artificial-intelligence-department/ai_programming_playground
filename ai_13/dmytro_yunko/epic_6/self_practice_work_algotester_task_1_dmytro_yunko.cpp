#include <iostream>
#include <vector>
using namespace std;




    struct G
    {
        int team;
        
        vector <int> neighbour;
    };
    
    bool dfs(int v, int team, vector<G>& teamAr) {
        teamAr[v].team = team;
        for (int u : teamAr[v].neighbour) {
            if (teamAr[u-1].team == 0 && !dfs(u-1, 3 - team, teamAr)) {
                return false;
            } else if (teamAr[u-1].team == team) {
                return false;
            }
        }
        return true;
    }
    
    
    


int main(int argc, char const *argv[])
{
    int friendsNum {0};
    int pairsNum {0};
    cin >> friendsNum >> pairsNum;
    if(friendsNum < 1 || friendsNum > 100000){
        
        cout << "Impossible" << endl;
        return 0;
    }
    if(pairsNum < 1 || pairsNum > 100000){
      
        
        cout << "Impossible" << endl;
       return 0;
    }
    
    
    vector<G> teamAr(friendsNum);
    
    for(size_t i=0;i<pairsNum;i++) {
        int a{0};
        int b{0};
        cin >>a >>b;
        if(a==b || a<1||b<1|| a>friendsNum|| b>friendsNum )
        {
          cout << "Impossible" << endl;
                return 0;  
        }
        teamAr[a-1].neighbour.push_back(b);
        teamAr[b-1].neighbour.push_back(a);
        
    }
     for (int i = 0; i < friendsNum; i++) {
        if (teamAr[i].team == 0 && !dfs(i, 1, teamAr)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
     for(int i=0; i<friendsNum; i++)
            cout << teamAr[i].team;
    
    

    return 0;
}
