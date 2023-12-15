#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Структура "Пацієнт"
struct Patient {
    string last_name;
    string first_name;
    string father_name;
    string address;
    int medical_card;
    string insurance;
};

// Функція для друку вмісту бінарного файлу
void printPatientFile(const string &fileName) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;  //cerr - стандартний потік помилок
        return;
    }

    Patient patient;
    while (file.read(reinterpret_cast<char*>(&patient), sizeof(patient))) {
        cout << "Last name: " << patient.last_name << "; First name: " << patient.first_name
                  << "; Address: " << patient.address << "; Medical card number: " << patient.medical_card
                  << "; Insurance number: " << patient.insurance << endl;
    }
    file.close();
}

// Функція для видалення пацієнта з вказаним номером медичної карти
void deletePatient(const string& fileName, int medicalCardNumber) {
    ifstream readFile(fileName, ios::binary);          
    if (!readFile.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    ofstream tempFile("temp.bin", ios::binary);            
    if (!tempFile.is_open()) {
        cerr << "Error: Could not create temporary file." << endl;
        readFile.close();
        return;
    }

    Patient patient;
    while (readFile.read(reinterpret_cast<char*>(&patient), sizeof(patient))) {
        if (patient.medical_card != medicalCardNumber) {
            tempFile.write(reinterpret_cast<const char*>(&patient), sizeof(patient));
        }
    }
    readFile.close();
    tempFile.close();

    if (remove(fileName.c_str()) != 0 || rename("temp.bin", fileName.c_str()) != 0) {
        cerr << "Error: Failed to delete or rename files." << endl;
    } else {
        cout << "Patient with medical card number " << medicalCardNumber << " has been deleted." << endl;
    }
}

// Функція для додавання пацієнтів до початку файлу
void addPatientsToBeginning(const string& fileName) {
    vector<Patient> newPatients;

    int numPatientsToAdd;
    cout << "Enter the number of patients to add: ";
    cin >> numPatientsToAdd;

    cin.ignore(); // Clear the input buffer

    for (int i = 0; i < numPatientsToAdd; ++i) {
        Patient newPatient;
        cout << "Enter details for Patient " << i + 1 << ":" << endl;
        cout << "Last name: ";
        getline(cin, newPatient.last_name);
        cout << "First name: ";
        getline(cin, newPatient.first_name);
        cout << "Father name: ";
        getline(cin, newPatient.father_name);
        cout << "Address: ";
        getline(cin, newPatient.address);
        cout << "Medical card number: ";
        cin >> newPatient.medical_card;
        cout << "Insurance number: ";
        cin >> newPatient.insurance;

        newPatients.push_back(newPatient);
        cin.ignore(); // Clear the input buffer
    }

    ifstream readFile(fileName, ios::binary);
    if (!readFile.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    vector<Patient> allPatients; // Вектор для зберігання всіх пацієнтів

    Patient patient;
    while (readFile.read(reinterpret_cast<char*>(&patient), sizeof(patient))) {
        allPatients.push_back(patient); // Додавання пацієнта у вектор
    }
    readFile.close();

    // Додаємо нових пацієнтів до початку вектору
    for (auto it = newPatients.rbegin(); it != newPatients.rend(); ++it) {
        allPatients.insert(allPatients.begin(), *it);
    }

    ofstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    // Перезапис вмісту файлу з оновленим вектором пацієнтів
    for (const Patient& pat : allPatients) {
        file.write(reinterpret_cast<const char*>(&pat), sizeof(pat));
    }
    file.close();

    cout << "New patients added to the beginning of the file." << endl;
}

int main() {
    string fileName = "patients.bin";

// Створення файлу
    ofstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not create file." << endl;
        return 1;
    }
    file.close();

    cout << "File " << fileName << " created successfully." << endl;
    
    // Додавання нових пацієнтів у початок файлу
    addPatientsToBeginning(fileName);

    // Вивід вмісту файлу
    cout << "File contents:" << endl;
    printPatientFile(fileName);

    // Видалення пацієнта з номером медичної карти 12345
    deletePatient(fileName, 12345);

    // вивід оновленого вмісту файлу
    cout << "Updated file contents:" << endl;
    printPatientFile(fileName);

    return 0;
}
