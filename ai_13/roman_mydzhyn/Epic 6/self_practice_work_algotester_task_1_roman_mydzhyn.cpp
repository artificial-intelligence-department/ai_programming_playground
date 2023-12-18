#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void upd(int &x, int val) // функція при val менше, то оновлює x
{
	x = min(x, val); // встановлює x як мінімум з x та val
}

int main() //
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> x1(k), y1(k), x2(k), y2(k);
	vector<int> d(m, numeric_limits<int>::max()); // оголошення вектора d з максимальними значеннями

	for (int i = 0; i < k; i++) // цикл для введення даних
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i]; // ввід даних
	}

	int ans = 0; // оголошення змінної для відповіді

	for (int a = 1; a <= n; a++)
	{
		fill(d.begin(), d.end(), numeric_limits<int>::max()); // заповнення вектора d максимальними значеннями

		for (int i = 0; i < k; i++)
		{
			if (x1[i] / a == x2[i] / a)
			{
				upd(d[min(y1[i], y2[i])], max(y1[i], y2[i])); // оновлення значення вектора d
			}
		}

		for (int b = 1; b <= m; b++) // цикл для обчислення
		{
			bool ok = true; // змінна для перевірки умови
			for (int j = 0; j < m; j++)
			{
				ok &= j / b != d[j] / b;
			}
			if (ok)
			{
				ans = max(ans, a * b); // оновлення відповіді
			}
		}
	}

	cout << ans << endl;

	return 0;
}
