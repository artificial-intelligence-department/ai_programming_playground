#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void write(string& name_of_the_file, vector<string>& data){
    ofstream file_stream1(name_of_the_file, ios::out);
    if (file_stream1.is_open()) 
    {
        for (const auto& each_line : data) 
        {
            file_stream1 << each_line << '\n';
        }
        file_stream1.close();
    }else
        cout << "Error while opening" << endl;
}

void read(string& name_of_the_file, vector<string>& data){
    ifstream file_stream2(name_of_the_file);
    if (file_stream2.is_open()) 
    {
        string elements_of_vector;
        while (getline(file_stream2, elements_of_vector)) 
        {
            data.push_back(elements_of_vector);
        }
        file_stream2.close();
    }else 
        cout << "Error while opening" << endl;
}

int main(){
    int N1=1, N2=9;
    string file_name = "lab9.txt";
    vector<string> data;
    data.push_back("HELLO");
    data.push_back("there:)");
    data.push_back("AflhA");
    data.push_back("s113");
    data.push_back("2023A");
    data.push_back("sdgjA");
    data.push_back("wpdjgd");
    data.push_back("afj");
    data.push_back("lanfA");
    data.push_back("jgsnA");

    write(file_name, data);
    vector<string> data_from_file;
    read(file_name, data_from_file);

    
    vector<string> data_to_file2;
    int c = 0;
    for (int i = 0; i < data_from_file.size(); i++) 
    {
        if(data_from_file[i][((data_from_file[i].size())-1)] == 'A' && i > N1 && i < N2)
            data_to_file2.push_back(data_from_file[i]); 
    }
    string file_name2 = "lab9_2.txt";
    write(file_name2, data_to_file2);
    vector<string> data_from_file2;
    read(file_name2, data_from_file2);


    cout<<"Sorted file 2: \n";
    vector <int> count(data_from_file2.size());
    for (int i = 0; i < data_from_file2.size(); i++)
    {
        count.push_back(0);
    }
    
    for (int i = 0; i < data_from_file2.size(); i++)
    {
        for (int j = 0; j < data_from_file2[i].size(); j++)
        {
            if (data_from_file2[i][j] == 'A')
                count[i] += 1;
        }
    }
    int max =0,index=0;
    for (int i = 0; i < count.size(); i++)
    {
        if(max < count[i]){
            max = count[i];
            index =i;
        }
    }
    cout<<'\n';
    cout<<data_from_file2[index];
        
    return 0;
}