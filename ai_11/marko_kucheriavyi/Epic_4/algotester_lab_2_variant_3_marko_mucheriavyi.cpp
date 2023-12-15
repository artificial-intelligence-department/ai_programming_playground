#include <iostream>
using namespace std;
int main()
{
    int N, array[N];
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> array[i];
    }
    int i = 0, j = N - 1;
    while (true){
        if (j - i == 1){
            cout << i+1 << " " << j+1 << endl;
            cout << "Stopped ";
            break;
        }
        if (j == i){
            cout << i+1 << " " << j+1 << endl; 
            cout << "Collision";
            break;
        }
        if (j - i < 0){
            cout << i+1 << " " << j+1 << endl;
            cout << "Miss";
            break;
        }
        i+=array[i];
        j-=array[j];
    }
    return 0;
}