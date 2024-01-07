#include <iostream>
#include <cmath>
using namespace std;

void Sum(int a[3][3], int b[3][3], int sum[3][3])
{

 for (int i = 0; i < 3; ++i)
 {
  for (int j = 0; j < 3; ++j)
  {
   sum[i][j] = a[i][j] + b[i][j];
  }
 }

}

void Transponed(int sum[3][3], int transponed[3][3])
{
 for (int i = 0; i < 3; ++i)
 {
  for (int j = 0; j < 3;++j)
  {
   transponed[j][i] = sum[i][j];
  }
 }

}

int main()
{

 int a[3][3] = 
 {

  {0,1,4},
  {10,8,5},
  {6,2,1}

 };

 int b[3][3] =
 {

  {3,6,8},
  {1,1,9},
  {3,7,2}

 };
 int sum[3][3];
 int transponed[3][3];


 cout << "Sum of matrix: " << endl;

 Sum(a, b, sum);
 for (int i = 0; i < 3; i++) 
 {
  for (int j = 0; j < 3; j++) {
   cout << sum[i][j] << " ";
  }
 }
 cout << endl;

 cout << "Transponed matrix: " << endl;

 Transponed(sum, transponed);

 for (int i = 0; i < 3; i++) 
 {
  for (int j = 0; j < 3; j++) {
   cout << transponed[i][j] << " ";
  }
 }

 return 0;

}
