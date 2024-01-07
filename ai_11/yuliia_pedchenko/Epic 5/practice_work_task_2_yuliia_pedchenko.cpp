#include <iostream>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////

void data_line(string path, string info) {
    ofstream output_info;

    output_info.open(path, ios::app);
    output_info << info;
    output_info.close(); 
}

////////////////////////////////////////////////////////////

int main() {

    const string fromfile_path = "C:/REPOSITORY/ai_programming_playground/ai_11/yuliia_pedchenko/textfiles/file_from.txt";
    const string tofile_path = "C:/REPOSITORY/ai_programming_playground/ai_11/yuliia_pedchenko/textfiles/file_to.txt";

     ifstream check_file1;
    check_file1.open(fromfile_path);
     if (!check_file1) {
        cout << "Failure" << endl;
        return 0;
    }
    check_file1.close();

    ofstream delete_data(tofile_path, ios::trunc);
    delete_data.close();

    ifstream check_file2;
    check_file2.open(tofile_path);
     if (!check_file2) {
        cout << "Failure" << endl;
        return 0;
    }
    check_file2.close();

    data_line(tofile_path, read_file(fromfile_path));
    if (read_file(fromfile_path) == read_file(tofile_path)) cout << "Success";
    else cout << "Failure";

    return 0;
}