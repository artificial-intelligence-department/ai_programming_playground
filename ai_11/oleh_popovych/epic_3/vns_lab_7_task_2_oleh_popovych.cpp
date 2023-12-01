//
// Created by olehio-p on 11/23/2023.
//
#include <iostream>
#include <string>
#include <sstream>


int find(int*);
int find(const std::string&);

int main(int argc, char const *argv[])
{
    int arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << find(arr) << std::endl;
    std::string str = "Hello, world. Where is my name. Who I am? Shit happens";
    std::cout << find(str) << std::endl;
    return 0;
}

int find(int* ptr_i) {
    int counter = 0;

    while(*ptr_i) {
        if(*(ptr_i++) % 2 != 0) {
            counter++;
        }
    }
    return counter;
}

int find(const std::string& str) {
    int counter = 0;
    std::string token;
    std::stringstream Stream(str);

    while(std::getline(Stream, token, ' ')) {
        counter++;
    }

    return counter;
}