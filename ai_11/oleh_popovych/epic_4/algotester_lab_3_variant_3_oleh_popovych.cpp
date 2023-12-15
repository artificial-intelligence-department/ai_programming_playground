//
// Created by olehio-p on 11/29/2023.
//
#include <iostream>
#include <string>


using namespace std;
int main(int argc, char const *argv[])
{
    string str, compressed_str;
    cin >> str;

    int occurrences = 1;
    int i = 0, j = 0;
    while(i < str.length()) {
        if(compressed_str.empty()) {
            compressed_str += str[i];
            i++;
        } else {
            if(str[i] != compressed_str[j]) {
                if(occurrences != 1) {
                    compressed_str += to_string(occurrences);
                    j += to_string(occurrences).length();
                    occurrences = 1;
                    continue;
                }
                compressed_str += str[i];
                i++;
                j++;
            } else {
                occurrences++;
                i++;
            }
        }
    }
    if(occurrences != 1)
        compressed_str += to_string(occurrences);
    cout << compressed_str << endl;
    return 0;
}


