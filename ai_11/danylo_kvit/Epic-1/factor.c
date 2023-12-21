#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    long long ans = 1;
    for(int i=1;i<=n;i++) ans*=i;
    printf("%lld",ans);

}