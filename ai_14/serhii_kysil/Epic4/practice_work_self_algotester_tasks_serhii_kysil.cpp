#include <iostream>
using namespace std;
int main(){
	int N;
	long K;
	cin >> N >> K;
	long arr[N];
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	long counter = 0;
	long maxcounter = 0;
	for(int i = 0; i < N; i++){
		if(arr[i] >= K)
		{
			counter++;
			continue;
		}
		if(counter > maxcounter){
			maxcounter = counter;
		}
		counter=0;
	}

	cout << maxcounter;
	return 0;
}