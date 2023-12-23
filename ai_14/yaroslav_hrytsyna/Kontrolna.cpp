#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
float matrix[10][10];
int s[10];

const int x=1038;
void crm(){
    for (int i = 0; i<10; i++){
        for(int j=0; j<10;j++){
            float d=(j+1)/(i+1);
            matrix[i][j]=abs(pow((i+1),d)-pow(d,1/3));
        }
    }
}

void sorting(float a[10][10],float x){
    bool swapped;
    for (int i=0; i<10;i++){
        for (int k=0; k<10;k++){
            swapped=false;
            for(int j=0;j<10;j++){
                if (a[j][i]>a[j+1][i]){
                    swap(a[i][j],a[j+1][i]);
                    swapped=true;
                }
            }
            if (!swapped){
                break;
            }
        }
    }
}

void sorting(int a[10][10],int x){
    bool swapped;
    for (int i=0; i<10;i++){
        for (int k=0; k<10;k++){
            swapped=false;
            for(int j=0;j<10;j++){
                if (a[j][i]<a[j][i+1]){
                    swap(a[i][j],a[j][i+1]);
                    swapped=true;
                }
            }
            if (!swapped){
                break;
            }
        }
    }
}

void sum(float a[10][10]){
    int j1,j2,j3;
    for (int i=0; i<10;i++){
        j1=rand()%9;
        j2=rand()%9;
        j3=rand()%9;
        s[i]=round(a[j1][i]+a[j2][i]+a[j3][i]);
        
    }
}

void crfile(int a[10]){
    fstream f("file1.txt");
    for (int i=0; i<10;i++){
        f << a[i];
    }
    string line;
    if (getline(f,line)){
        cout<<"success";
    }
    else{
        cout<<"error";
    }

    f.close();
}

float fi(int a[10]){
    ofstream f("file1.txt");
    float m=1;
    for (int i=0; i<10;i++){
        m=m*a[i];
    }
    cout << m<<" ";
    return m;
}

void rem(){
    remove("file1.txt");
}

int main(){
    crm();
    float q;
    cin>>q;
    sorting(matrix,q);
    sum(matrix);
    crfile(s);
    fi(s);
    rem();
    return 0;
}
