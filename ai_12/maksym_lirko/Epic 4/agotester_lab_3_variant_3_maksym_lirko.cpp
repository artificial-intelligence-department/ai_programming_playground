#include<iostream>
using namespace std;

int main()
{
    string S;
    int compressedS;

    cin>>S;

    int sizeS = S.length();
    if (sizeS == 1)
    {
        cout<<S;
        return 0;
    }
    
    compressedS=1;
    
    for (int i = 0; i < sizeS; i++)
    {
        if (S[i]==S[i+1])
        {
            compressedS++;
        }  
        else if(compressedS<=1)
        {
            cout<<S[i];
        }
        else if (compressedS>1)
        {
            cout<<S[i]<<compressedS;
            compressedS=1;
        }
    }
    


    return 0;
}