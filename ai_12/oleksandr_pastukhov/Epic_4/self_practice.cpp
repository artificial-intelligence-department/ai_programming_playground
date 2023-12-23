#include<iostream>
#include<vector>
#include <algorithm>

void countElements(const std::vector<int> array1,const std::vector<int> array2){
    int commonCount = 0;

    std::vector<int> uniqueElements;

    for(int element : array1){
        auto it = std::find(array2.begin(),array2.end(),element);
        if(it != array2.end()) 
            commonCount++;

        if(std::find(uniqueElements.begin(),uniqueElements.end(),element) == uniqueElements.end()) 
            uniqueElements.push_back(element);
    }

    for (int element : array2) 
        if (std::find(uniqueElements.begin(),uniqueElements.end(),element) == uniqueElements.end()) 
            uniqueElements.push_back(element); 

    std::cout << commonCount << std::endl;
    std::cout << uniqueElements.size() << std::endl;
}

int main(){
    using namespace std;

    int n;
    cin >> n;
    vector<int> array1;
    for (int i = 0;i < n;i++){
        int element;
        cin >> element;
        array1.push_back(element);
    }

    int m;
    cin >> m;
    vector<int> array2;
    for (int i = 0;i < m;i++) {
        int element;
        cin >> element;
        array2.push_back(element);
    }

    countElements(array1, array2);

    return 0;
}