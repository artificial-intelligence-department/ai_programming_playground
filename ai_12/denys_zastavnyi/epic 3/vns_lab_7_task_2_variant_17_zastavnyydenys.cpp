#include <iostream>
#include <cctype>
#include <string>

using namespace std;

double findAverage(int arrlen, int arr[]) {
  double sum = 0;
  for (int i = 0; i < arrlen; i++)
  {
    sum += arr[i];
  }
  return sum / arrlen;
}
double findAverage(int arrlen, float arr[]) {
  double sum = 0;
  for (int i = 0; i < arrlen; i++)
  {
    sum += arr[i];
  }
  return sum / arrlen;
}
double findAverage(int arrlen, double arr[]) {
  double sum = 0;
  for (int i = 0; i < arrlen; i++)
  {
    sum += arr[i];
  }
  return sum / arrlen;
}

int countLetters(const char* str) {
  int count = 0;
  while (*str) {
    if (isalpha(*str)) {
      count++;
    }
    str++;
  }
  return count;
}

int countLetters(const string& str) {
  int count = 0;
  for (char ch : str) {
    if (isalpha(ch)) {
      count++;
    }
  }
  return count;
}


int main() {

  int xlen = 7;
  int x[] = {15, 45, 78, 62, 30, 67, 12};

  int ylen = 5;
  float y[] = {32.16, 75.12, 65.3, 20.1, 6.603};

  int zlen = 9;
  double z[] = { 95.21, 96.12, 20.1, 6.603,32.16, 75.12, 65.3, 14.20, 78.36};


  double xAverage = findAverage(xlen, x);
  cout << "Average of integer array x: " << xAverage << endl;

  double yAverage = findAverage(ylen, y);
  cout << "Average of float array y: " << yAverage << endl;

  double zAverage = findAverage(zlen, z);
  cout << "Average of double array z: " << zAverage << endl;


  const char* charString = "Hello World!";
  string strString = "The quick brown fox jumps over the lazy dog.";

  int charStringCount = countLetters(charString);
  cout << "Number of letters in charString: " << charStringCount << endl;

  int strStringCount = countLetters(strString);
  cout << "Number of letters in strString: " << strStringCount << endl;

    return 0;
}