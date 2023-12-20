#include <iostream>
#include <fstream>

using namespace std;

///////////////////////////////////////////////////////////

void data_line(string path, string info) {
    ofstream output_info;

    output_info.open(path, ios::app);
    output_info << info;
    output_info.close(); 
}

///////////////////////////////////////////////////////////

string read_file(string path) {

    string info;
    string line;
    ifstream read_file;

    read_file.open(path, ios::app);
    while (getline(read_file, line)) {
        info += line;
    }
    
    return info;
}

///////////////////////////////////////////////////////////

int main() {

    const string file_path = "C:/REPOSITORY/ai_programming_playground/ai_11/yuliia_pedchenko/textfiles/myfile.txt";
    string input;

    cin >> input;

    ofstream delete_data(file_path, ios::trunc);
    delete_data.close();

    data_line(file_path, input);
    if (input == read_file(file_path)) cout << "Success";
    else cout << "Failure";

    return 0;
}