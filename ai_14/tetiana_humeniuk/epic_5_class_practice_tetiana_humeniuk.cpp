#include <iostream>
#include <fstream>
using namespace std;
enum FileOpResult {Success, Failure};
FileOpResult write_to_file(const char *name, char *content)
{
    ofstream file_out(name);
    if(file_out.is_open())
    {
         file_out<<content;
         file_out.close();
         return Success;
    }
   return Failure;
    
}

 int main()
 {
  cout<<"enter file name"<<endl;
  char* file_name;
  cin>>file_name;
  cout<<"enter text"<<endl;
  char* text;
  cin>>text;
  FileOpResult result = write_to_file(file_name, text);
  switch (result)
  {
    case Success:
    cout<<"Success";
    break;
    case Failure:
    cout<<"Failure";
    break;
  }
 
 }
