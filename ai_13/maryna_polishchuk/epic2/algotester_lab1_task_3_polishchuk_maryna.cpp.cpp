#include <iostream>

int main() {
   long long num[5];

    for(int i = 0; i < 5; i++) 
    {
        
        std::cin >> num [i];
    
        
        if (num [i]<=0)
        {
            std::cout<<"ERROR";
            return 0;
        }
        else if (num[i-1]<num[i])

        {
            std:: cout << "LOSS";
            return 0;
        }
    }
    std:: cout <<"WIN";
    return 0;
}
