#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, drone1 = 0, drone2 = 0, temp1 = 0, temp2; // N - розмір масиву, temp1 - тимчасова позиція дрона, пишем 0 бо числа додаються, temp2 - є знизу, 1 ми пишем коли є множення чисел
    cout << "Enter size of massive: ";
    cin >> N;
    while(N < 1 || N > 1000){ // розмір масиву має бути від 1 до 1000
        cout << "Enter size of massive again (it's must be from 1 to 1000): ";
        cin >> N;
    }
    int* array = new int[N]; // значення масиву, пишем * бо ми вводим елемент масиву
    cout << "Enter numbers for the massive: " << endl;
    for (int i = 0; i < N; i++) { // починаючи з 0 елемента, доки елемент менший за масив, перейти на кожен наступний елемент
        cout << "Enter " << i+1 << " number: ";
        cin >> array[i]; // ввести елемент масиву 
        while(array[i] < 1 || array[i] > 5){ // елемент масиву має бути від 1 до 5 
            cout << "Enter " << i+1 << " number again (it's must be from 1 to 5): ";
            cin >> array[i];
        }
    }
    temp2 = N-1; // оскільки елемент масиву починається з 0
    for (int i = 0; i < N; i++) {
        if (temp1+1 < temp2) { // вони стоять поряд
            temp1+= drone1; // додавання клітинки в які стоїть дрон 1
            temp2-= drone2; // віднімання клітинки в якій стоїть дрон 2
            if(temp1 > N-1){ // дрон 1 вилетів за масив зправа
                temp1=N-1; // межа зправа бо рахунок елементів йде від 0
            }
            if(temp2 < 0){ //дрон 2 вилетів за масив зліва
                temp2=0; // межа з зліва 
            }
            drone1 = array[temp1]; //елемент на якому зупиниться дрон1
            drone2 = array[temp2]; //елемент на якому зупиниться дрон2
        } else {
            break;
        }
    }
    if(temp1+1==temp2){ // дрони зупинилися один біля одного
        cout << "Pos Drone1: " << temp1+1 << endl << "Pos Drone2: " << temp2+1<<endl;
        cout << "Stopped";
    }else{
        if(temp1==temp2){ // дрони один на одному
        cout << "Pos Drone1: " << temp1+1 << endl << "Pos Drone2: " << temp2+1<<endl;
        cout << "Collision";
        }else{ // дрон перелетіли
        cout << "Pos Drone1: " << temp1+1 << endl << "Pos Drone2: " << temp2+1<<endl;
        cout << "Miss";
        }
    }
    return 0;
}
