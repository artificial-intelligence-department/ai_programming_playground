#include <iostream>
int main(){
    using namespace std;
    int n;
    unsigned int in = 15;
    char ans;
cin >> n;
for(int i = 0; i < n; i++){
cin >> ans;
if(ans == 'k'){
if(in > 0)
in--;
}
else if(ans == 'p'){
    if(in>0)
    in = 15;
    else{
        in = 0;
    }
}
else if(ans == 'z'){
    if(in>0)
    in = 0;
    else{
    in = 15;

    }
}
}
cout << in;








    return 0;
}
