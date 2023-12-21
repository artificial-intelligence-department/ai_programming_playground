#include <iostream>
using namespace std;
int findthebiggestnumber(int scoreboard[],  int length){
    int i;
    int j = 0;
    for(i=1;i<length;i++){
if (scoreboard[j]>=scoreboard[i]){
    continue;
} else {
    j = i;
        }   
    }
        return scoreboard[j];
   }
   
 int findLongestIncreasingSubsequence(int a[], int length) {
    int scoreboard[length]; 
    for (int i = 0; i < length; i++) 
        scoreboard[i] = 1;

    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j]<a[i]) {
                scoreboard[i] = max(scoreboard[i], scoreboard[j] + 1);
            }
        }
    }

    int maxLength = findthebiggestnumber(scoreboard, length);
    
    return maxLength;
}

int main() {
    int length;
      cin>> length;

    int a[length];
    for(int i = 0; i<length; i++)
    cin>>a[i];
    
    int result = findLongestIncreasingSubsequence(a, length);
    cout<< result;
    return 0;
}
