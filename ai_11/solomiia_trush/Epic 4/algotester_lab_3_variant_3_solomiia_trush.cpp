#include <iostream>
#include <string>
using namespace std;

int main () {
    long int k = 1;
    string line;
    cin >> line;

    string compressed_line = "";

    for (int l = 0; l < size(line)- 1; l++) {
        if (size(line)==1) {
            cout << line;
            return 0;
        }
        if (line[l] == line[l+1]) {
            k++;
        }
        else {
            if (k==1) {
                compressed_line += line[l];
            }
            else {
                compressed_line += line[l];
                compressed_line += to_string(k);
                k=1;
            }

        }
    }

    if (k==1) {
        compressed_line += line.back();
    }
    else {
        compressed_line += line.back();
        compressed_line += to_string(k);
    }

    cout << compressed_line << endl;

    return 0;
}