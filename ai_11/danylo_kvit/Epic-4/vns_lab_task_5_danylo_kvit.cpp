#include <iostream>
using namespace std;
int n;
int* c;
void change_raws(int** a,int x, int y){
    c = a[x];
    a[x] = a[y];
    a[y] = c;
}
void change_col(int** a,int x, int y){
    for(int i=0;i<n;i++){
        int r = a[i][x];
        a[i][x] = a[i][y];
        a[i][y] = r;
    }
}
pair<int,int> find_el(int** a, int i1_given, int i2_given){
    int max = a[i1_given][n-1-i2_given];
    int i_res = i1_given;
    int j_res = n-1-i2_given;
    for(int i=i1_given;i<=i2_given;i++){
        for(int j=n-1-i2_given;j<=n-1-i1_given;j++){
            if(a[i][j]>max){
                i_res = i;
                j_res = j;
                max = a[i][j];
            }

        }
    }
    return pair<int,int>(i_res,j_res);
}
bool check(int** a){
    for(int i=0;i<n-1;i++) if(a[i][n-1-i]<=a[i+1][n-2-i]) return false;
    return true;
}
int main(){
    cin >> n;
    int **a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int t1 =find_el(a,i,n-1).first;
        int t2 =find_el(a,i,n-1).second;
        change_raws(a,i,t1);
        change_col(a,n-1-i,t2);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << (check(a)?"Yes":"No");
    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;
}