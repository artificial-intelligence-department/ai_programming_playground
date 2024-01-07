#include <iostream>
#include <vector>
using namespace std;
int minfounder(vector<vector<int>> array, int N, int M)
{
	int min = array[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (array[i][j] < min)
			{
				min = array[i][j];

			}
		}
	}
	return min;
}
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	int x, y;
	cin >> x >> y;
	int xmod = x - 1;
	int ymod = y - 1;
	vector<vector<int>> mountain;
	mountain.resize(N);
	for (int i = 0; i < N; i++)
	{
		mountain[i].resize(M);
	}
	int testpoint = 1002;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mountain[i][j] = -1;
		}
	}
	mountain[xmod][ymod] = testpoint;

	if (N > 1)
	{

		for (int i = xmod; i > 0; i--)
		{
			for (int j = ymod; j > 0; j--)
			{
				if (mountain[i][j - 1] == -1)
				{
					mountain[i][j - 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j >= 0; j--)
			{

				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j < M - 1; j++)
			{
				if (mountain[i][j + 1] == -1)
				{
					mountain[i][j + 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j <= M - 1; j++)
			{

				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
			}
		}

		for (int i = xmod; i < N - 1; i++)
		{
			for (int j = ymod; j > 0; j--)
			{
				if (mountain[i][j - 1] == -1)
				{
					mountain[i][j - 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j >= 0; j--)
			{

				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j < M - 1; j++)
			{
				if (mountain[i][j + 1] == -1)
				{
					mountain[i][j + 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j <= M - 1; j++)
			{

				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
			}
		}
		int min = minfounder(mountain, N, M);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				mountain[i][j] = -1;
			}
		}
		mountain[xmod][ymod] = testpoint - min;

		for (int i = xmod; i > 0; i--)
		{
			for (int j = ymod; j > 0; j--)
			{
				if (mountain[i][j - 1] == -1)
				{
					mountain[i][j - 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j >= 0; j--)
			{

				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j < M - 1; j++)
			{
				if (mountain[i][j + 1] == -1)
				{
					mountain[i][j + 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j <= M - 1; j++)
			{

				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
			}
		}

		for (int i = xmod; i < N - 1; i++)
		{
			for (int j = ymod; j > 0; j--)
			{
				if (mountain[i][j - 1] == -1)
				{
					mountain[i][j - 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j >= 0; j--)
			{

				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j < M - 1; j++)
			{
				if (mountain[i][j + 1] == -1)
				{
					mountain[i][j + 1] = mountain[i][j] - 1;
				}
			}
			for (int j = ymod; j <= M - 1; j++)
			{

				if ((i < N - 1) && mountain[i + 1][j] == -1)
				{
					mountain[i + 1][j] = mountain[i][j] - 1;
				}
				if (i > 0 && mountain[i - 1][j] == -1)
				{
					mountain[i - 1][j] = mountain[i][j] - 1;
				}
			}
		}
	}
	else if (N == 1)
	{
		for (int j = ymod; j > 0; j--)
		{
			mountain[0][j - 1] = mountain[0][j] - 1;
		}
		for (int j = ymod; j < M - 1; j++)
		{
			mountain[0][j + 1] = mountain[0][j] - 1;
		}
		int min = minfounder(mountain, N, M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				mountain[i][j] = -1;
			}
		}
		mountain[xmod][ymod] = testpoint - min;
		for (int j = ymod; j > 0; j--)
		{
			mountain[0][j - 1] = mountain[0][j] - 1;
		}
		for (int j = ymod; j < M - 1; j++)
		{
			mountain[0][j + 1] = mountain[0][j] - 1;
		}

	}




	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << mountain[i][j] << " ";
		}
		cout << endl;
	}




}