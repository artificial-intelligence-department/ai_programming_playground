	#include<iostream>
	using namespace std;
	
	int main(){
	int n, m, res;
	
	cin >> n;
	cin >> m;
	res = n++-m;
	cout << res << endl;
	
	if(m-- > n){
	    cout << "True" << endl;
	}
	else{
	    cout << "False" <<endl;
	}
	
	if(n-- > m){
	    cout << "True";
	}
	else{
	    cout << "False";
	}
	    return 0;
	}
