#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> run_num(-5 , 5);

    int list_size;
    cin >> list_size;

    vector<int> list;
    int nessessory_num = 0;

    for(int i = 0; i < list_size; i++){
        int numbers = run_num(gen);
        list.push_back(numbers);
    }

    uniform_int_distribution<> position_run_num(0, list.size());
    int random_pos = position_run_num(gen);
    list.insert(list.begin() + random_pos , nessessory_num);

    for(int i = 0 ; i < list_size; i++){
        cout << list[i] << " ";
    }
    
    int index_to_insert;
    cout << "\nIndex to insert" << endl;
    cin >> index_to_insert; 
    cout << "Element with index you entered: "<<list[index_to_insert] << endl;

    if(index_to_insert ==  list_size){
        list[0] = 100;
    }
    else if (index_to_insert >= 0 && index_to_insert < list.size()){
        list.insert(list.begin() + index_to_insert + 1,100);
    }
    auto checker = find(list.rbegin() , list.rend() , nessessory_num);

    if (checker != list.rend()){
        list.erase((checker + 1).base());
    }

    for(int i = 0 ; i < list_size; i++){
        cout << list[i] << " ";
    }


    return 0;
}