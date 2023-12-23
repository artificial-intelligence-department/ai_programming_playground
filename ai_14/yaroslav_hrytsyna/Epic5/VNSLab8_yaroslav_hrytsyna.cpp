#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Record{
    char name[40];
    char Author[40];
    int duration;
    int price;
};

void formFile(Record& record);
void printFile();
void deleteEl(int lenth);
void addEl(Record& record, int number);

int main(){
    Record Paranoid;
    Paranoid = {"Paranoid", "Black Sabbath", 42, 1000};
    formFile(Paranoid);
    Record Moon;
    Moon = {"Dark side of the moon", "Pink floyd", 43, 1500};
    formFile(Moon);
    Record Rust;
    Rust = {"Rust in peace", "Megadeth", 41, 1200};
    formFile(Rust);
    printFile();

    cout << "Enter the lenth of record, which you want to delete" << endl;
    int dellenth;
    //cin.ignore();
    cin >> dellenth;
    deleteEl(dellenth);
    cout << "Records after deleting" << endl;
    printFile();
    cout << " " << endl;

    Record Wall;
    Wall = {"The Wall", "Pink Floyd", 81, 1300};
    Record Doors;
    Doors = {"The doors", "The Doors", 44, 1400};
    int pos;
    cout << "enter the after position" << endl;
    cin >> pos;
    addEl(Wall, pos);
    addEl(Doors, pos);
    printFile();


    fstream file("Records.dat", fstream::out | fstream::trunc | fstream::binary);
    file.close();
    return 0;
}

void formFile(Record& record)
{
    fstream outfile("Records.dat", fstream::out | fstream::app | fstream::binary);

    if(outfile.is_open())
    {
        outfile.write((char*)&record, sizeof(Record));
        outfile.close();
    }
    else
    {
        cout << "error opening file" << endl;
        return;
    }
}

void printFile()
{
    fstream infile("Records.dat", fstream::in | fstream::binary);
    if(infile.is_open())
    {
        Record record;
        while(infile.read((char*)&record, sizeof(Record)))
        {
            cout << "Name: " << record.name << endl;
            cout << "Author: " << record.Author << endl;
            cout << "Lenth: " << record.duration << endl;
            cout << "Price: " << record.price << endl;
            cout <<"===========" << endl;
        }
        infile.close();
    }
    else
    {
        cout << "error opening file" << endl;
        return;
    }
}
void deleteEl(int lenth)
{
    fstream infile("Records.dat", fstream::binary | fstream::in);
    fstream outfile("out.dat", fstream::binary | fstream::out);

    if(infile.is_open() && outfile.is_open())
    {
        Record record;
        bool founded = false;
        while (infile.read((char*)&record, sizeof(Record))){
            if(record.duration!=lenth){
                outfile.write((char*)&record, sizeof(Record));
            } else{
                founded = true;
            }
        }
        infile.close();
        outfile.close();
        if(founded)
        {
            fstream infile("Records.dat", fstream::binary | fstream::out);
            fstream outfile("out.dat", fstream::binary | fstream::in);
            if(outfile.is_open() && infile.is_open())
            {
                while(outfile.read((char*)&record, sizeof(Record)))
                {
                    infile.write((char*)&record, sizeof(Record));
                }
                outfile.close();
                infile.close();
            }
            else
            {
                cout << "error2 opening file" << endl;
                return;
            }
        }
        else
        {
            cout << "there is no records with this lenth" << endl;
            return;
        }
    }
    else
    {
        cout << "error opening files" << endl;
        return;
    }
    return;
}
void addEl(Record& record, int number)
{
    fstream infile("Records.dat", fstream::binary | fstream::in);
    fstream outfile("out.dat", fstream::binary | fstream::out);

    if(infile.is_open() && outfile.is_open())
    {
        int current_number = 0;
        Record rec;
        while(infile.read((char*)&rec, sizeof(Record)))
        {
            if(current_number==number)
            {
                outfile.write((char*)&record, sizeof(Record));
            }
            outfile.write((char*)&rec, sizeof(Record));
            current_number++;
        }
        if(current_number==number)
        {
            outfile.write((char*)&record, sizeof(Record));
        }
        infile.close();
        outfile.close();
        fstream infile("Records.dat", fstream::binary | fstream::out);
        fstream outfile("out.dat", fstream::binary | fstream::in);
        if(outfile.is_open() && infile.is_open()){
            while(outfile.read((char*)&record, sizeof(Record)))
            {
                infile.write((char*)&record, sizeof(Record));
            }
            outfile.close();
            infile.close();
        }
        else
        {
            cout << "error opening file" << endl;
            return;
        }
    }else{
        cout << "error opening files" << endl;
        return;
    }
}
