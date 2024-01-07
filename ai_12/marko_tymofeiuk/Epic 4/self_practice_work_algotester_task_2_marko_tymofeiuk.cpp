#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N, M;
    std::vector <int> nVector;
    std::vector <int> mVector;
    std::vector<int>::iterator iter;
    int inputN, inputM;

    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> inputN;
        nVector.push_back(inputN);       
    }
    std::cin >> M;
    for (int i = 0; i < M; i++){
        std::cin >> inputM;
        mVector.push_back(inputM);    
    }
    
    std::sort(nVector.begin(), nVector.end());
    iter = std::unique(nVector.begin(), nVector.end());
    nVector.resize(std::distance(nVector.begin(), iter));


    std::sort(mVector.begin(), mVector.end());
    iter = std::unique(mVector.begin(), mVector.end());
    mVector.resize(std::distance(mVector.begin(), iter));


    nVector.insert(nVector.end(), mVector.begin(), mVector.end());
    std::sort(nVector.begin(), nVector.end());
    int mergesize = nVector.size();
    int repet = 0;
    for (int i = 0; i < mergesize; i++){
        if (nVector[i] == nVector[i+1]){
            repet++;
        }
    }

    iter = std::unique(nVector.begin(), nVector.end());
    nVector.resize(std::distance(nVector.begin(), iter));
    mergesize = nVector.size();
    std::cout << repet << std::endl << mergesize;
}