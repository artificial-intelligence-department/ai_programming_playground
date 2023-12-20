#include <iostream>
#include <memory>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
std::shared_ptr<Node<T>> reverse(std::shared_ptr<Node<T>> head) {
    std::shared_ptr<Node<T>> prev = nullptr;
    auto current = head;
    std::shared_ptr<Node<T>> next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

template <typename T>
void printList(const std::shared_ptr<Node<T>>& head) {
    auto current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    auto head = std::make_shared<Node<int>>(1);
    head->next = std::make_shared<Node<int>>(2);
    head->next->next = std::make_shared<Node<int>>(3);
    head->next->next->next = std::make_shared<Node<int>>(4);
    head->next->next->next->next = std::make_shared<Node<int>>(5);
    
    std::cout << "Вихідний список: ";
    printList(head);
    
    head = reverse(head);
    
    std::cout << "Обернений список: ";
    printList(head);


    return 0;
}