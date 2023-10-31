#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of rounds: ";
    cin >> n;
    while  (n < 1 || n > 100000LL) {
        cout << "The number of rounds must be from 1 to 100000.\n";
        cout << "Enter the number of rounds: ";
        cin >> n;           
}
    for (int i = 0; i < n; i++)
    {
        if (n % 2 == 0) {
        cout << "The number of rounds must be odd.\n";
        cout << "Enter the number of rounds: ";
        cin >> n;
    }
    }
vector<int> a(n);      
vector<int> b(n);
 for (int i = 0; i < n; i++) {
    cout << "Enter your " << i+1 << " card number: ";
        cin >> a[i];
         if (a[i] > 2*n)
    {
        cout << "The number cannot be more than the number of cards\n";
        cout << "Enter your " << i+1 << " card number: ";
        cin >> a[i];
    }
    }
    for (int i = 0; i < n; i++) {
         cout << "Enter the opponent\'s " << i+1 << " card number: ";
        cin >> b[i];
        if (b[i] > 2*n)
    {
        cout << "The number cannot be more than the number of cards\n";
        cout << "Enter the opponent\'s " << i+1 << " card number: ";
        cin >> b[i];
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
    {
        cout << "Your and your opponent's numbers cannot be the same\n";
        cout << "Enter the opponent\'s " << i+1 << " card number: ";
        cin >> b[i];}
    }
int yourWins = 0;
int opponentWins = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            yourWins++;
        } else if (a[i] < b[i]) {
            opponentWins++;
             }
    }
    if (yourWins > opponentWins) {
        cout << "Possible";
    } else if (yourWins < opponentWins) {
        cout << "Impossible";
      }    
    return 0;
}




