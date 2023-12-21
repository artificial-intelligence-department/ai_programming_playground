#include <iostream>

int main()
{
    int n, max, min, x,y, temp, suma1;
    bool on = 1;
    unsigned long long arr[100000], suma[100000];
    std::cin >> n;
    max = 0;
    for(int i=0; i < n; i++)
    {
        std::cin >> arr[i];
        if(max < arr[i])
        {
            max = arr[i];
        }
        if(min > arr[i])
        {
            min = arr[i];
        }
    }

    std::cout << max << "   "  <<min << std::endl;

    for(int i=1; i < sizeof(arr); i++)
    {
        if(max % i == 0 && min % i == 0 )
        {
            x = max/i;
            y = min/i;
            temp = i;
            for(int j=0; j < n; j++)
            {
                if(suma[j] % temp == 0)
                {
                    suma[j] = arr[j]/temp;
                }
                else
                {
                    on = 0;
                    break;
                }
                
            }
        }
         if(on==true)
            {
                for(int i = 0; i < n; i++)
                {
                    suma1 += suma[i];
                }
            }
    }

    std::cout << temp << std::endl;


    std::cout << suma1;



    

    

}