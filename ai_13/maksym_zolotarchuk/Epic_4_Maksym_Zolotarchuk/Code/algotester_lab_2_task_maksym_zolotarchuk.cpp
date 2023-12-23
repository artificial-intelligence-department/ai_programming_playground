#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
 // Вказую розмір масиву
 int N;
 cin >> N;


 vector<int> pos(N);
 // Заповнюю масив
 for (int i = 0; i < N; ++i)
  cin >> pos[i];


 int drone_1 = 1;
 int drone_2 = N;

 do{
  if (drone_1 == drone_2)
  {
   cout << drone_1 << " " << drone_2 << endl;
   cout << "Collision" << endl;
   break;
  }
  else if (drone_1 > drone_2)
  {
   cout << drone_1 << " " << drone_2 << endl;
   cout << "Miss" << endl;
   break;
  }
  else if (drone_1 + 1 == drone_2)
  {
   cout << drone_1 << " " << drone_2 << endl;
   cout << "Stopped" << endl;
   break;
  }
  
  drone_1 = drone_1 + pos[drone_1 - 1];
  drone_2 = drone_2 - pos[drone_2 - 1];

 } while (true);

 return 0;
}
