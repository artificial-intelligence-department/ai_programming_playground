#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

enum Result { Success, Failure}; 
Result write(string& name_of_the_file, vector<string>& data){
    ofstream file_stream1(name_of_the_file, ios::out);
    if (file_stream1.is_open()) 
    {
        for (const auto& each_line : data) 
        {
            file_stream1 << each_line << '\n';
        }
        file_stream1.close();
        return Success;
    }else
        cout << "Error while opening" << endl;
        return Failure;
}

Result read(string& name_of_the_file, vector<string>& data){
    ifstream file_stream2(name_of_the_file);
    if (file_stream2.is_open()) 
    {
        string elements_of_vector;
        while (getline(file_stream2, elements_of_vector)) 
        {
            data.push_back(elements_of_vector);
        }
        file_stream2.close();
        return Success;
    }else 
        cout << "Error while opening" << endl;
        return Failure;
}

int main(){
    vector <string> content(1);
    string line;
    getline (cin, line);       
    content.push_back(line);
    string name_of_the_file1 = "practice_1.txt";
    Result result = write(name_of_the_file1, content);
    if (result == Success)
        cout<<"Successfully created and copied data to file\n";
    else
        cout<<"Unsuccessfully created and copied data to file\n";
    vector <string> new_content(1);
    read(name_of_the_file1, new_content);
    string name_of_the_file2 = "practice_2.txt";
    Result result2 = write(name_of_the_file2, new_content);
    if (result2 == Success)
        cout<<"Successfully created and copied data from file to file\n";
    else
        cout<<"Unsuccessfully created and copied data from file to file\n";
    return 0;
}