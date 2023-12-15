#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
int a;
vector<int> number;

cout<<"The size of vector"<<endl;
cin >>a;
for(int i = 0;i<a ;i++){
    int elements;
    cin >> elements;
    number.push_back(elements);
}
for(auto n = number.begin();n != number.end();){
    if(*n % 2 ==0){
       n = number.erase(n);
    }
    else{n++;}
}


cout << "Elements of vector: ";
    for (int num : number) {
        cout << num << " ";
    }
cout <<endl;
vector<string> words;
int sizeOfrWords;
cout <<"Size of sentence "<<endl;
cin >> sizeOfrWords;

for(int j=0;j<sizeOfrWords;j++){
    string w;
    cin >> w;
    words.push_back(w);
}
string resultString;
for (int i = 0; i < words.size(); ++i) 
    {
        if (i % 2 == 0) {
            resultString += words[i] + " ";
        }
    }

    cout << resultString <<endl;
}