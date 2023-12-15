#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    const int chunk_size = 200;

    char* buffer = new char[chunk_size];
    string myText;
  
  ifstream MyFile("F1.txt");

  int chunk_count = 0;
 while (MyFile) {
    
    MyFile.read(buffer, chunk_size);
  
    int bytesRead = MyFile.gcount();
   
    if (bytesRead > 0) {
      
      chunk_count++;
     
      string outfile_name = "output" + to_string(chunk_count) + ".txt";
      
      ofstream outfile(outfile_name);
      
      if (!outfile) {
        cerr << "Error opening output file\n";
        return 2;
      }
   
      outfile.write(buffer, bytesRead);
     
      outfile.close();
    }
  }
MyFile.seekg(0);

  MyFile.close();
}