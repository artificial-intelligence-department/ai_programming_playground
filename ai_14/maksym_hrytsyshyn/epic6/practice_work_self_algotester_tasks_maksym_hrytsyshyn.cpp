#include <iostream>
#include <vector>

using namespace std;

int main() {
   #include <iostream>

int main() {
    int n, k;
    cin >> n >> k;

    int per = n / k;
    int remainder = n % k;

    if (remainder == 0 || (remainder == 1 && k > 1)) {
        for (int i = 0; i < k; ++i) {
            int team = (remainingStudents > 0) ? studentsPerTeam + 1 : studentsPerTeam;
            cout << teamSize << " ";
            remainingStudents = max(0, remainingStudents - 1);
        }
        cout << endl;
    } else {
       
        cout << "Impossible" << endl;
    }

    return 0;
}

}