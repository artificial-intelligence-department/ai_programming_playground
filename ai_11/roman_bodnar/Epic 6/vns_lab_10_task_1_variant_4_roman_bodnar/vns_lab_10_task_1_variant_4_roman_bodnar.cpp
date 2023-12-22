#include <iostream>
#include <fstream>
using namespace std;

struct point
{
    int key;
    point *next;

    point(int key, point *next) : key(key), next(next) {}
    point() : next(NULL) {}
    point(int key) : point(key, NULL) {}
};

void add_element(point **head, int key, int position)
{
    point *new_element = new point;
    new_element->key = key;
    new_element->next = nullptr;

    if (*head == nullptr)
    {
        *head = new_element;
    }
    else
    {
        point *current = *head;
        int i = 0;
        while (current->next != nullptr && i < position)
        {
            current = current->next;
            i++;
        }
        new_element->next = current->next;
        current->next = new_element;
    }
}

void remove_element(point **head, int position)
{
    if (*head == nullptr)
    {
        return;
    }
    else
    {
        point *current = *head;
        int i = 0;
        while (current->next != nullptr && i < position)
        {
            current = current->next;
            i++;
        }
        point *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void print_list(point *head)
{
    point *current = head;
    while (current != nullptr)
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void save_list_to_file(point *head, string filename)
{
    ofstream outfile(filename);
    point *current = head;
    while (current != nullptr)
    {
        outfile << current->key << endl;
        current = current->next;
    }
    outfile.close();
}

point *restore_list_from_file(string filename)
{
    ifstream infile(filename);
    point *head = nullptr;
    point *current = nullptr;
    int key;
    infile >> key;
    while (!infile.eof())
    {
        point *new_element = new point;
        new_element->key = key;
        new_element->next = nullptr;

        if (head == nullptr)
        {
            head = new_element;
            current = head;
        }
        else
        {
            current->next = new_element;
            current = new_element;
        }

        infile >> key;
    }
    infile.close();
    return head;
}

void delete_list(point **head)
{
    point *current = *head;
    while (current != nullptr)
    {
        point *temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

int main()
{
    int choice;
    point *head = NULL;
    do
    {
        cout << "1. Add element" << endl
             << "2. Remove element" << endl
             << "3. Print list" << endl
             << "4. Save list to file" << endl
             << "5. Restore list from file" << endl
             << "0. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int key, position;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter position: ";
                cin >> position;
                add_element(&head, key, position);
                break;
            }
            case 2:
            {
                int position;
                cout << "Enter position: ";
                cin >> position;
                remove_element(&head, position);
                break;
            }
            case 3:
                print_list(head);
                break;
            case 4:
            {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                save_list_to_file(head, filename);
                break;
            }
            case 5:
            {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                head = restore_list_from_file(filename);
                break;
            }
            case 0:
                delete_list(&head);
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }

    } while (choice != 0);
    return 0;
}