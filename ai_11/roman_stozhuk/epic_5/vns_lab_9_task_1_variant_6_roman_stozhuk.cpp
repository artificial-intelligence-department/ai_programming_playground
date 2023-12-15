#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char file_from[9] = "test.txt", file_to[11] = "copied.cpp";
    unsigned int n = 5, k = 9;
    ifstream in(file_from, ios::binary);
    ofstream out(file_to, ios::binary | ios::app);
    if ((!out) || (!in)) {cout << "Failure1\n";}
    string tmp;
    for (int i = 1; i < k; i++) {
        getline(in, tmp);
        if (i >= n) {out << tmp << '\n';}
    }
    if (out.ios::good() && in.ios::good()) {std::cout << "Success\n";}
    else {cout << "Failure2\n";}
    in.close(); out.close();
    ifstream new_in(file_to, ios::binary);
    if(!new_in) {cout << "Failure3\n";}
    unsigned int cononsants = 0;
    string check;
    while(getline(new_in, check)) {
        for (int i = 0; i<check.length(); i++) {
            if (check[i] == 'B' || check[i] == 'b' || check[i] == 'C' || check[i] == 'c' || 
                check[i] == 'D' || check[i] == 'd' || check[i] == 'F' || check[i] == 'f' || 
                check[i] == 'G' || check[i] == 'g' || check[i] == 'H' || check[i] == 'h' ||
                check[i] == 'J' || check[i] == 'j' || check[i] == 'K' || check[i] == 'k' || 
                check[i] == 'L' || check[i] == 'l' || check[i] == 'M' || check[i] == 'm' || 
                check[i] == 'N' || check[i] == 'n' || check[i] == 'P' || check[i] == 'p' ||
                check[i] == 'Q' || check[i] == 'q' || check[i] == 'R' || check[i] == 'r' || 
                check[i] == 'S' || check[i] == 's' || check[i] == 'T' || check[i] == 't' || 
                check[i] == 'V' || check[i] == 'v' || check[i] == 'W' || check[i] == 'w' || 
                check[i] == 'X' || check[i] == 'x' || check[i] == 'Z' || check[i] == 'z') ++cononsants;
        }
    }
    cout << cononsants;
    return 0;
}