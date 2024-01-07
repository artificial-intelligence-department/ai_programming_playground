#include <iostream>

using namespace std;

int main() 
{
  int N, M, x, y;
  
  cin >> N >> M >> x >> y;
  
  int** a = new int*[N];
  
  for (int i = 0; i < N; i++) 
  { 
    a[i] = new int[M]();
  }
  
  for (int i = 0; i < N; i++) 
  {
    for (int j = 0; j < M; j++) 
    {
        a[i][j] = -abs(x - 1 - i) - abs( y - 1 - j);
    }
  }
  
  int min = 0;
  
  for (int i = 0; i < N; i++) 
  {
    for (int j = 0; j < M; j++) 
    {
      if (min > a[i][j]) 
      {
        min = a[i][j];
      }
    }
  }
  
  for (int i = 0; i < N; i++) 
  {
    for (int j = 0; j < M; j++) 
    {
      a[i][j] -= min;
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
