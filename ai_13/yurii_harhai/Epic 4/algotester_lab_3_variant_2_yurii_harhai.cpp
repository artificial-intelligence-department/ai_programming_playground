#include <iostream>
using namespace std;
int same {0};
int unique {0};
int main(){
    cout << "Enter first array range: ";
    int N {};
    cin >> N;
    int first[N] {};
    cout << "Enter numbers for first array: ";
     
    for (int i = 0; i < N; i++)
    {
        cin >> first[i];  
    }
cout << "Enter second array range: ";
    int M {};
    cin >> M;
    int second[M] {};
    cout << "Enter numbers for second array: ";
     
    for (int i = 0; i < M; i++)
    {
        cin >> second[i];  
    }

    for (int i = 0; i < N; i++){
        for (int k = 0; k < M; k++){
            if (first[i] == second[k])
                same++;
      }
    }
    unique = (M+N)-same;
    cout << same << endl;
    cout << unique;
    return 0;
}