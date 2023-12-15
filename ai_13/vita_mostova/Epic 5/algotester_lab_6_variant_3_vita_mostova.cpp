#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Coordinates{
    int x;
    int y;
};
vector<int> Variantu(const vector <vector<int>>& array, const vector<Coordinates>& coordinates);
int main (){

int N;

cin>>N;
if(N<1 || N>9){
    return 0;
}
vector<vector<int>> pole(N,vector<int>(N));
string row;
for(int i=0;i<N;i++){
    cin>>row;
   
    for(int j=0;j<N;j++){
        pole[i][j] = row[j] - '0';
    }
}
int Q;
cin>>Q;
vector <Coordinates> coordinates;
for(int k=0;k<Q;k++){
    Coordinates position;
cin>>position.x>>position.y;
coordinates.push_back(position);
for(int t=0;t<Q;t++){
if (pole[position.x-1][position.y-1]==0){ //
vector<int> yourOptions=Variantu(pole,coordinates);
    cout<<yourOptions.size()<<endl;
    for(int &element : yourOptions){
        cout<<element<<endl;
    }
}}}

return 0;}

vector<int> Variantu(const vector <vector<int>>& array, const vector<Coordinates>& coordinates){
    
    vector<int> PossibleNumbers;
    for(int i=1;i<=array.size();i++){
        PossibleNumbers.push_back(i);
    }
    for(int j=0;j<coordinates.size();j++){
        if(array[coordinates[j].x-1][j] !=0){
            auto it=find(PossibleNumbers.begin(),PossibleNumbers.end(),array[coordinates[j].x-1][j]); //перебираєм рядок 
            if (it != PossibleNumbers.end()) {
            PossibleNumbers.erase(it);
        }}
        if(array[j][coordinates[j].y-1] !=0){
           auto it=find(PossibleNumbers.begin(),PossibleNumbers.end(),array[j][coordinates[j].y-1]); //перебираєм стовпець
            if (it != PossibleNumbers.end()) {
            PossibleNumbers.erase(it);}
    }}
  
return PossibleNumbers;
}


