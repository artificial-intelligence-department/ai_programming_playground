#include<iostream>
using namespace std;

int main(){
    //Депутатські гроші. Вводимо кількість грошей і вираховуємо мінімальну кількість купюр
    int a[] = {500, 200, 100, 50 ,20 , 10, 5, 2, 1};
    start: cout<<"Enter the value of your money"<<endl;
    int n, c = 0;
    cin>>n;
    for(int i = 0; i < 9; i++){
        while(n >= a[i]){
            c++;
            n -= a[i];
        }
    } 
    cout<<"Minimal amount of the banknotes is "<<c<<endl;
    
    string s;
    cout<<"If you want to do it again then write 'Restart'"<<endl;
    cin>>s;
    if(s == "Restart") goto start;
    else return 0;
}