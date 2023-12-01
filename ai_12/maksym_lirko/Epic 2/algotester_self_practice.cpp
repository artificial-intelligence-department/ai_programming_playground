#include<iostream>
using namespace std;

int main() {
    int n, sum=0;
    cin >> n;  
    
         int bills[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++) {
       while(n>0){
        sum += 1;
        if (n>=bills[0])
       {
        n-=bills[0];
       }
       else if(n>=bills[1])
       {
            n-=bills[1];
        }
        else if(n>=bills[2])
        {
            n-=bills[2];
        }        
        else if(n>=bills[3])
        {
            n-=bills[3];
        }
        else if(n>=bills[4])
        {
            n-=bills[4];
        }
        else if(n>=bills[5])
        {
            n-=bills[5];
        }
        else if(n>=bills[6])
        {
            n-=bills[6];
        }
        else if(n>=bills[7])
        {
            n-=bills[7];
        }
        else if(n>=bills[8])
        {
            n-=bills[8];
        }
    }
    }

    cout <<sum << endl;
    return 0;
}
