#include <iostream>
#include <algorithm>                                                                        // Для використання функції std::sort
using namespace std;
int main () {
int N, min;
int i;
cout << "Please, enter the number of numbers in the array \"R\": ";
cin >> N;
while  (N < 1 || N > 100000LL) {
    cout << "Invalid input for the number of numbers in the array \"R\".\n";
    cout << "Please, enter the number of numbers in the array \"R\": \n";
    cin >> N;}
int R [N-1];     
for (int i = 0; i < N; i++){
   cout << "Enter element " << i+1 << " of the array \"R\": ";
   cin >> R[i];
while  (R[i] < 0 || R[i] > 100000LL) {
    cout << "Invalid input for the element of the array \"R\".\n";
    cout << "Enter element " << i+1 << " of the array \"R\": ";
    cin >> R[i];} }
sort(R, R + N);
if (R[N-2] - R[0] < R[N-1] - R[1]){
    min = R[N-2] - R[0];
} else {
    min = R[N-1]-R[1];}
cout << min;
return 0;
}





