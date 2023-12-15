#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
// Зчитуємо розмір масиву
int N;
cin >> N;

// Зчитуємо елементи масиву
vector<int> r(N);
for (int i = 0; i < N; i++) {
cin >> r[i];
}

// Зчитуємо елементи, які треба видалити
int x, y, z;
cin >> x >> y >> z;

// Видаляємо елементи x, y, z з масиву
r.erase(remove(r.begin(), r.end(), x), r.end());
r.erase(remove(r.begin(), r.end(), y), r.end());
r.erase(remove(r.begin(), r.end(), z), r.end()); 


// Виводимо результати
//cout << r.size() << endl;
// Кількість елементів масиву
    if (r.size() == 0) {
    cout << 0 << endl;
    cout << 0 << endl;
} else if (r.size() == 1){
    cout << 1 << endl;
    cout << r[0] << endl;
    
} else {
    cout <<r.size() <<endl;
    for (int i = 0; i < r.size() - 1; i++) {
        cout << r[i] + r[i + 1] << " ";
    }
    cout << endl;
}
cout<<endl;
return 0;

}