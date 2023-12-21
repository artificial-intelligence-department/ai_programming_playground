#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum FileOpResult { 
    Success, 
    Failure
};

struct Pupil {
    string last_name;
    string first_name;
    string surname;
    string clas;
    string phone_num;
    char evaluations[4];
};

FileOpResult create_file(char *name, Pupil &a) {
    ofstream cr(name, ios::binary);
    if (!cr) {return Failure;}
    cr << a.last_name  << ' ' << a.first_name << ' ' 
    << a.surname << '\n' << a.clas << '\n' << a.phone_num << '\n' 
    << a.evaluations[0] << ' ' << a.evaluations[1] << ' '<< a.evaluations[2] << ' ' << a.evaluations[3] << '\n';
    if (cr.ios::good()) {return Success;}
    else {return Failure;}
}   

FileOpResult print_file(char *name) {
    ifstream pr(name, ios::binary);
    if (!pr) {return Failure;}
    string a;
    while (getline(pr, a)) {
        cout << a << '\n';
    }
    if (pr.ios::eof()) {return Success;}
    else {return Failure;}
}

FileOpResult add_to_file(char *name, Pupil &a) {
    ofstream add(name, ios::app | ios::binary);
    if (!add) {return Failure;}
    add << a.last_name << ' ' << a.first_name << ' ' 
    << a.surname << '\n' << a.clas << '\n' << a.phone_num << '\n' 
    << a.evaluations[0] << ' ' << a.evaluations[1] << ' '<< a.evaluations[2] << ' ' << a.evaluations[3] << '\n';
    if (add.ios::good()) {return Success;}
    else {return Failure;}
}

FileOpResult delete_from_file(char *name) {
    vector<string> ins;
    string tmp_s[4];
    ifstream in(name, ios::binary);
    if (!in) {return Failure;}
    short i = 0;
    while(getline(in, tmp_s[i++])) {
        getline(in, tmp_s[i++]); 
        getline(in, tmp_s[i++]); 
        getline(in, tmp_s[i]); 
        if ((tmp_s[3][0] == '2') || (tmp_s[3][2] == '2') || (tmp_s[3][4] == '2') || (tmp_s[3][6] == '2')) {tmp_s[0] = ""; tmp_s[1] = ""; tmp_s[2] = ""; tmp_s[3] = "";}
        else {for(int j=0;j<4;j++) {ins.push_back(tmp_s[j]);}}
        i = 0;
    }
    in.close();
    remove(name);
    ofstream out(name, ios::binary);
    if (!out) {return Failure;}
    for (int i = 0; i<ins.size(); i++) {
        out << ins[i] << '\n';
    }
    return Success;
}

int main() {
    Pupil a{"Stozhuk","Roman","Igorovuch","10-B","+380508264122",{'5','5','5','5'}};
    Pupil b{"Hailov","Volodymyr","Olexiovich","10-A","+380963395648",{'2','5','5','5'}};
    char name[9] = "info.dat";
        if (create_file(name, a)) { std::cout << "Failure\n"; }
        if (print_file(name)) { std::cout << "Failure\n"; }
        if (add_to_file(name, b)) { std::cout << "Failure\n"; }
        if (print_file(name)) { std::cout << "Failure\n"; }
        if (delete_from_file(name)) { std::cout << "Failure\n"; }
        if (print_file(name)) { std::cout << "Failure\n"; }
    return 0;
}