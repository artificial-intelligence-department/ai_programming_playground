#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
vector<int> ToCheck {};
vector<int> Sorted {};
int main() {
    int N;
    cin >> N;
    //Ініціалізую числа, які я маю перевірити
    for(int i=1; i<=N; i++){
        ToCheck.push_back(i);
    }
    int field[N][N];

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            field[i][j] = row[j] - '0';
        }
    }


    int times;
    cin >> times;
    int M = times*2;
    int positions[M];       // координати 
    for(int i = 0; i < M; i++){
        cin >> positions[i];
    }
    // for(auto pos: positions){
    //     cout << pos << " ";}



    for (int i = 0; i < times; i++) {   // Початок обчислень
        int row = positions[i*2]-1;
        int col = positions[(i*2)+1]-1;
        vector<int> numbers; // Вектор для додавання всіх чисел навхрест

        // прохожусь по рядку
        for (int j = 0; j < N; j++) {
            if (field[row][j] != 0)
                numbers.push_back(field[row][j]);
        }

        // прохожусь по колонці
        for (int j = 0; j < N; j++) {
            if (field[j][col] != 0)
                numbers.push_back(field[j][col]);
        }

        // Сортую числа
        sort(numbers.begin(), numbers.end());

        // знаходжу числа
         for (int targetNumber : ToCheck) {
            auto fin = find(numbers.begin(), numbers.end(), targetNumber);
        //знову сортую
            if (fin == numbers.end()) {
                Sorted.push_back(targetNumber);
            }
         }
         cout << endl;
         if (field[row][col]!=0){
            cout << "1" << endl;
            cout << field[row][col] << endl;}
        else if(field[row][col]==0){
            cout << Sorted.size() << endl;
            for (int num : Sorted) {
                cout << num << " ";
            }
        cout << endl;
        }
        Sorted.clear();
 

    }

    return 0;
}
