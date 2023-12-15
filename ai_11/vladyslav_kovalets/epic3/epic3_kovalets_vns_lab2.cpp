#include <iostream>

int main() 
{
    int suma;
    for(int i = 0; i < 100; i++)
    {
        if(i % 2 == 0)
        suma = suma + i;        
    }
    std::cout << "Suma of the first 100 even numbers: " << suma;

    return 0;
}
