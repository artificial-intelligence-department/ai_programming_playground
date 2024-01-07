#include <iostream>
#include <fstream>

using namespace std;

struct spusok {
    int key;
    spusok* next;
    spusok* prev;

    spusok(int k) : key(k), next(nullptr), prev(nullptr) {}
};

void addElement(spusok*& head, int key);
void createSpusok(spusok*& head);
void deleteElement(spusok*& head, int index);
void saveSpusok(spusok* head, const string& filename);
void printSpusok(spusok* head);
void destroySpusok(spusok*& head);
void restoreSpusok(spusok*& head, const string& filename);

int main() {
    spusok* head = nullptr;

    createSpusok(head);
    cout << "List: ";
    printSpusok(head);

    int indexToDel;
    cout << "Enter index to delete: ";
    cin >> indexToDel;
    deleteElement(head, indexToDel);
    cout << "List after deleting: ";
    printSpusok(head);

    int elementToAdd;
    cout << "Enter key to add at the beginning: ";
    cin >> elementToAdd;
    addElement(head, elementToAdd);
    cout << "List after adding: ";
    printSpusok(head);

    saveSpusok(head, "list.txt");

    destroySpusok(head);

    cout << "List after destruction: ";
    printSpusok(head);

    restoreSpusok(head, "list.txt");

    cout << "Restored list: ";
    printSpusok(head);

    destroySpusok(head);

    return 0;
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

void addElement(spusok*& head, int key) {
    spusok* newspusok = new spusok(key);
    if (!head) {
        head = newspusok;
    } else {
        newspusok -> next = head;
        head -> prev = newspusok;
        head = newspusok;
    }
}

void deleteElement(spusok*& head, int index) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }

    spusok* current = head;
    for (int i = 1; i < index && current; ++i) {
        current = current->next;
    }

    if (!current) {
        cout << "Wrong index\n";
        return;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    delete current;
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

void saveSpusok(spusok* head, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "ERROR\n";
        return;
    }

    spusok* current = head;
    while (current) {
        file << current->key << " ";
        current = current->next;
    }

    file.close();
    cout << "List saved to file.\n";
}

void destroySpusok(spusok*& head) {
    while (head) {
        spusok* delet = head;
        head = head->next;
        delete delet;
    }
    cout << "List destroyed.\n";
}

void restoreSpusok(spusok*& head, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "ERROR\n";
        return;
    }

    int key;
    while (file >> key) {
        addElement(head, key);
    }

    file.close();
    cout << "List is restored\n";
}
