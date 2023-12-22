#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int x,y;
    vector<vector<char>>a(8,vector<char>(8));
    vector<vector<string>>b(8,vector<string>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin>>a[i][j];
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 'P') {
                if (i+1 != 8) {
                    if(j+1!=8){
                        b[i+1][j+1]+='P';
                    
                    } 
                    if(j-1>=0){
                        b[i+1][j-1]+='P';
                    }
                }
            } else if (a[i][j] == 'R') {
                x=i-1;
                y=j;
                while (x>=0 ){
                    b[x][y]+='R';
                    x--;
                }
                x=i+1;
                y=j;
                while (x<8 ){
                    b[x][y]+='R';
                    x++;
                }
                x=i;
                y=j-1;
                while (y>=0 ){
                    b[x][y]+='R';
                    y--;
                }
                x=i;
                y=j+1;
                while (y<8 ){
                    b[x][y]+='R';
                    y++;
                }
            } else if (a[i][j]=='N') {
                x=i+1;
                y=j+2;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i+2;
                y=j+1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i+1;
                y=j-2;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i-1;
                y=j+2;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i-2;
                y=j+1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i-2;
                y=j-1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i-1;
                y=j-2;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
                x=i+2;
                y=j-1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='N';
                }
            } else if (a[i][j]=='B'){
                x=i-1;
                y=j-1;
                while (x>=0 && y>=0 && x<8 && y<8 ) {
                    b[x][y]+='B';
                    x--;
                    y--;
                }
                x=i-1;
                y=j+1;
                while (x>=0 && y>=0 && x<8 && y<8 ) {
                    b[x][y]+='B';
                    x--;
                    y++;
                }
                x=i+1;
                y=j-1;
                while (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='B';
                    x++;
                    y--;
                }
                x=i+1;
                y=j+1;
                while (x>=0 && y>=0 && x<8 && y<8 ) {
                    b[x][y]+='B';
                    x++;
                    y++;
                }
            } else if (a[i][j]=='K'){
                x=i-1;
                y=j-1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i-1;
                y=j;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i-1;
                y=j+1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i;
                y=j-1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i;
                y=j+1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i+1;
                y=j-1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i+1;
                y=j;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
                x=i+1;
                y=j+1;
                if (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='K';
                }
            } else if (a[i][j]=='Q'){
                x=i-1;
                y=j;
                while (x>=0 ){
                    b[x][y]+='Q';
                    x--;
                }
                x=i+1;
                y=j;
                while (x<8 ){
                    b[x][y]+='Q';
                    x++;
                }
                x=i;
                y=j-1;
                while (y>=0){
                    b[x][y]+='Q';
                    y--;
                }
                x=i;
                y=j+1;
                while (y<8){
                    b[x][y]+='Q';
                    y++;
                }
                x=i-1;
                y=j-1;
                while (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='Q';
                    x--;
                    y--;
                }
                x=i-1;
                y=j+1;
                while (x>=0 && y>=0 && x<8 && y<8 ) {
                    b[x][y]+='Q';
                    x--;
                    y++;
                }
                x=i+1;
                y=j-1;
                while (x>=0 && y>=0 && x<8 && y<8 ) {
                    b[x][y]+='Q';
                    x++;
                    y--;
                }
                x=i+1;
                y=j+1;
                while (x>=0 && y>=0 && x<8 && y<8) {
                    b[x][y]+='Q';
                    x++;
                    y++;
                }
            }
        }
    }
    int test;
    cin>>test;
    while (test--){
        cin>>x>>y;
        x--;
        y--;
        if (a[x][y]!='O'){
            cout<<'X'<<endl;
        }else if (b[x][y].length()==0){
            cout<<'O'<<endl;
        }else{
            set<char>st;
            for (auto p : b[x][y]){
                st.insert(p);
            }
            for (auto p : st){
                cout<<p;
            }
            cout<<endl;
        }
    }
    return 0;
}













