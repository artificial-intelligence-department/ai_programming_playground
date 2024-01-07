#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n = 4;
	string output = "YES";
	long long int h[4], d[4];
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	long long int maxNum = 0, minNum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (d[i] > h[i])
		{
			output = "ERROR";
		}
	}
	if (output != "ERROR")
	{
		for (int i = 0; i < 4; i++)
		{
			h[i] -= d[i];
			if (h[i] == 0 || h[0] / h[i] >= 2 || h[1] / h[i] >= 2 || h[2] / h[i] >= 2 || h[3] / h[i] >= 2)
			{
				output = "NO";
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (h[i] == 0 || h[i] != h[1] || h[i] != h[2] || h[i] != h[3] || h[i] != h[0])
			{
				output = "NO";
			}
		}
	}

	cout << output << endl;

	return 0;
}