#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 const int size = 100;
 int N = 0;
 int M = 0;

 int arr_1 [size];
 int arr_2 [size];

 cin >> N;
 for(int i = 0; i < N; ++i)
 {
  cin >> arr_1[i];
 }

 cin >> M;
 for (int k = 0; k < M; ++k)
 {
  cin >> arr_2[k];
 }


 int common = 0;

 for (int i = 0; i < N; ++i)
 {
  for (int k = 0; k < M; ++k)
  {
   if (arr_1[i] == arr_2[k])
   {
    ++common;
    continue;
   }
  }
 }
  

 int unique = (N + M) - common;

 cout << "Common elements: " << common << endl; 
 cout << "Unique elements: " << unique << endl;


 return 0;

}
