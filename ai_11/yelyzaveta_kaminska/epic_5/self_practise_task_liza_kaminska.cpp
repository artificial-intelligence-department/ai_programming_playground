#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Contact {
    string name;
    string phoneNumber;
    string email;
};

void add_contact(const Contact& contact, const string& filename) {
    ofstream file(filename, ios::binary | ios::app);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&contact), sizeof(Contact));
        cout << "Contact added successfully." << endl;
    } else {
        cout << "Unable to open the file."<< endl;
    }

    file.close();
}

void display_contacts(const string& filename) {
    ifstream file(filename, ios::binary);

    if (file.is_open()) {
        Contact contact;
        while (file.read(reinterpret_cast<char*>(&contact), sizeof(Contact))) {
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phoneNumber << endl;
            cout << "Email: " << contact.email << endl;
            cout << "-----------------"<< endl;
        }
    } else {
        cout << "Unable to open the file." << endl;
    }

    file.close();
}

int main() {
    const string filename = "contacts.dat";

    while (true) {
        cout << "1. Add Contact"<< endl;
        cout << "2. Display Contacts"<< endl;
        cout << "3. Exit"<< endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter Name: ";
                cin >> newContact.name;
                cout << "Enter Phone Number: ";
                cin >> newContact.phoneNumber;
                cout << "Enter Email: ";
                cin >> newContact.email;

                add_contact(newContact, filename);
                break;
            }
            case 2:
                display_contacts(filename);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
