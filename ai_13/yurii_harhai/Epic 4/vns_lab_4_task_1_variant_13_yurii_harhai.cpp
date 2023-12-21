#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
int smallest();
double find_mean();

const int N {100};
size_t n {10};
int mini {};
size_t NewSize {3};


int old[N];
double updated[N];


int main() {
    srand(time(0));

    for(int i = 0; i < n; i++) { //генерація рандомного масиву
        old[i] = rand();
    }

    for(int i = 0; i < n; i++) {
        cout << old[i] << " ";
    }
    cout << endl <<"-------------------------------------------------------------------" << endl;
    cout << fixed << setprecision(1);
    for(int i = 0; i<3; i++){   //3 значення середнього арифметичного на початок
        updated[i] = find_mean();
    }
    
    mini = smallest();              // Генерація оновленого масиву без найменшого
    for (int i=0; i < n; i++){      
        if ( old[i] != mini){
            updated[NewSize] = old[i];
            NewSize++;
        }
    }  
    
    for(int i = 0; i < NewSize; i++) {
        cout << updated[i] << " ";
    }
 
    return 0;
}


int smallest(){                     // функція найменшого числа
    int minimum = INT_MAX; 
        for (int i= 0; i < 10; i++){
        if (old[i]< minimum)
            minimum = old[i];              
        }      
    return minimum;
}

double find_mean(){                 // функція середнього арифметичного масиву
    double suma {};
    double mean {};
    
    for (int i= 0; i < n; i++){
            suma += old[i];
        }
    mean = suma/n;
    return mean;
    
}
