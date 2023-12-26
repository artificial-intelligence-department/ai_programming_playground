#include <iostream>
#include <fstream>
using namespace std;
const int pull_n = 1366; // to change // цілочисельна константа
string const filename = "/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-7/file.txt";
//double f(int n,int m){
//    double ans = n+m+0.3;
//    return ans;
//}
double f(int n, int m){
    return n*1.3 + m +0.5;
}
template<typename t>
struct matrix{
    int n,m;
    t**x;
    matrix(int n,int m):n(n),m(m){
        x = new t*[n];
        for(int i=0;i<n;i++){
            x[i] = new t[m];
        }
    }
};
matrix<double> create_matrix(double (*f)(int i,int j)){
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
matrix<int> function2(matrix<int> m){
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
    for(int j=0;j<10;j++){
        int i1=int(random()%10),i2=int(random()%10),i3=int(random()%10);
        double ans = m.x[i1][j]+m.x[i2][j]+m.x[i3][j];
        a[j] = int(ans);
    }
    return a;
}
bool write_f(int* a) {
    ofstream file;
    file.open(filename, ios::out);
    if (!file.is_open()) {
        return false;
    }
    for(int i=0;i<10;i++){
        file << a[i] << ' ';
    }
    file.close();
    return true;
}
int read_f(){
    ifstream file;
    file.open(filename, ios::in);
    int ans = 1;
    for(int i=0;i<10;i++){
        int x;
        file >> x;
        ans*=x;
    }
    cout << ans;
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
    int b = read_f();
    delete_f();
    return 0;
}