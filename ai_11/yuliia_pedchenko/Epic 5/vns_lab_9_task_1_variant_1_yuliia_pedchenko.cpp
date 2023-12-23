#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string f1_path = "C:/REPOSITORY/ai_programming_playground/ai_11/yuliia_pedchenko/textfiles/F1.txt";
const string f2_path = "C:/REPOSITORY/ai_programming_playground/ai_11/yuliia_pedchenko/textfiles/F2.txt";

////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<string> read_file(string path) {

    vector<string> info;
    string line;
    ifstream read_file;

    read_file.open(path, ios::app);

    while (getline(read_file, line)) {
        
        cout << line << endl;
        info.push_back(line);
    }
    
    return info;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void copy_info(vector<string> info, string path) {
    ofstream put_info;
    put_info.open(path, ios::app);
    for (int i = 0; i < info.size(); i++) {
        if (i%2==0) {
            put_info << info[i] << endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    ofstream delete_data(f2_path, ios::trunc);
    delete_data.close();

    ifstream check_file;
    check_file.open(f1_path);
     if (!check_file) {
        cout << "File 'F1' does not exist" << endl;
        return 0;
    }
    check_file.close();

    ifstream check_file2;
    check_file2.open(f2_path);
     if (!check_file2) {
        cout << "File 'F2' does not exist" << endl;
        return 0;
    }
    check_file2.close();
    
    cout << endl <<"Data of the F1 file is: " << endl;
    vector <string> F1_info = read_file(f1_path);
    
    copy_info(F1_info, f2_path);

    cout << endl <<"Data of the F2 file is: " << endl;
    read_file(f2_path);

    ifstream in_file1(f1_path, ios::binary);
    in_file1.seekg(0, ios::end);
    int sizef1 = in_file1.tellg();

     ifstream in_file2(f2_path, ios::binary);
    in_file2.seekg(0, ios::end);
    int sizef2 = in_file2.tellg();

    cout    << endl << "Size of F1 file is " << sizef1 << " bytes" << endl
            << "Size of F2 file is " << sizef2 << " bytes" << endl;

    return 0;
}