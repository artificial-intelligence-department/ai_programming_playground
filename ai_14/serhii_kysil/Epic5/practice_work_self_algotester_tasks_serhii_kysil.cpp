#include <iostream>
using namespace std;
int main() 
{
	int N;
	int M;
	cin >> N >> M;
	int arr1[N];
	int arr2[M];
	int min = 1000;
	int res;
	for(int i=0; i<N; i++)
	{
		cin >> arr1[i];
		if(arr1[i]<min)
			min = arr1[i];
	}
	res = min;
	min = 1000;
	for(int i=0; i<M; i++)
	{
		cin >> arr2[i];
		if(arr2[i]<min)
			min = arr2[i];
	}
	res+=min;
	cout << res;
	return 0;
}