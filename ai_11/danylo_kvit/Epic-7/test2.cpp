#include <iostream>
#include <fstream>
using namespace std;
const int pull_n = 1366;    // цілочисельна константа
string const filename = "/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-7/file.txt";
//double f(int n,int m){
//    double ans = n+m+0.3;
//    return ans;
//}
double f(int n, int m){     //використано аргументи функції
    float result = n*1.3 + m +0.5;  //дійсна змінна
    return result;
}
template<typename t>
struct matrix{              // своя структура = об'єкт матриця
    int n,m; //цілочисельна змінна
    t**x;                   // двовимірний масив для зберігання значень
    matrix(int n,int m):n(n),m(m){
        x = new t*[n];
        int i = 0;
        while(true){
            x[i] = new t[m];
            i++;
            if(i>=10) break;    // break для виходу з циклу
        }
    }
};
matrix<double> create_matrix(double (*f)(int i,int j)){ // тут використано вказівник до функції яку ми використовуємо
    matrix<double> m(10,10);
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) m.x[i][j]=f(i,j);
    return m;
}
matrix<double> function2 (matrix<double> m){
    for(int k=m.m-1;k>=0;k--){
        for(int j=0;j<k;j++) {
            bool ok = 1;
            for (int i = 0; i < m.n; i++) {
                if(m.x[i][j]>m.x[i][j+1]){
                    ok=0;
                }
            }
            if(!ok){
                for(int i=0;i<m.n;i++){
                    double r = m.x[i][j];
                    m.x[i][j] = m.x[i][j+1];
                    m.x[i][j+1] = r;
                }
            }
        }
    }
    return m;
}
matrix<int> function2(matrix<int> m){           // перевантаження функції для різних типів даних з якими працюємо
    for(int k=m.n-1;k>=0;k--){
        for(int i=0;i<k;i++) {
            bool ok = 1;
            for (int j = 0; i < m.m; i++) {
                if(m.x[i][j]<m.x[i+1][j]){
                    ok=0;
                }
            }
            if(!ok){
                int* r = m.x[i];
                m.x[i] = m.x[i+1];
                m.x[i+1] = r;
            }
        }
    }
    return m;
}
int* f_sum(matrix<double> m){
    int* a = new int [10];
    int j = 0;
    do{                             // do-while цикл для вибірки 3-тьох елементів з КОЖНОГО рядка
        int i1 = int(random() % 10), i2 = int(random() % 10), i3 = int(random() % 10); // математична функція random
        double ans = m.x[i1][j] + m.x[i2][j] + m.x[i3][j];    //дійсна змінна з подвійною точністю для підрахунку суми перед її заокругленням
        a[j] = int(ans);
        j++;
    }while(j<10);
    return a;
}
bool write_f(int* a) {
    ofstream file;
    file.open(filename, ios::out);
    if (!file.is_open()) {    // оператор розгалуження
        return false;
    }
    for(int i=0;i<10;i++){      // for цикл для того щоб записати всі 10 значень
        file << a[i] << ' ';    // функція для запису у файл
    }
    file.close();
    return true;
}
int read_f(){
    ifstream file;
    file.open(filename, ios::in);
    int ans = 1;
    int i=0;
    while(i<10){     //while для зчитування 10-ти значень з файлу
        int x;
        file >> x;     //функція для читання з файлу
        ans*=x;
        i++;
    }
    cout << ans;        // оператори для виведення даних
    file.close();
    return ans;
}
void delete_f(){
    fstream file;
    file.open(filename,ios::out);
    cout << "\nfile blanked\n";
}
int main(){
    matrix<double> m = create_matrix(f);
    m = function2(m);
    int* a = f_sum(m);
    write_f(a);
    int b = read_f();     //цілочисельна змінна для підрахуйнку
    delete_f();
    return 0;
}