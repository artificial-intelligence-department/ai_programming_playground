#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	double result = 0;

	int x1, y1, x2, y2;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		double y = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		result += y;
	}
	
	cout << static_cast<int>(result) << endl;

	return 0;

}







