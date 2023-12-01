//епік 2 лаба 1 (2)

#include <iostream>
 using namespace std;
int main()
{
   cout << "Enter a number: ";
   float m = 0;
   cin >> m; 
   cout << "You entered " << m << endl;
    cout << "Enter a number: ";
   float n = 0;
   cin >> n; 
   cout << "You entered " << n << endl;
   float result1=(m++-n);
   cout <<result1<<endl;

   float result2=(m-->n);
   cout <<result2<<endl;

   float result3=(n-- >m);
   cout <<result3<<endl;


   
   return 0;

}