#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  //відкриває файл F1.txt для зчитування інформації
  ifstream f1("F1.txt");
  //відкриває файл F2.txt для зчитування інформації
  ofstream f2("F2.txt");

  string line;
  while (getline(f1, line)) {
    if (line.find(' ') == string::npos) {
      f2 << line << endl;
    }
  }

  f1.close();
  f2.close();

  return 0;
}