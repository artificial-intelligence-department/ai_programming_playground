#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int length = s.length();
	char masB[length];
	char masY[length];

	for(int i=0; i<length; i++)
	{
		if(i%2==0)
		{
			masB[i]='B';
			masY[i]='Y';
		}
		else
		{
			masB[i]='Y';
			masY[i]='B';
		}
	}
	int counterForB=0;
	int counterForY=0;
	for(int i=0; i<length; i++)
	{
		if(masB[i]!=s.at(i))
			counterForB++;
		if(masY[i]!=s.at(i))
			counterForY++;
	}
	if(counterForB<counterForY)
		cout << counterForB;
	else
		cout << counterForY;

	return 0;
}