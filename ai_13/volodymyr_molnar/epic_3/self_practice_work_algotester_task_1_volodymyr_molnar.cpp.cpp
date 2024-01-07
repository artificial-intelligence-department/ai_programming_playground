#include <iostream>

using namespace std;

int sum(int n) {
	int result{};
	for (size_t i = 0; i <= n; i++)
		result += i;
	return result;
}

int main() {
    int a;
	cin >> a;
	cout << sum(a);

    return 0;
}
