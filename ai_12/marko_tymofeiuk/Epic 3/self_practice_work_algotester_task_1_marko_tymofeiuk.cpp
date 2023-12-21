#include <iostream>
#include <vector>

int main (){
    int numof;
    std::cin >> numof;

    std::vector <char> vector;
    for (int i = 0; i < numof; i++){
        char input;
        std::cin >> input;
        vector.push_back(input);
    }

    int signal = 15;
    for (int i = 0; i < numof; i++){
        if(vector[i] == 'k' && signal > 0){
            signal--;
        } else if (vector [i] == 'p'){
            if (signal >= 1){
                signal = 15;
            }
        } else if (vector[i] == 'z'){
            if (signal > 0){
                signal = 0;
            } else if (signal == 0){
                signal = 15;
            }            
        }
    }
    std::cout << signal;
}