#include <iostream>
using namespace std;

int main()
{
	int sum = 0;	 
	int i = 2;		 
	while (i < 100) 
	{
		sum += i; 
		i += 2;	 
	}
	cout << "Sum = " << sum << endl; 
	return 0;
}