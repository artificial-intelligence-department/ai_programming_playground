#include <iostream>
#include <fstream>
using namespace std;
struct Node {
  int key;
  Node* prev;
  Node* next;
};

Node* create_node(int key) {
  Node* node = new Node;
  node->key = key;
  node->prev = nullptr;
  node->next = nullptr;
  return node;
}

Node* create_list(int n) {
  if (n <= 0) {
    return nullptr;
  }

  Node* head = create_node(0);
  Node* prev = head;
  for (int i = 1; i < n; i++) {
    Node* node = create_node(i);
    prev->next = node;
    node->prev = prev;
    prev = node;
  }

  return head;
}

void print_list(Node* head) {
  if (head == nullptr) {
    cout << "Список порожній" << endl;
    return;
  }

  Node* current = head;
  while (current != nullptr) {
    cout << current->key << " ";
    current = current->next;
  }
  cout << endl;
}

Node* add_element_at_position(Node* head, int key, int position) {
  if (head == nullptr || position < 0) {
    return nullptr;
  }

  int i = 0;
  Node* current = head;
  while (current != nullptr && i < position - 1) {
    current = current->next;
    i++;
  }

  if (current == nullptr) {
    return nullptr;
  }

  Node* new_node = create_node(key);
  new_node->prev = current;
  new_node->next = current->next;
  current->next->prev = new_node;
  current->next = new_node;

  return head;
}

Node* delete_element_from_end(Node* head, int k) {
  if (head == nullptr || k <= 0) {
    return nullptr;
  }

  Node* current = head;
  while (current != nullptr && k > 0) {
    current = current->next;
    k--;
  }

  if (current == nullptr) {
    return nullptr;
  }

  if (current->prev == nullptr) {
    return head->next;
  }

  current->prev->next = current->next;
  if (current->next != nullptr) {
    current->next->prev = current->prev;
  }

  delete current;

  return head;
}

void save_list_to_file(Node* head, string filename) {
  if (head == nullptr) {
    return;
  }

  ofstream file(filename);
  if (!file.is_open()) {
    return;
  }

  Node* current = head;
  while (current != nullptr) {
    file << current->key << " ";
    current = current->next;
  }

  file.close();
}

int main() {
  int n = 10;
  Node* head = create_list(n);

  print_list(head);

  head = add_element_at_position(head, 11, 5);
  print_list(head);

  head = delete_element_from_end(head, 3);
  print_list(head);

  save_list_to_file(head, "list.txt");

  return 0;
}