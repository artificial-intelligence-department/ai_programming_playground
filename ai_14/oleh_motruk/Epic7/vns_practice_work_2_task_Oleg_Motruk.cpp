#include <iostream>
#include <cmath>

using namespace std;

void result_x(float x, float a){
    if(x > 3.0){
        return;
    }

    float result = cos(x) - 1.0 / (a + 1);

    cout << "X: " << x << "\t Result: " << result << endl;

    result_x(x + 0.5, a);


}

int main(){
    float a = 2.4;
    float startingX = -3;


    result_x(startingX, a);

    return 0;
}