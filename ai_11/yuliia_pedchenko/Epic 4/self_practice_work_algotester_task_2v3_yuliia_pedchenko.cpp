#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;
    if (N<1 || N>1000) return 0;

    int ldrone = 0;
    int rdrone = N-1;

    int way[N];
    for (int i = 0; i < N; i++) {
        
        cin >> way[i];
        if (way[i]<1 || way[i]>5) return 0;
    } 

    for (int i = 0; i < N; i++) {
        if (ldrone == rdrone) {
            cout << ldrone+1 << " " << rdrone+1 << endl;
            cout << "Collision";
            return 0;
        }
        else if (ldrone == rdrone-1) {
            cout << ldrone+1 << " " << rdrone+1 << endl;
            cout << "Stopped";
            return 0;
        }
        else if (ldrone > rdrone) {
            cout << ldrone+1 << " " << rdrone+1 << endl;
            cout << "Miss";
            return 0;
        }
        else {
            ldrone = ldrone + way[ldrone];
            rdrone = rdrone - way[rdrone];
        }   
    }
}
