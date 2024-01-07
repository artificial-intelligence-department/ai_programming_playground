#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Customer 
{
    char name[40];
    char surname[40];
    char patronymic[40];
    char address[40];
    char number[100];
    char card_number[40];
};

int main() 
{
    Customer m;

    ofstream info("Customers_information.txt");

    if(!info) 
    {
        cerr << "Customers.txt could not be opened";
        exit(1);
    }
    
    cout << "Write a name: ";  cin >> m.name;  info  << m.name << "\n";
    cout << "Write a surname: ";  cin >> m.surname;  info << m.surname << "\n";
    cout << "Write a patronymic: ";  cin >> m.patronymic;  info << m.patronymic << "\n";
    cout << "Write an address: ";  cin >> m.address;  info << m.address << "\n";
    cout << "Write a number: ";  cin >> m.number;  info << m.number << "\n";
    cout << "Write a card_number: ";  cin >> m.card_number;  info << m.card_number << "\n";

    info.close();
    
    ifstream printinfo("Customers_information.txt");

    if (!printinfo) 
    {
        cerr << "Customers_information.txt could not be opened";
        exit(2);
    }

    string print;
    while (getline(printinfo, print))
    {
        cout << print << "\n";
    }
    printinfo.close();

    vector<Customer> people;
    ifstream infile("Customers_information.txt");
    if (!infile)
    {
        cerr << "Customers_information.txt could not be opened";
        exit(3);
    }
    while (infile >> m.name >> m.surname >> m.patronymic >> m.address >> m.number >> m.card_number)
    {
        people.push_back(m);
    }
    infile.close();

    people.erase(people.begin(), people.begin()+3);

    Customer newCustomer;
    cout << "Write a name: "; cin >> newCustomer.name; people.push_back(newCustomer);
    cout << "Write a surname: "; cin >> newCustomer.surname; people.push_back(newCustomer);
    cout << "Write a patronymic: "; cin >> newCustomer.patronymic; people.push_back(newCustomer);

    ofstream tovector("Customers_information.txt");
    if (!tovector) 
    {
        cerr << "Customers_information.txt could not be opened";
        exit(4);
    }
    for (const auto& person : people) 
    {
        tovector << person.address << "\n";
        tovector << person.number << "\n";
        tovector << person.card_number << "\n";
        tovector << person.name << "\n";
        tovector << person.surname << "\n";
        tovector << person.patronymic << "\n";
    }
    tovector.close();
    
    ifstream modyfiedinfo("Customers_information.txt");
    if (!modyfiedinfo) 
    {
        cerr << "Customers_information.txt could not be opened";
        exit(6);
    }

    string line;
    while (getline(modyfiedinfo, line))
    {
        cout << line << endl;
    }

    modyfiedinfo.close();

    return 0;
}
