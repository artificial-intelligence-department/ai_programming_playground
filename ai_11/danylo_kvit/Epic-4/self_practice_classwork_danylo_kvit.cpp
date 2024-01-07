long long exp(long long x, int n){
    if(n==0) return 1;
    return x*exp(x,n-1);
}
bool is_pal(char* a, int n){
    if(n<2) return true;
    if(*a!=*(a+n-1)) return false;
    return is_pal(a+1,n-2);
}
bool is_pal(long long k, int n){
    if(n<2) return true;
    if(k%10!=k/exp(10,n)) return false;
    return is_pal((k/10)%exp(10,n-1),n-2);
}
bool is_pal(long long k, int n, char){

    if(k/exp(10,n+1)==0) return is_pal(k,n);
    return is_pal(k, n+1, 'q');
}
bool is_pal(long long k){
    return is_pal(k,0, 'q');
}

