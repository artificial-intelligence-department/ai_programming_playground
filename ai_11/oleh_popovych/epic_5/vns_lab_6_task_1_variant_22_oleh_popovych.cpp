//
// Created by olehio-p on 12/6/2023.
//
#include <iostream>
#include <cstring>

int startsWith(char*, char);

int main(int argc, char const *argv[])
{
    char src[255];
    std::cout << "Please enter the line: ";
    std::cin.getline(src, 256);
    printf("There are %d words that starts with %c\n", startsWith(src, 'a'), 'a');
    return 0;
}

int startsWith(char* line, char letter) {
    int counter = 0;
    char* token;
    token = strtok(line, " ");
    while(token) {
        if(*token == 'a') {
            counter++;
        }
        token = strtok(nullptr, " ");
    }
    return counter;
}
