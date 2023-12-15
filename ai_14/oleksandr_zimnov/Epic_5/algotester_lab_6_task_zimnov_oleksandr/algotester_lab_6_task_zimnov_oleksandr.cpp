#include <iostream>
#include <string>
using namespace std;

bool ValidTemp(int temp[2]) {
    bool result = true;
    for (int i = 0; i < 2; i++) {
        if (temp[i] < 0 || temp[i]>7)
            result = false;
    }
    return result;
}
string Peshka(string mas[8][8], int position[][2], int step, string answer) {
    int temp[2];
    bool check=true;
    for (int i = -1; i <= 1; i += 2) {
        temp[0] = position[step][0] - 1;
        temp[1] = position[step][1] - i;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "P") {
                if (answer == "O") {
                    answer = "P";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='P')
                        check=false;
                    }
                    if(check)
                    answer += "P";
                }  
            }
        }
    }
    return answer;
}
string Tura(string mas[8][8], int position[][2], int step, string answer) {
    int temp[2];
    bool check=true;
    for (int i = 0; i < 8; i++) {
            temp[0] = i;
            temp[1] = position[step][1];
            if (ValidTemp(temp)) {
                if (mas[temp[0]][temp[1]] == "R") {
                    if (answer == "O") {
                        answer = "R";
                    }
                    else {
                        for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='R')
                        check=false;
                    }
                    if(check)
                        answer += "R";
                    }
                }
            }
    }
    for (int i = 0; i < 8; i++) {
            temp[0] = position[step][0];
            temp[1] = i;
            if (ValidTemp(temp)) {
                if (mas[temp[0]][temp[1]] == "R") {
                    if (answer == "O") {
                        answer = "R";
                    }
                    else {
                        for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='R')
                        check=false;
                    }
                    if(check)
                        answer += "R";
                    }
                }
            }
    }
    return answer;
}
string King(string mas[8][8], int position[][2], int step, string answer) {
    int temp[2];
    bool check=true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
                temp[0] = position[step][0] + j;
                temp[1] = position[step][1] + i;
                if (ValidTemp(temp)) {
                    if (mas[temp[0]][temp[1]] == "K") {
                        if (answer == "O") {
                            answer = "K";
                        }
                        else {
                            for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='K')
                        check=false;
                    }
                    if(check)
                            answer += "K";
                        }
                    }
                }
        }
    }
    return answer;
}
string Slon(string mas[8][8], int position[][2], int step, string answer) {
    int temp[2];
    bool check=true;
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] >= 0 || temp[1] >= 0) {
        temp[0]--;
        temp[1]--;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "B") {
                if (answer == "O") {
                    answer = "B";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='B')
                        check=false;
                    }
                    if(check)
                    answer += "B";
                }
            }
        }
    }
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] <= 7 || temp[1] >= 0) {
        temp[0]++;
        temp[1]--;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "B") {
                if (answer == "O") {
                    answer = "B";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='B')
                        check=false;
                    }
                    if(check)
                    answer += "B";
                }
            }
        }
    }
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] >= 0 || temp[1] <= 7) {
        temp[0]--;
        temp[1]++;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "B") {
                if (answer == "O") {
                    answer = "B";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='B')
                        check=false;
                    }
                    if(check)
                    answer += "B";
                }
            }
        }
    }
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] <= 7 || temp[1] <= 7) {
        temp[0]++;
        temp[1]++;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "B") {
                if (answer == "O") {
                    answer = "B";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='B')
                        check=false;
                    }
                    if(check)
                    answer += "B";
                }
            }
        }
    }
    return answer;
}
string Queen(string mas[8][8], int position[][2], int step, string answer) {
    int temp[2];
    bool check=true;
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] >= 0 || temp[1] >= 0) {
        temp[0]--;
        temp[1]--;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "Q") {
                if (answer == "O") {
                    answer = "Q";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='Q')
                        check=false;
                    }
                    if(check)
                    answer += "Q";
                }
            }
        }
    }
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] <= 7 || temp[1] >= 0) {
        temp[0]++;
        temp[1]--;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "Q") {
                if (answer == "O") {
                    answer = "Q";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='Q')
                        check=false;
                    }
                    if(check)
                    answer += "Q";
                }
            }
        }
    }
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] >= 0 || temp[1] <= 7) {
        temp[0]--;
        temp[1]++;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "Q") {
                if (answer == "O") {
                    answer = "Q";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='Q')
                        check=false;
                    }
                    if(check)
                    answer += "Q";
                }
            }
        }
    }
    temp[0] = position[step][0];
    temp[1] = position[step][1];
    while (temp[0] <= 7 || temp[1] <= 7) {
        temp[0]++;
        temp[1]++;
        if (ValidTemp(temp)) {
            if (mas[temp[0]][temp[1]] == "Q") {
                if (answer == "O") {
                    answer = "Q";
                }
                else {
                    for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='Q')
                        check=false;
                    }
                    if(check)
                    answer += "Q";
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
            temp[0] = i;
            temp[1] = position[step][1];
            if (ValidTemp(temp)) {
                if (mas[temp[0]][temp[1]] == "Q") {
                    if (answer == "O") {
                        answer = "Q";
                    }
                    else {
                        for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='Q')
                        check=false;
                    }
                    if(check)
                        answer += "Q";
                    }
                }
            }
    }
    for (int i = 0; i < 8; i++) {
            temp[0] = position[step][0];
            temp[1] = i;
            if (ValidTemp(temp)) {
                if (mas[temp[0]][temp[1]] == "Q") {
                    if (answer == "O") {
                        answer = "Q";
                    }
                    else {
                        for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='Q')
                        check=false;
                    }
                    if(check)
                        answer += "Q";
                    }
                }
            }
    }
    return answer;
}
string Horse(string mas[8][8], int position[][2], int step, string answer) {
    int temp[2];
    bool check=true;
    temp[0] = position[step][0] - 2;
    temp[1] = position[step][1] - 1;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] - 2;
    temp[1] = position[step][1] + 1;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] - 1;
    temp[1] = position[step][1] - 2;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] - 1;
    temp[1] = position[step][1] + 2;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] + 1;
    temp[1] = position[step][1] - 2;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] + 1;
    temp[1] = position[step][1] + 2;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] + 2;
    temp[1] = position[step][1] - 1;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    temp[0] = position[step][0] + 2;
    temp[1] = position[step][1] + 1;
    if (ValidTemp(temp)) {
        if (mas[temp[0]][temp[1]] == "N") {
            if (answer == "O") {
                answer = "N";
            }
            else {
                for(int i=0; i<answer.length(); i++){
                        if(answer[i]=='N')
                        check=false;
                    }
                    if(check)
                answer += "N";
            }
        }
    }
    return answer;
}
string GetAnswer(string mas[8][8], int position[][2], int step) {
    string answer="O";
    if(mas[position[step][0]][position[step][1]]!="O"){
    answer="X";
    }else{
        answer = Slon(mas, position, step, answer);
        answer = King(mas, position, step, answer);
        answer = Horse(mas, position, step, answer);
        answer = Peshka(mas, position, step, answer);
        answer = Queen(mas, position, step, answer);
        answer = Tura(mas, position, step, answer);
        
    }
    return answer;
}
int main()
{
    int Q;
    string mas[8][8];
    string row;
    for (int i = 0; i < 8; i++) {
        cin>>row;
        for (int j = 0; j < 8; j++) {
            mas[i][j]=row[j];
        }
    }
        cin >> Q;
    string* answer= new string[Q];
    int(*position)[2] = new int[Q][2];
    for (int i = 0; i < Q; i++) {
            cin >> position[i][0];
        position[i][0]--;
        cin >> position[i][1];
        position[i][1]--;
        if (position[i][0] >= 0 && position[i][1] >= 0 && position[i][0] <= 7 && position[i][1] <= 7) {
            answer[i] = GetAnswer(mas, position, i);
        }
        else {
            answer[i] = "O";
        }
        cout << endl;
    }   
    for (int i = 0; i < Q; i++) {
        cout << answer[i] << endl;
    }
    return 0;
}