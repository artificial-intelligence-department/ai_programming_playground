#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main()
{

    int  size_n = 3;
    int  size_m = 4;
    int  x = 2;
    int  y = 2;
    while (true) {

    cin >> size_n;
    cin >> size_m;
    cin >> x;
    cin >> y;
     

    
    int *map = new int [size_n,size_m];
    int xmax = -1;
    int ymax = -1;

    
    int status = 0;

    if (x <= size_n / 2) {
        xmax = 1;
    }
    else {
        xmax = size_n;
    }

    if (y <= size_m / 2) {
        ymax = 1;
    }
    else {
        ymax = size_m;
    }

   
    
    int max_value = (size_n - 1) + (size_m - 1) - (abs(x - xmax) + abs(y - ymax));
    //cout  << max_value << "\n";
   
    for (int i = 0; i < size_n; i++) {
        for (int j = 0; j < size_m; j++) {
            map[i, j] = max_value - (abs(x - (i + 1)) + abs(y - (j + 1)));

            cout << map[i, j] << " ";
        }
       cout << "\n";
    }
    delete [] map;
    char answer;
    cin >> answer;
    if (answer != 'y') {
        break;
    }

    }

}

