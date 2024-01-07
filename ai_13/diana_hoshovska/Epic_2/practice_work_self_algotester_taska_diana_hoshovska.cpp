#include <iostream>
#include <vector>
#include <algorithm>
int gcd(int a, int b) {
while (a != 0 && b != 0)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return (a+b);
}

int main(){
    long long int n, nsd, sum2=0;
    std::cin >> n;
    std::vector <long long> a(n);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    if (n == 1) { std::cout << 1; }
    else {
        nsd = gcd(a[0], a[1]);
		for (int i = 2; i < n; i++)
        {
			nsd = gcd(nsd, a[i]);
		}
        for (int i = 0; i < n; i++)
        {
            sum2 += a[i]/nsd;
        }
        std::cout << sum2;
    }
    return 0;
}
