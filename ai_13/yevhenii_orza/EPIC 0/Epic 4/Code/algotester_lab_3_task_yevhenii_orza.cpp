#include <iostream>


int main(){
int N, M;
int count = 0;
int uncount = 0;


std::cin >> N;
int arr1[N];
for (int i = 0; i < N; i++){
    std::cin>>arr1[i];
}
std::cin >> M;
int arr2[M];
for (int i = 0; i < M; i++){
    std::cin>>arr2[i];
}
for (int i = 0; i < N; i++){
    for(int b = 0; b < M; b++){
    if(arr1[i] == arr2[b]){
        count = count + 1;
    }
    }
}
uncount = (M + N) - count;
std::cout << count << std::endl;
std::cout << uncount << std::endl;

}