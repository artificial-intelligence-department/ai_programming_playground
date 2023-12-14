#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int N {};
double num {};
double sum {};
double mean {};
vector<double>chusla;

int main(){
    cout << fixed << setprecision(3);
    cout <<"Enter the amount of numbers u want to check: ";
    cin >> N;
    cout << "Enter numbers separated by space: ";
    for(size_t i = 0; i<N; i++){
        cin >> num;
        chusla.push_back(num);
    }    
        for(size_t i = 0; i<chusla.size(); i++){
        sum +=chusla.at(i);
    } 
    mean = sum/N;
    cout << "Mean of numbers is:" << mean;
return 0;
}