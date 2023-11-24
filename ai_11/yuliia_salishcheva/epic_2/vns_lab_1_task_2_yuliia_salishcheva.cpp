#include <iostream>

int main()
{
	//1
	int n = 2, m = 3;
	std::cout << n++ - m << std::endl;
	std::cout << n << std::endl;
	//2
	int a = 1, b = 2;
	std::cout << (a-- > b) << std::endl;
	//3
	int c = 3, d = 2;
	std::cout << (c-- > d) << std::endl;

}
