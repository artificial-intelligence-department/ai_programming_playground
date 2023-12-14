#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int hr_count;
    cout << "Enter count of pucks: ";
    cin >> hr_count;

    long long month_count = hr_count * 7 * 26;
    cout << "A worktable produces " << month_count << " pucks in 1 month";
    
    return 0;
}