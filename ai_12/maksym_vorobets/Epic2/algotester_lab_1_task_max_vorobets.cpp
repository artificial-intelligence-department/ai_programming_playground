#include <iostream>

int main(){
 long long h1, h2, h3, h4;
    long long d1, d2, d3, d4;
    scanf("%lld %lld %lld %lld", &h1, &h2, &h3, &h4);
    scanf("%lld %lld %lld %lld", &d1, &d2, &d3, &d4);
     long long h11=h1-d1, h12=h2-d2, h13=h3-d3, h14=h4-d4;
     long long min_h=h1;
        if(h2<min_h){min_h=h2;}
        if(h3<min_h){min_h=h3;}
        if(h4<min_h){min_h=h4;}
    long long max_new=h11;
        if(h12>max_new){max_new=h12;}
        if(h13>max_new){max_new=h13;}
        if(h14>max_new){max_new=h14;}
    long long min_new=h11;
        if(h12<min_new){min_new=h12;}
        if(h13<min_new){min_new=h13;}
        if(h14<min_new){min_new=h14;}
    if(d1>h1||d2>h2||d3>h3||d4>h4){printf("ERROR\n");}
    else if(2*min_new>max_new&&min_h!=0&&2*h12>max_new&&2*h13>max_new&&2*h11>h2&&2*h11>h3&&2*h11>h4&&2*h12>h3&&2*h12>h4&&2*h13>h4){
        printf("YES\n");}
    else{
        printf("NO\n");}
  return 0;
}  
