#include <iostream>
using namespace std;

int main(){
    char cave[1000][1000]; 
    int N, M; 
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }

    for(int i = 0; i < M; i++){ // Прохід через кожний стовпець
    for(int j = N-1; j >= 0; j--){ // Прохід через кожний рядок знизу до верху
        if(cave[j][i]=='S'){ // Якщо виявлено пісок
            int k = j+1; // Початок пошуку вільної клітини знизу
            while(k<N && cave[k][i]!='X' && cave[k][i]!='S'){ // Пошук найближчої вільної клітини знизу
                k++;
            }
            k--; // Повернення до останньої вільної клітини
            if(k!=j){ // Якщо пісок можна перемістити вниз
                char temp = cave[j][i];
                cave[j][i]=cave[k][i];
                cave[k][i]=temp;
            }
        }
    }
}
    // Вивід печери
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }
    return 0; 
}