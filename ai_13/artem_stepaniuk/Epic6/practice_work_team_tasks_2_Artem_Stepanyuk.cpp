#include <iostream>
#include <fstream>

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

bool areListsEqual(ListNode* head1, ListNode* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->value != head2->value) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return (head1 == nullptr && head2 == nullptr);
}

void writeListToFile(const ListNode* head, const std::string& filename) {
    std::ofstream file(filename);
    while (head != nullptr) {
        file << head->value << " ";
        head = head->next;
    }
    file.close();
}

ListNode* readListFromFile(const std::string& filename) {
    std::ifstream file(filename);
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    int value;

    while (file >> value) {
        if (head == nullptr) {
            head = new ListNode(value);
            current = head;
        } else {
            current->next = new ListNode(value);
            current = current->next;
        }
    }

    file.close();
    return head;
}

int main() {
    ListNode* list1 = new ListNode(10);
    list1->next = new ListNode(20);
    list1->next->next = new ListNode(30);
    writeListToFile(list1, "list1.txt");

    ListNode* list2 = new ListNode(10);
    list2->next = new ListNode(20);
    list2->next->next = new ListNode(30);
    writeListToFile(list2, "list2.txt");

    ListNode* readList1 = readListFromFile("list1.txt");
    ListNode* readList2 = readListFromFile("list2.txt");

    if (areListsEqual(readList1, readList2)) {
        std::cout << "Списки ідентичні.\n";
    } else {
        std::cout << "Списки різні.\n";
    }

    delete list1;
    delete list2;
    delete readList1;
    delete readList2;

    return 0;
}