#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <vector>

using namespace std;

int main()
{
    srand(time(0)); 
    
    int sad = 10;
    vector<int> love(sad);
    
    cout<<"Original array:\n ";
    for (int i=0; i < sad; ++i)
    {
        love[i] = rand() % 10;
        cout<<i + 1<<"-й елемент: "<<love[i]<<endl;
        
	}
	for (int i = 0; i < sad; ++i){
	    if (love[i] % 7 == 0){
	        love.erase(love.begin() + i);
            --sad;
            --i;
	   }
	}
    
    for (int i = 0; i < sad + 1; ++i)
    {

        if (love[i] % 2 != 0)
        {
            love.insert(love.begin() + i + 1, 0);
            ++sad; 
            ++i;  
        }
    }

    cout << "Масив після модифікацій:" << endl;
    for (int i = 0; i < sad; ++i)
    {
        cout << i + 1 << "-й елемент: " << love[i] << endl;
    }

    return 0;
}