#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void copy(string path1, string path2)
{
    string line;
    ifstream file1;
    ofstream file2;
    file1.open(path1, ios_base::app);
    file2.open(path2, ios_base::app);
    if (!file1 || ! file2){

        cout<<"Failure" ;
        return;

    }
    while(getline(file1 , line))
    {
        int count = 0;
        for(int i = 0; i < line.size();i++)
        {
            if(line[i] == ' ' && line[i + 1] != ' ')
            {
                count++;
            }
        }
        if (count == 0)
        {
            file2<<line<<"\n";
        }
    }
    file1.close();
    file2.close();

}
void read(string path)
{

    string line;
    ifstream file;
    file.open(path, ios_base::app);
    if (!file){

        cout<<"Failure" ;
        return;

    }
    int lenght = 0;
    string buff;
    while(getline(file , line))
    {
       if (lenght < line.size())
       {
           lenght = line.size();
           buff = line;
       }

    }
    cout<<"The longest word: "<< buff;
    file.close();

}

int main()
{
    string path1 = "C:/Users/Nout_1/CLionProjects/untitled3/file_1.txt";
    string path2 = "C:/Users/Nout_1/CLionProjects/untitled3/file_2.txt";
    copy(path1 , path2);
    read(path2);

    return 0;
}