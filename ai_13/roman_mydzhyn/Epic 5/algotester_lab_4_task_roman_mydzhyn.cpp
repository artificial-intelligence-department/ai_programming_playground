#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	int N, i;
	cin >> N;
	vector<int> S(N);
	for (i = 0; i < N; i++)
	{
		cin >> S[i];
	}

	auto it = partition(S.begin(), S.end(), [](int i)
							  { return i % 3 == 0; });
	auto it1 = partition(S.begin(), it, [](int i)
								{ return i % 3 == 2; });
	auto it2 = partition(it, S.end(), [](int i)
								{ return i % 3 == 1; });

	sort(S.begin(), it1);
	sort(it1, it);
	sort(it, it2, greater<int>());
	sort(it2, S.end(), less<int>());

	auto it3 = unique(S.begin(), S.end());

	S.erase(it3, S.end());
	cout << S.size() << endl;
	copy(S.begin(), S.end(), ostream_iterator<int>(cout, " "));

	return 0;
}
