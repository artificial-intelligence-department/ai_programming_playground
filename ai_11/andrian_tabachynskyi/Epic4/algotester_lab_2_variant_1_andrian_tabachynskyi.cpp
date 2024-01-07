#include <iostream>

using namespace std;

int main() {
	int a, b, c, n, d = 0;
	//const int n = 10;
	cin >> n;
	int* r;
	r = new int[n];
	//int r[n] = {5,6,5,4,7,1,4,7,10,2};
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}
	cin >> a;
	cin >> b;
	cin >> c;

	/*for (int i = 0; i < n; i++) {
		cout << "\nr[" << i << "]=" << r[i]<<endl;
	}*/


	for (int i = 0; i < n; i++) {
		if ((r[i] != a) && (r[i] != b) && r[i] != c) {
			d++;
		}
	}
	if (d == 0 || d == 1) {
		cout << 0;
		exit(0);
	}

	int* rt;
	rt = new int[d];

	int k = 0;
	for (int i = 0; i < n; i++) {
		if ((r[i] != a) && (r[i] != b) && r[i] != c) {
			rt[k] = r[i];
			k++;
		}

	}

	//	for (int k = 0; k < d; k++) {
		//	cout << "\nrt[" << k << "]=" << rt[k] << endl;
		//}

	int f = d - 1;
	cout << f << endl;
	int* rtnew;
	rtnew = new int[f];
	int k1 = 0;

	for (int i = 0; i < f; i++) {
		rtnew[i] = rt[k1] + rt[k1 + 1];
		k1++;
		cout << rtnew[i] << " ";
	}
	/*
		for (int i = 0; i < f; i++) {
			cout << /*"\nrtnew[" << i << "]=" rtnew[i] << " ";
		}*/
}