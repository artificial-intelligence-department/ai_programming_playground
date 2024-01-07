#include <iostream>

using namespace std;

int main() {
	double length, height, width, res;
	cout << "Enter please length: ";
	cin >> length;
	cout << "\nEnter please height: ";
	cin >> height;
	cout << "\nEnter please width: ";
	cin >> width;

	res = 2 * ((length * width) + (width * height) + (length * height));
	cout << res;

	double kil, verst;
	cout << "\nWrite kilometers: ";
	cin >> kil;

	verst = (kil * 1000) / 1066.8;
	
	cout << endl << verst;
}
