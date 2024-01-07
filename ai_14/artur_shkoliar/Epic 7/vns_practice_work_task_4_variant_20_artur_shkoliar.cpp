#include <iostream>
#include <cmath>
#include <cstdarg>
#include <fstream>

using namespace std;

// Функція для розрахунку та виведення таблиці для типу double 
void calcDouble(double x, double k, double end, ...) 
{
  // 13. в коді використано еліпсис(але він нічого не робить)
  va_list args;

  va_start(args, end); 

  va_end(args);

  if (x > end) 
  {
    return;
  }
  
  cout << "Double " << endl;

  // Відкриття файлу для запису
  ofstream outputFile("output.txt");

  cout << "| " << "Х: " << "| " << "Y: " << "| " << endl;
  // 9. в коді використаний while цикл
  while (x <= end) 
  {
    cout << "| " << x << " | " << abs(x - 2) + abs(x + 1) << " |" << endl;
    
    // 19. в коді використано функції роботи з файлами, для того, щоб записати у файл
    outputFile << x << " " << abs(x - 2) + abs(x + 1) << endl;

    x += k; 
  }

  outputFile.close();
}

// 12. в коді використано перевантаження функції 
void calcFloat(float x, float k, float end) 
{
  // 5. в коді використані умовні оператори та розгалуження
  if (x > end) 
  {
    return;
  }
  
  cout << "Float " << endl;

  ofstream outputFile("output.txt", ios::app);

  cout << "| " << "Х: " << "| " << "Y: " << "| " << endl;

  //8. в коді використаний do while цикл
  do 
  {
    cout << "| " << x << " | " << abs(x - 2) + abs(x + 1) << " |" << endl;

   
    outputFile << x << " " << abs(x - 2) + abs(x + 1) << endl;

    x += k; 
  } 
  while (x <= end);

  outputFile.close();
}

void readFromFile(const string& filename) 
{
  ifstream inputFile(filename);

  if (inputFile.is_open()) 
  {
    cout << "Читання з файлу " << filename << ":" << endl;

    double x, value;
    
    while (inputFile >> x >> value) 
    {
      cout << "| " << x << " | " << value << " |" << endl;
    }

    inputFile.close();
  } 
  else 
  {
    cerr << "Помилка відкриття файлу " << filename << endl;
  }
}

int main() 
{
  const float k = 0.5;
  int x = -4;
  double end = 4.0; 

  calcDouble((double)x, k, end);

  calcFloat((float)x, k, (float)end);

  // 20. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
  readFromFile("output.txt");

  return 0;
}
