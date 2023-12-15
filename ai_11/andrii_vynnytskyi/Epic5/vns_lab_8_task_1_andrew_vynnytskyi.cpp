#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Patient
{
    string initials;
    string adress;
    string number_of_med;
    string number_of_sec;
};
void deleteAllData(string path){
    ofstream file(path, ios::trunc);
    file.close();
}
void delete_element(vector<Patient>& data, const string& number_of_cart)
{
    for(int i = 0; i < data.size(); i++)
        if(data[i].number_of_med == number_of_cart)
        {
            data.erase(data.begin() + i);
        }

}
vector<Patient> import_data(vector<string> buffer)
{

    vector<Patient> data;
    for (int i = 0; i < buffer.size() - 1; )
    {
        Patient buff = { buffer[i],buffer[i+1],buffer[i + 2],buffer[i + 3]};
        i += 4;
        data.push_back(buff);
    }
    return data;
}
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
        if (text[i]!=' ')
        {
            buff += text[i];
        }

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
    while(getline(file , line))
    {
        output += line;
        cout<< line<<"\n";
    }

    file.close();
    return output;
}
void write(string path, Patient data)
{
    ofstream file;
    file.open(path,ios_base::app);
    if (!file){

        cout<< "Failure" ;
        return;

    }
    file << data.initials<<"; ";
    file << data.adress<<"; ";
    file << data.number_of_med<<"; ";
    file << data.number_of_sec<<";\n ";
    file.close();
}



int main()
{

    string path = "C:/Users/Nout_1/CLionProjects/untitled3/data.txt";
    write(path, {"Jonh Black","Chicago","7895","6547"});
    write(path, {"Adam White","New York","5321","4596"});
    write(path, {"Damian Brown","Minesota","6542","6548"});
    cout<< "File's data:\n";
    string text = read(path);
    cout << "Enter a number of patient's medical cart: ";
    string med_card;
    cin>> med_card;
    vector<Patient> data = import_data(parse(text));
    delete_element(data, med_card);
    deleteAllData(path);
    write(path, {"Mark Dominiko","Berlin","7895","6547"});
    write(path, {"Volodymyr Duda","Lviv","5321","4596"});
    for(int i = 0; i < data.size(); i++)
    {
        write(path,{data[i].initials,data[i].adress,data[i].number_of_med,data[i].number_of_sec});
    }
    cout<<"Edited list:\n ";
    read(path);

    return 0;
}
