#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <fstream>
using namespace std;
bool check(string &s){
    vector<string> words;
    int j = -1;
    for(int i=0;i<s.size();i++){
        if(i==0||s[i-1]==' '){words.emplace_back(""); j++;}
        words[j]+=s[i];
    }
    set<string> swords;
    for(const auto &i:words) swords.insert(i);
    if(swords.size()==words.size()) return true;
    return false;
}
bool c(string &s){
    int ans=0;
    for(int i=0;i<s.size();i++) {
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e' || s[i] == 'y' || s[i] == 'i') {
            ans+=1;
        }
    }
    cout << ans;
    return ans;
}
int main() {
    FILE *f1 = fopen("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/f1.txt", "w");
    FILE *f2 = fopen("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/f2.txt", "w");
    fprintf(f1, "Koly ja czytaju knyzky, to knyzkf rozumnishaje\n"
                "Jakos ja torknuvsa garachogo chajnyka i obpik jogo\n"
                "Odnogo razu ja nasnywsja snu\n"
                "zarady 'dam' hlopci jdut na podvygy, zarady 'ne dam' ne idyt\n"
                "Samorozvytok ce koly porivnuesh sebe zi vchorashnim sobojo a ne z inshymy\n"
                "Najivnist vid viry vidriznjaje vidsutnist mozkovoji dijalnosti\n"
                "Nemozlyvo spijmaty tygra u klitku, bo tygry buvaut tilky u polosku\n"
                "Mene spytaly chomy ja takyj krutyj - ta bo ja samogonky bahnuv\n"
                "Krashche svitle pyvo niz temne majbutnje\n"
                "Tili tili tyapa tyapa rubi rubi rava rava\n");
    fclose(f1);
    FILE * f3 = fopen("/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/f1.txt", "r");
    string old;
    string s;
    char x;
    int i=0;
    while(true){
        fscanf(f3,"%c",&x);
        if(i>=10)break;
        if(x=='\n') {
            if(i==0) {
                c(s);
            }
            if(check(s)) fprintf(f2,"%s\n",&s[0]);
            s = "";
            i++;
            continue;
        }
        s+=x;
    }
    return 0;
}