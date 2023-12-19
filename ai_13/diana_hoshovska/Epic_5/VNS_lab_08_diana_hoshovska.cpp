#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct PATIENT{ //фактично працює як змінна з підзміннами
    char firstName[100];
    char surName[100];
    char patronymic[100];
    char Address[100];
    int MedCard;
    int StrPolicy;
};

void addPatient(const char* filename, int number){
    ofstream file(filename, ios::binary | ios::app);
    if (!file.is_open()){
    cerr << "An error has occured, please try again." << endl; exit(1);}

    for (int i = 0; i < number; i++){
        PATIENT newPatient;
        cout << "\nEnter the details of the " << i+1 << " patient: " << endl;
        cout << "Name: "; cin >> newPatient.firstName;
        cout << "Surname: "; cin >> newPatient.surName;
        cout << "Patronymic: "; cin >> newPatient.patronymic;
        cout << "Address: "; cin >> newPatient.Address;
        cout << "MedCard: "; cin >> newPatient.MedCard;
        cout << "StrPolis: "; cin >> newPatient.StrPolicy;

        file.write((char *)&newPatient, sizeof(PATIENT));
    }
    file.close();
}

void deleteMedCard(const char* filename, int num){
    ifstream file(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);

    if (!file.is_open()){
    cerr << "An error has occured, please try again." << endl; exit(1);}
    PATIENT newPatient;
    for(int i = 0; file.read((char *)&newPatient, sizeof(PATIENT)); i++){
        if(newPatient.MedCard != num){
            temp.write((char *)&newPatient, sizeof(PATIENT));
        }
        else{
            cout << "A patient with a medical card " << newPatient.MedCard << " - is deleting...\n\n";
        }
    }
    file.close();
    temp.close();

    remove(filename);
    rename("temp.dat", filename);
}

void patientNoMedCard(const char* filename, int num){
    ifstream file(filename, ios::binary);
    if (!file.is_open()){
    cerr << "An error has occured, please try again." << endl; exit(1);}

    cout << "Patients without medical card: " << endl;
    PATIENT newPatient;
    for(int i = 0; file.read((char *)&newPatient, sizeof(PATIENT)); i++){
        if(newPatient.MedCard != num){
            cout << "Name: " << newPatient.firstName << endl;
            cout << "Surname: " << newPatient.surName << endl;
            cout << "Patronymic: " << newPatient.patronymic << endl;
            cout << "Address: " << newPatient.Address << endl;
            cout << "MedCard: " << newPatient.MedCard << endl;
            cout << "StrPolis: " << newPatient.StrPolicy << endl << endl;
        }
    }
    file.close();
}

int main(){
    int number, num;
    const char* filename = "patient.dat";

    cout << "Enter a number of patients: ";
    cin >> number;

    cout << "Enter a number of medical card to delete: ";
    cin >> num;

    addPatient(filename, number);
    deleteMedCard(filename, num);
    patientNoMedCard(filename, num);

    return 0;
}