#include <iostream>
#include <vector>

using namespace std;

// Функція "solve" приймає вектор "arr" та два індекси "left" та "right"
void solve(vector<int> &arr, int left, int right)
{
	
	if (left == right)
	{
		cout << left << " " << right << endl;
		cout << "Collision "<< endl;
	}
	
	else if (left > right)
	{
		cout << left << " " << right << endl;
		cout << "Miss" << endl;
	}

	else if (left == right - 1)
	{
		cout << left << " " << right << endl;
		cout << "Stopped" << endl;
	}
	// Тоді викликаю рекурсивно "solve з новими значеннями" "left" та "right"
	else
	{
		solve(arr, left + arr[left], right - arr[right]);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N + 1);
	// Заповнення вектора
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	solve(arr, 1, N);

	return 0;
}
