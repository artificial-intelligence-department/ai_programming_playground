#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i<n; i++) {
        std::cin>>a[i];
    }
    int m;
    std::cin >> m;
    int *b = new int[m];
    for (int i = 0; i<m; i++) {
        std::cin>>b[i];
    }

    int not_unique = 0;
    for (int i=0;i<n; i++) {
        for (int j=0;j<m;j++) {
            if (a[i] == b[j]) {
                not_unique++;
                break;
            }
        }
    }
    int unique = m+n-not_unique;
    std::cout << not_unique << std::endl << unique;
    return 0;
}