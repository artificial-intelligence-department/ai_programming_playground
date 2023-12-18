#include <iostream>
#include <fstream>
using namespace std;
enum Result {Success, Failure};

Result w(char *n, char *c, int k){
    ofstream wf(n, ios::out | ios::binary);
    if(!wf){
        cout <<"Can't open\n";
        return Failure;
    }
    wf.write(&c[0], k);
    wf.close();
    return Success;
}
Result w(string &name, string &c){
    return w(&name[0],&c[0],c.size());
}
Result w(string &name, char* c, int k){
    return w(&name[0],c, k);
}Result w(char* name, string &c){
    return w(name,&c[0],c.size());
}
int main(){
    string filen= "/Users/user/Documents/GitHub/ai_programming_playground/ai_11/danylo_kvit/Epic-5/example.txt";
    char* filename = &filen[0];
    char content[256];
    cout << "Enter content:";
    cin.getline(content,256);
    int len = 0;
    for(int i=0;i<256;i++){
        if(content[i]=='\0') break;
        len++;
    }
    Result result = w(filen, content, len);
    if (result == Success) cout << "Successfully created file"<< endl;
    else cout << "Fail" << '\n';
    return 0;
}
