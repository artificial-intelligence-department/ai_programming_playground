#include <iostream>
using namespace std;
int main ()
{
   int p=10; //productivity in 1 hour
   int Hshift=8; //8 hours in 1 shift
   int Dmonth=30-4; //work days in month
   int prevention=1; //1 hour for prevention


   int puck_in_shift = p*(Hshift-prevention);
   int puck_in_two_shift=puck_in_shift*2;
   int puck_in_month=Dmonth*puck_in_shift;
   cout<<"Automatic machine produces "<<puck_in_shift<<" pucks"<<" in 1 shift."<<endl;
   cout<<"Automatic machine produces "<<puck_in_two_shift<<" pucks"<<" in 2 shifts."<<endl;
   cout<<"Automatic machine produces "<<puck_in_month<<" pucks"<<" in 1 month."<<endl;


    return 0;
}
