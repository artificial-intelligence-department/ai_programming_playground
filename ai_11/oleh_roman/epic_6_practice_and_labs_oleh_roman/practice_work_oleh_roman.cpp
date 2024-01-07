#include <iostream>
#include <string>

using namespace std;

struct spusok {
    int key;
    spusok* next;
    spusok* prev;

    spusok(int k) : key(k), next(nullptr), prev(nullptr) {}
};

void printSpusok(spusok* head);
void createSpusok(spusok*& head);
spusok* reverse(spusok* head);
void addElement(spusok*& n, int key);
bool compare(spusok* h1, spusok* h2);
spusok* add(const spusok *n1, const spusok *n2);
void deleteSpusok(spusok* head);


int main() {
    spusok* head = nullptr;
    int choise;
    string continue_or_no;
    do 
    {
        cout << "Which practice you want to review?\n";
        cin >> choise;
        switch (choise){
            case 1:
            {
                spusok* head = nullptr;
                createSpusok(head);                     

                cout << "List before reversing: ";
                printSpusok(head);

                head = reverse(head);
                cout << "list after reversing: ";
                printSpusok(head);
                deleteSpusok(head);
            }
                break;
            case 2:
            {
                spusok* h1 = nullptr;
                spusok* h2 = nullptr;
                cout << "Create the first list:\n";
                createSpusok(h1);

                cout << "Create the second list:\n";
                createSpusok(h2);
                if (compare(h1, h2)){
                    cout << "Lists are equal\n";
                } else {
                    cout << "Lists arent equal\n";
                }
                deleteSpusok(h1);
                deleteSpusok(h2);
            }
                break;
            case 3:
            {
                spusok* n1 = nullptr;
                spusok* n2 = nullptr;

                cout << "Creating the first list:\n";
                createSpusok(n1);

                cout << "Creating the second list:\n";
                createSpusok(n2);

                spusok* result = add(n1, n2);
                
                cout << "Result of adding: ";
                printSpusok(result);
                deleteSpusok(n1);
                deleteSpusok(n2);
                deleteSpusok(result);
            }
                break;
        }
            cout << "Do you want to check another practice?(Yes/No):";
            cin >> continue_or_no;
        if (continue_or_no == "No")
            cout << "Goodbye) See you later";

    } while (continue_or_no == "Yes");

    return 0;
}

void deleteSpusok(spusok* head) {
    spusok* current = head;
    spusok* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}


void createSpusok(spusok*& head) {
    int N, key;
    cout << "Enter amount of number: ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cout << "Element№" << i + 1 << ": ";
        cin >> key;
        addElement(head, key);
    }
}

void printSpusok(spusok* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    spusok* current = head;
    while (current) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << "\n";
}

spusok* reverse(spusok* head) {
        spusok* prev = nullptr;
        spusok* current = head;
        spusok* nextSpusok = nullptr;

        while (current != nullptr) {
            nextSpusok = current->next;
            current->next = prev;
            current->prev = nextSpusok;  
            prev = current;
            current = nextSpusok;
        }

        head = prev;
        return head;
    }

void addElement(spusok*& n, int key) {
    spusok* newSpusok = new spusok(key);
    if (!n) {
        n = newSpusok;
    } else {
        newSpusok->next = n;
        n->prev = newSpusok;
        n = newSpusok;  
    }
}

bool compare(spusok* h1, spusok* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->key != h2->key) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }

    return true;
}

spusok* add(const spusok *n1, const spusok *n2) {
    spusok* result = nullptr;
    spusok* current = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry + (n1 ? n1->key : 0) + (n2 ? n2->key : 0);
        carry = sum / 10;

        spusok* newSpusok = new spusok(sum % 10);

        if (result == nullptr) {
            result = current = newSpusok;
        } else {
            current->next = newSpusok;
            newSpusok->prev = current;
            current = newSpusok;
        }

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result;
}



