#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string results;
    std::cin >> results;

    int K_count = 0, V_count = 0; 
    int K_score = 0, V_score = 0; 

    for (int i = 0; i < n; ++i) {
        if (results[i] == 'K') {
            K_score++;
        } else {
            V_score++;
        }

        
        if ((K_score >= 11 || V_score >= 11) && abs(K_score - V_score) >= 2) {
            if (K_score > V_score) {
                K_count++;
            } else {
                V_count++;
            }
            K_score = V_score = 0; 
        }
    }

    
    std::cout << K_count << ":" << V_count << std::endl;

    
    if (K_score > 0 || V_score > 0) {
        std::cout << K_score << ":" << V_score << std::endl;
    }

    return 0;
}

