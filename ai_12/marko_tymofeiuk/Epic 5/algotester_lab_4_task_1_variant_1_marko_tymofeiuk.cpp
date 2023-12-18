#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){
    size_t n, m;
    std::vector<int> nVector, mVector;

    std::vector<int> difference1, difference2, intersection, onion, symmetricDifference;

    std::cin >> n;
    for (int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        nVector.push_back(temp);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++){
        int temp;
        std::cin >> temp;
        mVector.push_back(temp);
    }

    std::sort(nVector.begin(), nVector.end());
    std::sort(mVector.begin(), mVector.end());

    std::set_difference(nVector.begin(), nVector.end(), mVector.begin(), mVector.end(), std::back_inserter(difference1));

    std::set_difference(mVector.begin(), mVector.end(), nVector.begin(), nVector.end(), std::back_inserter(difference2));

    std::set_intersection(nVector.begin(), nVector.end(), mVector.begin(), mVector.end(), std::back_inserter(intersection));

    std::set_union(nVector.begin(), nVector.end(), mVector.begin(), mVector.end(), std::back_inserter(onion));

    std::set_symmetric_difference(nVector.begin(), nVector.end(), mVector.begin(), mVector.end(), std::back_inserter(symmetricDifference));


    std::cout << difference1.size() << std::endl;
    for (int elem : difference1){
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << difference2.size() << std::endl;
    for (int elem : difference2){
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << intersection.size() << std::endl;
    for (int elem : intersection){
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << onion.size() << std::endl;
    for (int elem : onion){
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << symmetricDifference.size() << std::endl;
    for (int elem : symmetricDifference){
        std::cout << elem << " ";
    }

    return 0;
}