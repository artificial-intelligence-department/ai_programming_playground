#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	double E = 0.0001;
	double suma = 0.0;
	double an = 1.0, e=2.71;

	cout << "Enter a number: " << endl;
	cin >> n;

	while(fabs(an)>=E)
	{
		an =an* (log10(n + 1) * pow(e, -sqrt(n + 1)));
		suma+=an;
	}
	
	cout<< suma << endl;

	return 0;
}