#include <iostream>
#include <string>

int main() {
    std::string s, sComp;
    int counter;

    std::cin >> s;
    counter = 1;

    for(int i = 0; i < s.length(); i++){

        if(s[i] == s[i + 1]){
            counter ++;
        }else {
            sComp += s[i];
            if(counter != 1){
                sComp += std::to_string(counter);
            }

            counter = 1;
        }
    }

    std::cout << sComp;

    return 0;
}