#include <string>
#include <iostream>

using namespace std;



int main(int argc, char const *argv[])
{
    string s {""};
    string compressedS {""};
    cin >> s; 
    int repNum {1};

    for (const char* c = s.c_str(); *c; ++c)
    {   
        
        if(*c == *(c+1)){
            repNum ++;
            
        }else{
            char prevC = *(c);
            compressedS.append(1,prevC);
            if (repNum>1)
            {
                compressedS.append(to_string(repNum));
            }
            
            

            repNum = 1;
        }
        

    }
    cout << compressedS;
    

    return 0;
}
