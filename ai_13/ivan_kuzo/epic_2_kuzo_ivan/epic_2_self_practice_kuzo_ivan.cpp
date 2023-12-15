#include<iostream>
using namespace std;
int main()
{
	int a = 0;
	unsigned int n;
	cin >> n;
	if (n<1)
		n=1;
	if (n >= 500)
		for (; n >= 500; a++)
			n -= 500;
	if (n >= 200)
		for (; n >= 200; a++)
			n -= 200;
	if (n >= 100)
		for (; n >= 100; a++)
			n -=100;
	if (n >= 50)
		for (; n >= 50; a++)
			n -= 50;
	if (n >= 20)
		for (; n >= 20; a++)
			n -= 20;
	if (n >= 10)
		for (; n >= 10; a++)
			n -= 10;
	if (n >= 5)
		for (; n >= 5; a++)
			n -= 5;
	if (n >= 2)
		for (; n >= 2; a++)
			n -= 2;
	if (n >= 1)
		for (; n >= 1; a++)
			n -= 1;
	cout << a<<"\n\n";
	cout<<"any number to quit";
	int quit;
	cin>>quit;
	return 0;
}

