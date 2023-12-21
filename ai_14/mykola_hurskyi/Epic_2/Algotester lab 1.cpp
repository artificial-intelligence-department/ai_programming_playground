#include <iostream> 
using namespace std; 
int main() 
{ 
    long long array[5]; 
    for (int i = 0; i < 5; i++) 
    {
        cin >> array[i]; 
        if (array[i] <= 0) 
        { 
            cout << "ERROR";      
            exit(0); 
            }        
            else 
            {             
                if ((array[i] > array[i-1]) && i > 0) 
            {                 
                cout << "LOSS";                 
                exit(0); 
            } 
        } 
    }
          
    cout << "WIN"; 
} 
