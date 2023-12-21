//
// Created by olehio-p on 11/29/2023.
//
#include <iostream>


using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;

    int b[m];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }


    int intersection = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                intersection++;
                break;
            }
        }
    }

    int i = 0, j = 0, unique = 0;
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            unique++;
            i++;
        } else if(a[i] > b[j]) {
            unique++;
            j++;
        } else {
            unique++;
            i++;
            j++;
        }
    }
    while(i < n) {
        unique++;
        i++;
    }
    while(j < m) {
        unique++;
        j++;
    }
    cout << intersection << endl;
    cout << unique << endl;
    return 0;
}

