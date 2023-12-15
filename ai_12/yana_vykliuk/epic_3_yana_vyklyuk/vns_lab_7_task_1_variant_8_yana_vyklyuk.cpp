#include <iostream>
#include <cstdarg>

int min(int amount, ...)
{
    va_list numbers;
    va_start(numbers, amount);
    
    int min_number = va_arg(numbers, int);
    
    for (int arg = 1; arg < amount; arg++)
    {
        int current_number = va_arg(numbers, int);
        
        if (current_number < min_number)
        {
            min_number = current_number;
        }
    }

    va_end(numbers);

    return min_number;
}

int max(int count, ...)
{
    va_list values;
    va_start(values, count);

    int max_value = va_arg(values, int);

    for (int arg = 1; arg < count; arg++)
    {
        int current_value = va_arg(values, int);
        
        if (current_value > max_value)
        {
            max_value = current_value;
        }
    }

    va_end(values);

    return max_value;
}

int main()
{
    int minimum1 = min(5, 12, 45, 3, 78, 68);
    int maximum1 = max(5, 12, 45, 3, 78, 68);
    
    int minimum2 = min(10, -6, 23, 1, -69, 114, 13, 26, -2, 43, 5);
    int maximum2 = max(10, -6, 23, 1, -69, 114, 13, 26, -2, 43, 5);
    
    int minimum3 = min(12, 321, 0, 87, -101, 100, 307, 6, 33, 562, 10, -7, -101);
    int maximum3 = max(12, 321, 0, 87, -101, 100, 307, 6, 33, 562, 10, -7, -101);
    
    printf("Minimal number: %d\n", minimum1);
    printf("Maximal number: %d\n\n", maximum1);
    
    printf("Minimal number: %d\n", minimum2);
    printf("Maximal number: %d\n\n", maximum2);
    
    printf("Minimal number: %d\n", minimum3);
    printf("Maximal number: %d\n", maximum3);

    return 0;
}
