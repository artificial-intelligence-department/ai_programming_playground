#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int max_size = 256;
struct Human
{
    char name[max_size + 1];
    int age;
    char home_address[max_size + 1];
    char phone_number[max_size + 1];

    Human()
    {
        strcpy(name, "");
        age = 0;
        strcpy(home_address, "");
        strcpy(phone_number, "");
    }

    Human(const char *name,
          int age,
          const char *home_address,
          const char *phone_number)
    {
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->home_address, home_address);
        strcpy(this->phone_number, phone_number);
    }
};

Human create_human()
{
    Human human;
    cout << "Enter name: ";
    fgets(human.name, 255, stdin);
    cout << "Enter age: ";
    cin >> human.age;
    getc(stdin); // remove \n from buffer (from previous cin)
    cout << "Enter home address: ";
    fgets(human.home_address, 255, stdin);
    cout << "Enter phone number: ";
    fgets(human.phone_number, 255, stdin);
    return human;
}

int main()
{
    vector<Human> people;

    FILE *file = fopen("input.bin", "rb");
    if (file == nullptr)
    {
        cerr << "File not found\nSeeding list\n";
        people.emplace_back("Roman", 18, "Lviv", "380931234567");
        people.emplace_back("Ivan", 19, "Kyiv", "380671234568");
    }
    else
    {
        Human human;
        fread(&human, sizeof(Human), 1, file);
        while (!feof(file))
        {
            people.push_back(human);
            fread(&human, sizeof(Human), 1, file);
        }

        fclose(file);
    }

    int choice;
    do
    {
        cout << "1 - print people\n"
             << "2 - add new person\n"
             << "3 - delete person\n"
             << "0 - exit\n"
             << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                for (int i = 0; i < people.size(); i++)
                    cout << people[i].name << " " << people[i].age << " "
                         << people[i].home_address << " "
                         << people[i].phone_number << endl;
                break;
            case 2:
            {
                char phone_number[max_size];
                cout << "Enter phone number of previous person: ";
                getc(stdin); // remove \n from buffer (from previous cin)
                fgets(phone_number, 255, stdin);

                for (int i = 0; i < people.size(); i++)
                    if (strcmp(people[i].phone_number, phone_number) == 0)
                    {
                        people.insert(people.begin() + i + 1, create_human());
                        break;
                    }
                break;
            }
            case 3:
            {
                int age;
                cout << "Enter age of person to delete: ";
                cin >> age;
                for (int i = 0; i < people.size(); i++)
                    if (people[i].age == age){
                        people.erase(people.begin() + i);
                        i--;
                    }
                break;
            }
            case 0:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 0);

    file = fopen("input.bin", "wb");
    for (int i = 0; i < people.size(); i++)
        fwrite(&people[i], sizeof(Human), 1, file);

    fclose(file);

    return 0;
}