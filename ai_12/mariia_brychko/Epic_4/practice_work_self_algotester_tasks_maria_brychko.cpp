#include <iostream>
using namespace std;

int main() 
{
	int n; 
	int m;                       //необхідна кількість шматків загалом
	cin >> n >> m;

	long a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	double low = 0;               
	double high = 0;         \
	for(int i = 0; i < n; i++)
	{
		if(a[i] > high)
		{
			high = a[i];
		}
	}

	double E = 0.000001;
	int counter;              
	double result = 0;

	while (high-low >= E)
	{
		counter = 0;
		double center = (high+low)/2;                   
		for(int i = 0; i < n; i++)
		{
			counter += a[i]/center;
		}
		if(counter >= m)
		{
			low = center;
			result = center;
		}
		if(counter < m)
		{
			high=center;
		}
	};
	
	cout << result;
	return 0;
}
