#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n, m, l[100];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> l[i];
    }
    int max = l[0];
    for(int i = 1; i < m; i++){
        if(l[i]>max)
            max = l[i];
    }
    double left = 0, right = max;
    double length, try_length = max;
    int number = 0;
    for(int i = 0; i < m; i++){
        double current = l[i];
        while(current-try_length>=0){
            current-=try_length;
            number++;
        }
    }
    if(number>=n){
        length = try_length;
    } else{
        number = 0;
        try_length = (left + right)/2;
        for(int i = 0; i < m; i++){
            double current = l[i];
            while(current-try_length>=0){
                current-=try_length;
                number++;
            }
        }
        while(right - left > 0.00000001){
            if(number >= n){
                left = try_length;
                length = try_length;
            } else {
                right = try_length;
            }
            number = 0;
            try_length = (left + right)/2;
            for(int i = 0; i < m; i++){
                double current = l[i];
                while(current-try_length>=0){
                    current-=try_length;
                    number++;
                }
            }
        }
    }
    cout << setprecision(8) << length << endl;
    return 0;
}