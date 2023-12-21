#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   float m, n, res_1;
   bool res_2, res_3;

   cout << "input n: ";
   cin >> n;
   cout << "input m: ";
   cin >> m;

   res_1 = n++*m;
   res_2 = n++<m;
   res_3 = n++>m;

   cout << res_1 << endl; 

   if(res_2){
      cout << "true" << endl;
   }
   else{
      cout << "false" << endl;
   }
   if(res_3){
      cout << "true" << endl;
   }
   else{
      cout << "false" << endl;
   }
   return 0;
} 
