#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int findmax(vector<int> v){
    int maxi=0;
    for(auto &&element : v)
        maxi = max(maxi, element);
    return maxi;
}
int findmin(vector<int> v){
    int mini = v[0];
    for(auto &&element : v)
        mini = min(mini, element);
    return mini;
}
void findlong(vector<int>v, const char *str ){
    int pos = 0;
    int count = 0;
    int max = findmax(v);
    for(auto &element : v){
        if(max!=element){
            pos++;
        } else{
            break;
        }
    }

    for(int i=0; i<255; i++){
        if(str[i]==' '&&str[i+1]!=' '){
            count++;
        } 
        if(count == pos && str[i]!='.'){
            cout<<str[i];
        } else if( str[i]=='.'){
            break;
        }
    }
}
void findshort(vector<int>v, const char *str ){
    int pos = 0;
    int count = 0;
    int min = findmin(v);
    for(auto &element : v){
        if(min!=element){
            pos++;
        } else{
            break;
        }
    }

    for(int i=0; i<255; i++){
        if(str[i]==' '&&str[i+1]!=' '){
            count++;
        } 
        if(count == pos && str[i]!='.'){
            cout<<str[i];
        } else if( str[i]=='.'){
            break;
        }
    }
}


int main(){
    int i;
    int count = 0;
    char str[255];
    vector<int> scores;
    gets_s(str, 255);

    for(i=0;i<255;i++){
        if(str[i]!=' '&&str[i]!='.'){
            count++;
        } else if(str[i]==' '){
            scores.push_back(count);
            count = 0;
        } else {
        scores.push_back(count);
        break;
        }
    }
    cout<< "Here is longest word: ";
    findlong(scores,str);
    cout<<"\n"<<"Here is shortest word: ";
    findshort(scores, str);
}