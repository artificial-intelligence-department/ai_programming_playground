#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::vector<std::string> words, selectedWords;
    std::vector<char> finalVec;
    std::vector<char>::iterator iter;
    long long n, k;
    std::cin >> n >> k;
    k -= 1;
    for (int i = 0; i < n; i++){
        std::string temp;
        std::cin >> temp;
        words.push_back(temp);
    }

    for (auto &elem : words){
        for (auto &letter : elem){
            letter = std::tolower(letter);
        }
    }

    std::sort(words.begin(), words.end());

    for (int i = 0; i < n; i++){
        if (i+k < n){
            if (words[i] == words[i+k]){
                std::string temp = words[i];
                selectedWords.push_back(temp);
            }
        }
    }

    if (selectedWords.empty()){
        std::cout << "Empty!";
        return 0;
    }

    for (auto &elem : selectedWords){
        for (auto &letter : elem){
            finalVec.push_back(letter);
        }
    }

    std::sort(finalVec.begin(), finalVec.end());
    iter = std::unique(finalVec.begin(), finalVec.end());
    finalVec.resize(std::distance(finalVec.begin(), iter));
    std::reverse(finalVec.begin(), finalVec.end());

    size_t finalSize = finalVec.size();
    std::cout << finalSize << std::endl;

    for (char elem : finalVec){
        std::cout << elem << " ";
    }

    return 0;
}