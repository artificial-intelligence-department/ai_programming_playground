#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int members, numUrns, buleteni;
	cin >> members >> numUrns >> buleteni;
	vector<int> Urns(numUrns);

	for (int i = 0; i < numUrns; i++)
	{
		cin >> Urns[i];
	}

	for (int i = 0; i < numUrns; i++)
	{
		if (Urns[i] > buleteni)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	int count = 1;
	int cur = 0;

	for (int i = 0; i < numUrns; i++)
	{
		if (cur + Urns[i] <= buleteni)
		{
			cur += Urns[i];
		}
		else
		{
			count++;
			cur = Urns[i];
		}
	}

	int ans = members - count;

	if (count > members)
	{
		ans = -1;
	}

	cout << ans << endl;
	return 0;
}
