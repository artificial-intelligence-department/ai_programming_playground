#include<iostream>

using namespace std;

int main(){
    int N;//кількість елементів
    //cout << "\nInput the number of elements: ";
    cin >> N;

    int r[N];

    int max=0, mini = 0, number_of_the_max_element=0,number_of_the_min_element=0;
    for(int i=0; i<N; i++)
    {
            //cout << "\nEnter number " << i << ": ";
            cin >> r[i];
            
            if(i==0){
            max=r[i];
            mini=r[i];
            }

            if(r[i] > max){
                max = r[i];
                number_of_the_max_element = i;
            }
                

            if(r[i] < mini){
                number_of_the_min_element = i;
                mini = r[i];
            }
    }

    int minimal_tireness1 = 0, minimal_tireness2 = 0, temp_max, temp_min;
    
    temp_max = max;
    temp_min = mini;
    //cout << "\nmax- " << max << "temp min - " << temp_min << endl;
    r[number_of_the_max_element] = -1;
    max = -1;
    for(int i=0; i < N; i++){
        if(r[i] > max){
            max = r[i];
        }
    }
    minimal_tireness1 = max - temp_min;
    //cout << "\nmax- " << max << "temp min - " << temp_min << endl;
    r[number_of_the_max_element] = temp_max;
    
    r[number_of_the_min_element] = 100001;
    mini = 100001;
    for(int i=0; i < N; i++){
        if(r[i] < mini){
            mini = r[i];
        }
    }
    minimal_tireness2 = temp_max - mini;

    int result;
    result = min(minimal_tireness1, minimal_tireness2);
    if(N == 1){
        result = 0;
    }

    cout << result << endl;

    return 0;
}