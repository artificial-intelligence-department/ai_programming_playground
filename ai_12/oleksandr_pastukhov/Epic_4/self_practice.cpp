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

    std::cout << "Кількість спільних елементів: " << commonCount << std::endl;
    std::cout << "Кількість унікальних елементів в обох масивах разом: " << uniqueElements.size() << std::endl;
}

int main(){
    using namespace std;
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {3, 4, 5, 6, 7};

    countElements(array1, array2);

    return 0;
}
