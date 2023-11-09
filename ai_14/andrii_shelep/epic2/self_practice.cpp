//031 Коля, Вася і теніс
#include <iostream>

using namespace std;

int main(){
    char c[100000];
    int n, kolya=0, vasya=0, kolya_part=0, vasya_part=0;

    cin >> n; //вводимо к-ть подач

    for (int i=0; i<n; i++){
        cin >> c[i]; //вводимо подачі
    }
    
    for (int i=0; i<n; i++){
        if(c[i]=='K'){ //якщо подачу виграв Коля, то добавляємо йому очок до рахунку
            kolya++;
        } else{ //якщо подачу виграв Вася, то добавляємо йому очко до рахунку
            vasya++; 
        }
        if (kolya>=11 && kolya-vasya >= 2){ //якщо Коля набрав 11 чи більше, і рахунок відрізняється мінімум на 2 очки, то Коля виграв партію і рахунок подач онуляється
            kolya_part++;
            kolya=0;
            vasya=0;
        } else if(vasya>=11 && vasya-kolya >= 2){ //якщо Вася набрав 11 чи більше, і рахунок відрізняється мінімум на 2 очки, то Вася виграв партію і рахунок подач онуляється
            vasya_part++;
            kolya=0;
            vasya=0;
        }
    }
// тоді виводимо рахунок, якщо всі партії доіграні, то виводимо тільки рахунок по партіях, якщо ні - то ще рахунок по подачах
    if (kolya==0 && vasya==0){
        cout << kolya_part << ":" << vasya_part << endl;
    } else{
        cout << kolya_part << ":" << vasya_part << endl << kolya << ":" << vasya << endl;
    }
    
    return 0;
}