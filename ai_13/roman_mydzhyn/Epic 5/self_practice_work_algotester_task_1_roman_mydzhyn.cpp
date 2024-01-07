#include <iostream>
using namespace std;

// Функція для знаходження максимального значення з двох чисел
long long findMaxValue(int a, int A, int b, int B, int n)
{
	long long ans = 0; // максимальне значення

	for (int x = 0; a * x <= n && x < b; ++x)
	{
		int y = (n - a * x) / b;
		ans = max(ans, A * (long long)x + B * (long long)y);
	}

	// максимальне значення з двох чисел
	for (int y = 0; b * y <= n && y < a; ++y)
	{
		int x = (n - b * y) / a;
		ans = max(ans, A * (long long)x + B * (long long)y);
	}

	return ans;
}

long long findMaxValue(int a, int A, int b, int B, int c, int C, int n)
{
	long long ans = 0;

	for (int x = 0; a * x <= n && x < a * b * c; ++x)
	{
		ans = max(ans, A * (long long)x + findMaxValue(b, B, c, C, n - a * x));
	}

	for (int y = 0; b * y <= n && y < a * b * c; ++y)
	{
		ans = max(ans, B * (long long)y + findMaxValue(a, A, c, C, n - b * y));
	}

	for (int z = 0; c * z <= n && z < a * b * c; ++z)
	{
		ans = max(ans, C * (long long)z + findMaxValue(a, A, b, B, n - c * z));
	}

	return ans;
}

int main()
{
	int b, d, m, n;
	cin >> b >> d >> m >> n;

	if (b < d)
	{
		swap(b, d);
	}

	long long ans = findMaxValue(6, b, 9, b + d, n);
	if (n >= 6)
	{
		ans = max(ans, m + findMaxValue(6, b, 9, b + d, 5, m, n - 6));
	}

	cout << ans << endl;
	return 0;
}
