#include<iostream>
using namespace std;

int main() {

	int array[10] = {};
	cout << "Please enter 10 elements" << endl;

	for (int i = 0; i < 10; i++) {
		cin >> array[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	for (int i = 0; i < 10; i++) {
		if (array[i] > 9) {
			array[i] -= 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}


}




//  3 14 17 1 8 15 1 8 3 14