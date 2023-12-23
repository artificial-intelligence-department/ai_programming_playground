
// 1 - очистити файл
// 2 - вписати початкові дані  
// 3 - зчитати та вивести початкові дані
// 4 - запросити зміни у користувача
// 5 - перетворити зчитані дані у масив
// 6 - змінити дані у масиві
// 7 - вивести нові дані та вивести їх у консоль  

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////

struct Abiturients {
    string sec_name;
    string name;
    string po_bati;
    string birth_year;
    string mark1;
    string mark2;
    string mark3;
    string average;      };


const string file_path = "C:/REPOSITORY/ai_programming_playground/ai_11/yuliia_pedchenko/textfiles/Abiturients.txt";

///////////////////////////////////////////////////////////////////////

void data_line(string path, Abiturients info) {
    ofstream output_info;

    output_info.open(path, ios::app);
    output_info << info.sec_name << ", "
                << info.name << ", "
                << info.po_bati << ", "  
                << info.birth_year << ", " 
                << info.mark1 << ", " 
                << info.mark2 << ", " 
                << info.mark3 << ", " 
                << info.average << ";" << endl;

    output_info.close(); 
}

///////////////////////////////////////////////////////////////////////

string read_file(string path) {

    string info;
    string line;
    ifstream read_file;

    read_file.open(path, ios::app);
    while (getline(read_file, line)) {
        cout << line << endl;
        info += line;
    }
    
    return info;
}

///////////////////////////////////////////////////////////////////////

vector<Abiturients> info_as_mass(string info) {

    vector<string> s_vector;
    string temp;


    for (int i = 0; i < info.size(); i++) {

        if (info[i] == ',' || info[i] == ';' ) {
            
            s_vector.push_back(temp);
            temp = "";
        }
        else if (info[i] == ' ') {}
        else {
            temp += info[i];
        }
    }
    vector <Abiturients> inf_as_mass;

    for (int i = 0; i < s_vector.size()-1; i += 8) {
        
        Abiturients mtemp = {s_vector[i], s_vector[i+1], s_vector[i+2], s_vector[i+3], s_vector[i+4], s_vector[i+5], s_vector[i+6], s_vector[i+7]};  
        inf_as_mass.push_back(mtemp);

    }
    return inf_as_mass;
}

///////////////////////////////////////////////////////////////////////

vector<Abiturients> erase_element(vector<Abiturients> mass, int number) {

    vector<Abiturients> new1mass;

    for (int i = 0; i < mass.size(); i++) {
        if (i != (number-1)) {
            new1mass.push_back(mass[i]); 
        }
    }
    return new1mass;
}

///////////////////////////////////////////////////////////////////////

int main() {

    ifstream check_file;
    check_file.open(file_path);
     if (!check_file) {
        cout << "File with this path does not exist" << endl;
        return 0;
    }
    check_file.close();

    ofstream delete_data(file_path, ios::trunc);
    delete_data.close();

    data_line(file_path, {"Pedchenko", "Yuliia", "Serghiivna", "2006", "200", "186", "181", "9.9" });
    data_line(file_path, {"Bartysheva", "Valentyna", "Serghiivna", "2007", "143", "180", "164", "8.5" });
    data_line(file_path, {"Piven", "Tymofiy", "Konstantynovych", "2006", "175", "186", "170", "10.3" });
    data_line(file_path, {"Shchurlin", "Prokhor", "Oleksandrovych", "2005", "200", "200", "200", "10.9" });
    data_line(file_path, {"Koriakov", "Pavlo", "Olegovych", "2005", "172", "200", "193", "11" });


    cout << "Current info in file:" << endl;
    string cinfo = read_file(file_path);

    vector<Abiturients> element_mass = info_as_mass(cinfo);

    int number;
    string nazwisko;

    cout << "Which line do you want to delete? (Enter number)" << endl;
    cin >> number;
    if (number < 1 || number > 5) {
        cout << "Please try number between 1 and 5";
        return 0;
    }

    vector <Abiturients> new_element_mass = erase_element(element_mass, number);

    cout << "List now is builded with these elements:" << endl;

    for (int i = 0; i < new_element_mass.size(); i++) {
        cout    << new_element_mass[i].sec_name << ", "
                << new_element_mass[i].name << ", "
                << new_element_mass[i].po_bati << ", "
                << new_element_mass[i].birth_year << ", "
                << new_element_mass[i].mark1 << ", "
                << new_element_mass[i].mark2 << ", "
                << new_element_mass[i].mark3 << ", "
                << new_element_mass[i].average << "; " << endl;
    }

    cout << endl << "After which last name you want to add new line?" << endl;
    cin >> nazwisko;

    ofstream delete_data2(file_path, ios::trunc);
    delete_data2.close();

    for (int i = 0; i < new_element_mass.size(); i++) {

        if (new_element_mass[i].sec_name == nazwisko) {
        data_line(file_path,    {new_element_mass[i].sec_name, new_element_mass[i].name, new_element_mass[i].po_bati,
                                 new_element_mass[i].birth_year, new_element_mass[i].mark1, new_element_mass[i].mark2,
                                 new_element_mass[i].mark3, new_element_mass[i].average});
        data_line(file_path, {"Burunduk", "Roman", "Viktorovych", "2004", "100", "109", "132", "3.3" });
        }
        else data_line(file_path,    {new_element_mass[i].sec_name, new_element_mass[i].name, new_element_mass[i].po_bati,
                                 new_element_mass[i].birth_year, new_element_mass[i].mark1, new_element_mass[i].mark2,
                                 new_element_mass[i].mark3, new_element_mass[i].average});

    }

    cout << "List now is builded with these elements:" << endl << endl;
    read_file(file_path);

    return 0;

}
