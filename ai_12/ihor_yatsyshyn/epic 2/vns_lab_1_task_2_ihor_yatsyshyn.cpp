#include <cstdio>

int main() {
    int n, m;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    printf("%d \n", n+++m);
    printf("%d \n", m-->n);
    printf("%d \n", n-->m);
    printf("%d", n);

    return 0;
}