// Створити однонаправлений список, видалити значення та додати натомість
#include <iostream>

using namespace std;

struct Node {
  int key;
  Node* next;
};

Node* createList() { // Створюєтсья список із 10 вузлів
  Node* head = new Node();
  head->key = 1;
  head->next = nullptr;

  Node* current = head;
  for (int i = 2; i <= 10; i++) {
    Node* newnode = new Node();
    newnode->key = i;
    newnode->next = nullptr;

    current->next = newnode;
    current = newnode;
  }

  return head;
}

void printlist(Node* head) { // Виводить ключі усіх вузлів у списку
  Node* current = head;
  while (current != nullptr) {
    cout << current->key << " ";
    current = current->next;
  }
  cout << endl;
}

void delelem(Node*& head, int ind) { // Видаляє елемент за індексом
  if (ind == 0) {
    Node* newHead = head->next;
    delete head;
    head = newHead;
    return;
  }

  Node* current = head;
  for (int i = 1; i < ind; i++) {
    current = current->next;
  }

  Node* nodtodel = current->next;
  current->next = nodtodel->next;
  delete nodtodel;
}

void adelems(Node* head, int ind, int K) { // Додає К нових вузлів до списку після вузла із заданим індексом
  Node* current = head;
  for (int i = 1; i < ind; i++) { // Проходить по списку до вузла із зазначеним індексом
    current = current->next;
  }

  for (int i = 0; i < K; i++) {
    Node* newnode = new Node(); // Створюється новий вузол
    newnode->key = i + 8; // Ключ нового вузла
    newnode->next = current->next;
    current->next = newnode;
    current = newnode;
  }
}

int main() {
  Node* head = createList();

  printlist(head);

  delelem(head, 5);

  printlist(head);

  adelems(head, 5, 2);

  printlist(head);

  return 0;
}
