#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
char pawn(int a, int b, int c, int d){
if( a == c && b == d)
return 'X';
else if(c-a == 1 && abs(b-d) == 1)
return 'P';
else{
    return 0;
}
}
char tour(int a, int b, int c,int d){
if( a == c && b == d)
return 'X';
else if(a == c || b == d)
return 'R';
 
else{
    return 0; 
}
}
char elephent(int a, int b, int c, int d){
if( a == c && b == d)
return 'X';
else if(abs(a-c) == abs(b-d))
return 'B';
else{
    return 0; 
}
}
char hourse(int a, int b, int c,int d){
    if( a == c && b == d)
    return 'X';
    else if(abs(a-c) == 2 && abs(d-b) == 1 || abs(a-c) == 1 && abs(d-b) == 2)
    return 'N';
else{
    return 0; 
}
}
char queen(int a, int b, int c, int d){
if(a == c && b == d)
return 'X';
else if(a == c || b == d || abs(a-c) == abs(b-d))
return 'Q';
else{
    return 0;
}
}
char king(int a, int b, int c, int d){
if(a == c && b == d)
return 'X';
else if( abs(a-c) <= 1 && abs(b-d) <= 1)
return 'K';
else{
    return 0;
}
}
bool check(const std::string &str){
for(int i = 0; i < str.size(); i++){
if((str)[i] == 'R' || (str)[i] == 'P'|| (str)[i] == 'R'|| (str)[i] == 'B'|| (str)[i] == 'N'|| (str)[i] == 'Q'|| (str)[i] == 'K' || (str)[i] == 'X'){
return false;
}

}
    return true;
}





int main(){
    using namespace std;
    char board[8][8];
     vector<string> result;
    vector<char> sym;
    vector<int> position1;
    vector<int> position2;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
        cin >> board[i][j];
        if(board[i][j] != 'O'){
        sym.push_back(board[i][j]);
        position1.push_back(i);
        position2.push_back(j);
        }
        }
    }
    int n, x,y;
    cin >> n;
    for(int t = 0;t < n; t++){
    cin >> x >> y;
    string answear;
    answear.clear();


       for (int i = 0; i < sym.size(); i++) {
    char resultChar = 0;  // Ініціалізуємо символ значенням 0 (нуль), яке не є дійсним символом.

    switch (sym[i]) {
        case 'P':
            resultChar = pawn(position1[i] + 1, position2[i] + 1, x, y);
            break;
        case 'R':
            resultChar = tour(position1[i] + 1, position2[i] + 1, x, y);
            break;
        case 'B':
            resultChar = elephent(position1[i] + 1, position2[i] + 1, x, y);
            break;
        case 'N':
            resultChar = hourse(position1[i] + 1, position2[i] + 1, x, y);
            break;
        case 'Q':
            resultChar = queen(position1[i] + 1, position2[i] + 1, x, y);
            break;
        case 'K':
            resultChar = king(position1[i] + 1, position2[i] + 1, x, y);
            break;
    }

    if (isalpha(resultChar)) {
        answear += resultChar;
    }
}
 
        
        result.push_back(answear);
}

    for(int i = 0; i< result.size(); i++){
    if(check(result[i])){
    cout << 'O' << endl; 
    if(i == result.size()-1)
    break;
    else{
    continue;
    }
    }
    size_t position = result[i].find('X');
    if(position != std::string::npos ){
    cout << "X" << endl;
    }
    else{
    sort(result[i].begin(), result[i].end());
    auto it = unique(result[i].begin(), result[i].end());
    result[i].erase(it, result[i].end());
    cout << result[i] << endl;
    }
    }

    return 0;
}