#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    cout << "array len: ";
    cin >> n;
    int x;
    cin >> x;
    int ans = x;
    for (int i = 1; i < n; i++){
        cin >> x;
        ans = max(ans,x);
    }
    cout << ans << '\n';

    cout << "\nsentence:";
    char s[400];
    int max_word_len = 0;
    char max_word[20];
    int i=0;
    int curr_len=0;
    char curr_word[20];
    fgets(s, 400, stdin);
    int r=0;
    while(s[i] != '\0'){
        if(s[i]==' '||s[i+1]=='\0'){
            if(curr_len>max_word_len){
                for(int j=0;j<20;j++) max_word[j] = curr_word[j];
                max_word_len = curr_len;
            }
            curr_len = 0;
            for(int j=0;j<20;j++) curr_word[j] = '\0';
            r = 0;
        }else{
            curr_word[r]=s[i];
            r++;
            curr_len++;
        }
        i++;
    }
    for(char j : max_word){
        if(j=='\0') break;
        cout << j;
    }
}