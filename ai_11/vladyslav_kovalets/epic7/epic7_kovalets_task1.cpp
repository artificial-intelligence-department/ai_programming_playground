#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>

// 14. в коді використано структури 
struct Point 
{
    int x, y;
};

bool file(const char *name, const char *content)
{
    //19. в коді використано функції роботи з файлами, для того, щоб записати у файл
    std::ofstream outputFile(name);
    if (!outputFile.is_open()) 
    {
        std::cout << "Unable to open" << std::endl;
        return 0;
    }

    //11. в коді використано оператори break і continue
    int i = 0;
    for(;i!=5;)
    {
        if(i==4)
        {
            break;
        }
        else
        {
            i++;
            continue;
        }
    }

    //20. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    std::istringstream contentStream(content); 
    std::string line1;

    while (std::getline(contentStream, line1)) 
    {
        if (!line1.empty()) 
        {
            outputFile << line1 << std::endl;
        }
    }
    outputFile.close();
    return 1;
}

int main() 
{
    // 1. в коді використана як мінімум одна цілочисельна змінна
    int x = 2, y = 2; 

    // 2. в коді використана як мінімум одна дійсна змінна
    // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double a = (sqrt(std::abs(x - 1)) - sqrt(y)) / (1 + std::pow(x, 2) / 2 + std::pow(y, 2) / 4);
    std::cout << "A = " << a << std::endl;

    double b = 1 / (tan(exp(x)));
    std::cout << "B = " << b;

    // Додавання структури
    Point point;
    point.x = 5;
    point.y = 7;


    const char *nameCStr = "f1";
    const char *contentCStr = "f2";
    int result = file(nameCStr, contentCStr);
}
