#include <iostream>
#include <string>

int main() {
    
    std::string S;
    std::cin >> S;    
    std::string compress;

    
    for (int i = 0; i < S.size(); ++i) 
    {    
        char curr_char = S[i];
        int count = 1;

        
        while (i + 1 < S.size() && S[i + 1] == curr_char)
        {
            ++count;
            ++i;
        }

        compress += curr_char;

        if (count > 1) {
            compress += std::to_string(count);
        }
    }
    std::cout << compress << std::endl;
    return 0;
}
