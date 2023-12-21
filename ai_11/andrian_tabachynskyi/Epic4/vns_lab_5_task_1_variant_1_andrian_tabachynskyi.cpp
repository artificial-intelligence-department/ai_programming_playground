#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canArrangeSideDiagonal(vector<vector<int>>& matrix, int N) {
	for (int j = 0; j < N; ++j) {
		sort(matrix[j].begin(), matrix[j].end());
		for (int i = 0; i < N; ++i) {
			if (matrix[j][i] != matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int N;
	cout << "Enter the size of the matrix (N): ";
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N));

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
	}

	if (canArrangeSideDiagonal(matrix, N)) {
		cout << "It is possible to rearrange the columns to have increasing elements along the side diagonal." << endl;
	}
	else {
		cout << "It is not possible to rearrange the columns to have increasing elements along the side diagonal." << endl;
	}

	return 0;
}


/*
1 2 - 4
3 - 5 6
6 9 0
*/