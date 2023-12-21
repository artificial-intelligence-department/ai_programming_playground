 #include <iostream>
 #include <cmath>

 using namespace std;

int main() {
  int n, m;

    cout << "Enter value n:" << endl;
    cin>>n;
    cout<<"Enter value m:"<<endl;
    cin>>m;

    cout << (++n * m) << endl;
    cout<<( m++ < n)<< endl;
    cout << (n++ > m) << endl;
    return 0;
}