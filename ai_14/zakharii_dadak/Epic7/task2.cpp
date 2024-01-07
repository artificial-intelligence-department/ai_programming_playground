#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

    vector<vector<double>> vector2D;

    for (int i = 0; i < 5; ++i) {
        vector<double> temp;
        for (int j = 0; j < 2; ++j) {
            double x;
            cin >> x;
            temp.push_back(x);
        }
        vector2D.push_back(temp);
    }
    int R,a,b;
    cin>>R>>a>>b;


    for (int i = 0; i < 5; ++i) {
        if ((pow((vector2D[i][0] - a), 2) + pow((vector2D[i][1] - b), 2)) <= pow(R, 2)) {
            cout << "Dot is in the circle" << endl;
        } else {
            cout << "Dot is out the circle" << endl;
        }
    }


}
