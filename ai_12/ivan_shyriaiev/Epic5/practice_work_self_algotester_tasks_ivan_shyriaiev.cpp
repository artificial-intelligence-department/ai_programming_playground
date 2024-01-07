#include<iostream>
#include<string>
using namespace std;
int customsize(string &str){
    int count = 0;

    for(char &ch : str ){
        count++;
    }

    return count;
}
int main(){
    string ribbon;
    cin>>ribbon;

    int counter_even = 0, counter_odd = 0;
//YBYB або BYBY
    for (int i = 0; i < customsize(ribbon); ++i) {
        if ((i%2==0 && ribbon[i]!='B')||(i%2==1 && ribbon[i]!='Y')) {
            ++counter_even;
        }
        if ((i%2==0 && ribbon[i]!='Y') || (i%2==1 && ribbon[i]!='B')) {
            ++counter_odd;
        }
    }

    cout<< min(counter_even, counter_odd);

    return 0;
}