#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Stadium {
    string name;
    int year;
    int site;
    string kind_of_sports;
};

void write_data_to_file(const string& filename, const Stadium& stadium) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Trouble with opening" << endl;
        return;
    }
    file << stadium.name << " " << stadium.year << " " << stadium.site << " " << stadium.kind_of_sports << endl;
    file.close();
}

void watch_file(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Trouble with opening" << endl;
        return;
    }
    Stadium stadium;
    while (file >> stadium.name >> stadium.year >> stadium.site >> stadium.kind_of_sports) {
        cout << "Name of stadium is: " << stadium.name << endl;
        cout << "Year of stadium is: " << stadium.year << endl;
        cout << "Num of stadiums sites is: " << stadium.site << endl;
        cout << "There are such sports: " << stadium.kind_of_sports << endl;
        cout << endl;
    }
    file.close();
}

void add_stadium_define_position(const string& old_fileName, int position, const Stadium& stadium) {
    ifstream old_file(old_fileName);
    ofstream new_file("new_fileName");
    if (!new_file.is_open() || !old_file.is_open()) {
        cerr << "Trouble with opening" << endl;
        return ;
    }
    vector<Stadium> stadiums;
    Stadium current_stadium;
    while (old_file >> current_stadium.name >> current_stadium.year >> current_stadium.site >> current_stadium.kind_of_sports) {
        stadiums.push_back(current_stadium);
    }
    old_file.close();
    stadiums.insert(stadiums.begin() + position, stadium);
    for (const auto& stadium : stadiums) {
        new_file << stadium.name << " " << stadium.year << " " << stadium.site << " " << stadium.kind_of_sports << endl;
    }
    new_file.close();
    remove(old_fileName.c_str());
    rename("new_fileName", old_fileName.c_str());
}

void delete_stadium(const string& old_fileName, int delete_year) {
    ifstream old_file(old_fileName);
    ofstream new_file("new_fileName");
    if (!new_file.is_open() || !old_file.is_open()) {
        cerr << "Trouble with opening" << endl;
        return ;
    }
    vector<Stadium> stadiums;
    Stadium current_stadium;
    while (old_file >> current_stadium.name >> current_stadium.year >> current_stadium.site >> current_stadium.kind_of_sports) {
        if (current_stadium.year != delete_year) {
            stadiums.push_back(current_stadium);
        }
    }
    old_file.close();
    for (const auto& stadium : stadiums) {
        new_file << stadium.name << " " << stadium.year << " " << stadium.site << " " << stadium.kind_of_sports << endl;
    }
    new_file.close();
    remove(old_fileName.c_str());
    rename("new_fileName", old_fileName.c_str());
}
void clear_file(const string& filename) {
    ofstream file(filename, ios::trunc);
    if (!file.is_open()) {
        cerr << "Trouble with opening" << endl;
        return ;
    }
    file.close();
}

int main() {

    string filename = "stadiums.txt";
    clear_file(filename);
    Stadium stadium1 = {"Stadium_name1", 1998, 5, "Football"};
    write_data_to_file(filename, stadium1);
    
    cout << "Content of file: " << endl;
    watch_file(filename);
    cout<<"--------------------------------------------------------"<<endl;
    
    Stadium stadium2 = {"Stadium_name2", 2003, 10, "Baseball"};
    Stadium stadium3 = {"Stadium_name3", 1998, 15, "Basketball"};

    add_stadium_define_position(filename, 1, stadium2);
    
    cout << "Content of file after adding stadium2: " << endl;
    watch_file(filename);
    cout<<"--------------------------------------------------------"<<endl;

    add_stadium_define_position(filename, 1, stadium3);

    cout << "Content of file after adding stadium3: " << endl;
    watch_file(filename);
    cout<<"--------------------------------------------------------"<<endl;

    delete_stadium(filename, 1998);
    
    cout << "Content of file after deleting by year: " << endl;
    watch_file(filename);

    return 0;
}