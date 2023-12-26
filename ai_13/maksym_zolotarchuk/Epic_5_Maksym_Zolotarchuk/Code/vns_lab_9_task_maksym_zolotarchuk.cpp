#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ofstream F1("C:/AlgotesterLabs/F1.txt");
  string line;

  cout << "Enter in first file (F1): " << endl;

  for (int i = 0; i < 10; ++i)
  {
   getline(cin, line);
   F1 << line << endl;
  }

  ifstream F1_full("C:/AlgotesterLabs/F1.txt");
  ofstream F2("C:/AlgotesterLabs/F2.txt");

  int symbols = 0;
  while (getline(F1_full, line)) 
  {
   if (line.front() == line.back())
   {
    F2 << line << endl;
    symbols += line.length();
   }
  }
 cout << "Amount of symbls in F2: " << symbols;
  
  return 0;
}
