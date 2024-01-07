#include <iostream>

void str1(int m){
    for(int j = 0; j < m;j++){
    if(j%2 == 1)
    std::cout << 'x';
    else{
    std::cout << '.';
        }
    }
std::cout << std::endl;



}

void str2(int m){
     for(int j = 0; j < m;j++){
        std::cout << '.';
     }
     std::cout << std::endl;
}
void str3(int m){
    for(int j = 0; j < m;j++){
    if(j%2 != 1)
    std::cout << 'x';
    else{
    std::cout << '.';
        }
    }
std::cout << std::endl;

}


int main(){
    using namespace std;
    int n, m;
    cin >> n >> m;
    int field[n][m];
    for(int i = 0; i<n - 1;i++){
    if(i%4 == 0 || i == 0){
        str1(m);
    }
    else if(i%2 == 1){
        str2(m);
    }
    else if(i%2 == 0)
        str3(m);
    }
int check = n/2;
check = check%2;
if(n%2 == 0)
str3(m);
else if( check == 1 && n%2 == 1)
str3(m);
else if( check == 0 && n%2 == 1)
str1(m);
    return 0;
}