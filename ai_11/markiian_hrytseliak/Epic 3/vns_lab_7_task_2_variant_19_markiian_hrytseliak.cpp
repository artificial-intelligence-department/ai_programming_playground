#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

// Functiuon overload;

// For array of integers finds minimal element;

int min(int n,int a[0])
{
  int min=a[0];
  for(int i=1; i<n; i++)
  {
    if(a[i]<min)
    {
      min=a[i];
    }
  }
  return min;
  
}

// For string finds length of the shortest word;

 int min(string line)
 {
    int len = INT_MAX;
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        if(word.length()<len)
        {
            len = (int) word.length();
        }
    }
    return len;
 }

 int main()
 {
    int n=5;
    int a[]={10,9,8,7,6};
    cout<<"Minimal element of the array that consists of integers: "<<min(5,a)<<endl;
    string line;
    cout<<"Enter your string: "<<endl;
    getline(cin, line);
    cout<<"Lenght of the shortest word is: "<<min(line)<<endl;
    return 0;
 }