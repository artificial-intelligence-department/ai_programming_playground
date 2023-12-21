#include<iostream>
using namespace std;

char** cavesorter( char**cave ,int h, int l){
    char** tempcave=cave;
    char checkcave[h][l];
    int i, j;
    int count = 0;

    for(i=0;i<h;i++){
            for(j=0;j<l;j++){
                checkcave[i][j]=tempcave[i][j];
            }
    }

    for(j=0;j<l;j++){
        for(i=0;i<h-1;i++){
            if(tempcave[i][j]=='O'||tempcave[i][j]=='X'){
                continue;
            } else if(tempcave[i][j]=='S'&&tempcave[i+1][j]=='O'){
                tempcave[i+1][j]='S';
                tempcave[i][j]='O';
            } 
        }
    }

     for(i=0;i<h;i++){
            for(j=0;j<l;j++){
                if(tempcave[i][j]==checkcave[i][j]){
                    count++;
                }
            }
        }
    
    if(count==h*l){
        return tempcave;
    }else{
        return cavesorter(tempcave,h,l);
    }
}
int main(){
    int i,j;
    int height, length;
    cin>> height;
    cin>> length;
    
    char** cave = new char*[height];
        for ( i = 0; i < height; ++i){
            cave[i] = new char[length];
        }

    for(i=0;i<height;i++){
            for(j=0;j<length;j++){
                cin>>cave[i][j];
            }
        }

    char** newcave = cavesorter(cave, height, length);
    
    cout<<"\n";
    for(i=0;i<height;i++){
            for(j=0;j<length;j++){
                cout<<newcave[i][j];
            }
        cout<<"\n";
        }

}






