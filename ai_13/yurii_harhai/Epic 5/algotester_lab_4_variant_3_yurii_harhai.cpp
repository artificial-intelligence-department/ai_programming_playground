#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ost0;
vector<int> ost1;
vector<int> ost2;
vector<int> final;
bool sortDescending(int, int);
int main(){
    int N;
    cin >> N;
    int chusla[N];
    for(int i=0; i<N; i++){
        cin >> chusla[i];
    }

    for(int i=0; i<N; i++){
        if((chusla[i] % 3) == 0){
            ost0.push_back(chusla[i]);}

        else if((chusla[i] % 3) == 1){
            ost1.push_back(chusla[i]);}

        else if((chusla[i] % 3) == 2){
            ost2.push_back(chusla[i]);}
    }

    sort(ost0.begin(), ost0.end());
    ost0.erase(unique(ost0.begin(), ost0.end()), ost0.end());

    sort(ost1.begin(), ost1.end(), sortDescending);
    ost1.erase(unique(ost1.begin(), ost1.end()), ost1.end());

    sort(ost2.begin(), ost2.end());
    ost2.erase(unique(ost2.begin(), ost2.end()), ost2.end());



    for(int i=0; i<ost0.size(); i++)
        final.push_back(ost0.at(i));

    for(int i=0; i<ost1.size(); i++)
        final.push_back(ost1.at(i));
        
    for(int i=0; i<ost2.size(); i++)
        final.push_back(ost2.at(i));


    cout << final.size() << endl;
    for(int i=0; i<final.size(); i++)
        cout << final.at(i)<< " ";
return 0;
}

bool sortDescending(int a, int b) {
    return a > b;}