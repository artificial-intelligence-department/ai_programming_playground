#include <iostream>
#include <vector>
#include <string>

using namespace std;
int kabel(int&);
int povtoruvach (int&);
int zminuvach (int&);
string a;
vector<char> blocks;
int k {15};
size_t rozmir {};

int main(){
    cin >> rozmir;
    cin >> a;
        for (int i = 0; i<a.size(); i++){
            blocks.push_back(a.at(i));
   
        }

    for (int i = 0; i<blocks.size(); i++){
         if (blocks.at(i) == 'k'){
            kabel(k);
        }

        else if (blocks.at(i) == 'p'){
            povtoruvach(k);
        }
        
        else if (blocks.at(i) == 'z'){
            zminuvach(k);
        }
    }
    cout << k;

}

int kabel(int &k){
    k = (k-1);
    if (k<0)
        k=0;
return k;
}

int povtoruvach (int &k){
    if (k>0){
        k=15;
    }
    else if(k<=0){
        k=0;
    }
return k;
}

int zminuvach (int &k){
    if (k<=0){
        k=15;
    }
    else if(k>0){
        k=0;
    }
return k;
}