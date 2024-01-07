#include <iostream>
#include <fstream>
#include <string>
enum FileOpResult { Success, Failure};
FileOpResult write_to_file(const char *name, const char *content);
FileOpResult copy_file(const char *file_from,const  char *file_to);

using namespace std;
int main(){
string fileName;
cout<<"Enter name of the file you want to write into\n";
getline(cin,fileName);

string text;
cout<<"Enter text you want to write into the file\n";
getline(cin,text);
FileOpResult resultOfWriting=write_to_file((fileName.c_str()),(text.c_str()));
if(resultOfWriting==Success){
    cout<<"Success\n";
}else{
    cout<<"Failure\n";
}

string fileNameForCopy;
cout<<"Enter name of the file you want to copy from\n";
getline(cin,fileNameForCopy);

string fileNamtoCopy;
cout<<"Enter name of the file you want to copy this into\n";
getline(cin,fileNamtoCopy);
FileOpResult resultOfCopying=copy_file((fileNameForCopy.c_str()),(fileNamtoCopy.c_str()));
if(resultOfCopying==Success){
    cout<<"Success\n";
}else{
    cout<<"Failure\n";
}
    return 0;
}
FileOpResult write_to_file(const char *name, const char *content){

ofstream myFile(name);
if (!myFile.is_open()) {
        return Failure;
    }
myFile<<content;
    if(myFile.fail()){
    myFile.close();
    return Failure;
    }

else{
   
    myFile.close();
    return Success;
}
}
FileOpResult copy_file(const char *file_from,const  char *file_to){
ifstream myReadFile(file_from);
ofstream myCopiedFile(file_to);
string myText;
if(!myReadFile.is_open() || !myCopiedFile.is_open()){
    return Failure;
}
while (getline(myReadFile, myText)) {
   myCopiedFile << myText << "\n";
}


myReadFile.close();
myCopiedFile.close();
return Success;
}