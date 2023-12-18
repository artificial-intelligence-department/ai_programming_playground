#include <iostream>
using namespace std;

int main()
{
	long long N;                                         
	cin >> N;
	long long size = 2*N;

	long long Array[size];
	for(long long i=0; i<size; i++)
		cin >> Array[i];

	cout << "Marichka\n";

	long long sumparne=0, sumneparne=0, left=0, right=size-1;
	for(long i=0; i<size-1; i+=2)
	{
		sumparne+=Array[i];
	}
	for(long i=1; i<=size-1; i+=2)
	{
		sumneparne+=Array[i];
	}
	
	bool parnychBilshe;
	(sumparne>=sumneparne)?parnychBilshe=true:parnychBilshe=false;
	for(long long i=0; i<N; i++)
	{
		if(parnychBilshe)
		{
			if(left%2==0||left==0)
			{
				left++;
				cout << 'L';
			}
			else
			{
				right--;
				cout << 'R';
			}
		}
		else
		{
			if(left%2==1||left==1)
			{
				left++;
				cout << 'L';
			}
			else
			{
				right--;
				cout << 'R';
			}
		}

		if(Array[left]>=Array[right])
			left++;
		else
			right--;
	}
	return 0;
}