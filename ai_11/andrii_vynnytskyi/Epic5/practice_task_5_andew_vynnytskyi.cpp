#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

vector<string> parse(string text)
{
    vector<string> data;
    string buff;
    for(int i = 0 ;i < text.size(); i++)
    {
        bool is_separator_found = false;
        if (text[i] == ';')
        {
            is_separator_found = true;
        }

        if (is_separator_found)
        {
            data.push_back(buff);
            buff = "";
        }
        else
        {

                buff += text[i];


        }
    }
    return data;
}

string read(string path)
{
    string output;
    string line;
    ifstream file;
    file.open(path, ios_base::app);
    if (!file){

        return "Failure" ;
    }
    cout << "Success" << endl;
    while(getline(file , line))
    {
        output += line;
        cout<< line<<"\n";
    }

    file.close();
    return output;
}
void write(string path, string data)
{

    ofstream file;

    file.open(path,ios_base::app);
    if (!file){

        cout<< "Failure" ;
        return;
    }
    cout << "Success" << endl;

    file << data <<";\n";
    file.close();
}
void deleteAllData(string path){
    ofstream file(path, ios::trunc);
    file.close();
}

int main()
{
    vector <string> sentences = {"The quick brown fox jumps over the lazy dog.", "Artificial intelligence is transforming various industries.","Coding allows us to create incredible software applications.","The sun sets in the west, painting the sky with vibrant colors.","Learning new things is a lifelong adventure."};

    string path = "C:/Users/Nout_1/CLionProjects/untitled3/write.txt";
    string path1 = "C:/Users/Nout_1/CLionProjects/untitled3/copy.txt";
    for (string i: sentences) {
        write(path, i);
    }

    string rfile  = read(path);
    vector<string> r_file = parse(rfile);
    for (string i: r_file) {
        write(path1, i);
    }

    return 0;
}
