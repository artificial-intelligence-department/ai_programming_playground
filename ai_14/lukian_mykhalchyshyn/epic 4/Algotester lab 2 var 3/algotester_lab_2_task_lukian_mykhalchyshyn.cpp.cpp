	#include <iostream>
	#include <string>
	
	using namespace std;
	
	int main()
	{
	    int N, drone1 = 0, drone2 = 0, temp1 = 0, temp2;  
		   
	    cin >> N;
		
	    int* array = new int[N]; 
	    for (int i = 0; i < N; i++) 
		{  
	        cin >> array[i];  
	    }

	    temp2 = N-1; 
	    for (int i = 0; i < N; i++) 
		{
	        if (temp1+1 < temp2) 
			{ 
	            temp1+= drone1; // додавання клітинки в які стоїть дрон 1
	            temp2-= drone2; // віднімання клітинки в якій стоїть дрон 2
	            
	            drone1 = array[temp1]; //елемент на якому зупиниться дрон1 
	            drone2 = array[temp2]; //елемент на якому зупиниться дрон2 
	        } 
			else 
			{
	            break;
	        }

	    }
	    if(temp1+1==temp2)
		{ 
	        cout << temp1+1 << " " << temp2+1 << endl; // дрони зупинилися один біля одного
	        cout << "Stopped";
	    }else
		{
	        if(temp1==temp2)
			{ 
	        cout << temp1+1 << " " << temp2+1 << endl; // дрони один на одному
	        cout << "Collision";
	        }
			else
			{ 
	        cout  << temp1+1 << " " <<  temp2+1 << endl; // дрон перелетіли
	        cout << "Miss";
	        }
	    }

	    delete []array;
	    return 0;
	}
