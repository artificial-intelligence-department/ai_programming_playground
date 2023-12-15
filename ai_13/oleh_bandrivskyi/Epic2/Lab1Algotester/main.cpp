#include <iostream>

#define LOSE std::cout << "NO"; return 0
#define WIN std::cout << "YES"; return 0

int main()
{
    long long H, M;
    std::cin >> H >> M;
    bool win = true;

    for(int i = 0; i < 3; i++)
    {
        long long h, m;
        std::cin >> h >> m;

        if(h == 0 ^ m == 0)
        {
            H -= h; 
            M -= m;
            
              
            if(H <= 0 || M <= 0)
                win = false;
        }
        
        else if(h == 0 && m == 0)
            continue;
        else
            win = false;
    }
    
    if(win) {WIN;}
    if(!win) {LOSE;}
}