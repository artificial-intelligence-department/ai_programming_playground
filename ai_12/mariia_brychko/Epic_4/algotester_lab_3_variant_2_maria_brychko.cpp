#include <iostream>
#include <unordered_set>
using namespace std;

int main () {
int N, M;
cin >> N;
int a[N];
unordered_set<int> unielem;      //створює змінну, яка буде використовуватися для зберігання унікальних цілих чисел.

for (int i = 0; i < N; i++){
   cin >> a[i];
   unielem.insert(a[i]);    
   }

cin >> M;
int b[M];
int common = 0;

for (int i = 0; i < M; i++){
   cin >> b[i];
      if (unielem.find(b[i]) != unielem.end()) {    
            ++common;
        }
        unielem.insert(b[i]);
        }

        cout << common << endl;
        cout << unielem.size();

    return 0;
}
