#include <iostream>
using namespace std;

// Структура вузла списку
struct Node {
    int numbers;    // Це поле numbers представляє число, яке зберігається у вузлі списку.
    Node* next;     // Вказівник next вказує на наступний елемент списку.
    
    Node(int val) : numbers(val), next(nullptr) {}  // Конструктор створює новий вузол з заданим числовим значенням val та встановлює вказівник next на nullptr.
                                                    //Node(int val): Це звичайний конструктор, який приймає ціле число val як параметр.
                                                    //numbers(val): Ця частина ініціалізує поле numbers структури Node значенням, яке 
                                                    //передано через параметр конструктора val. Тобто, поле numbers буде містити значення, 
                                                    //передане під час створення нового вузла.
                                                    //next(nullptr): Цей фрагмент ініціалізує вказівник next значенням nullptr. У вузлі 
                                                    //списку Node, next вказує на наступний елемент у послідовності. При створенні нового 
                                                    //вузла конструктор встановлює початкове значення next як nullptr, що означає, що 
                                                    //спочатку елемент не має наступника і є останнім в списку.
};


// Функція для реверсу списку
Node* reverse(Node* head) {  //приймає вказівник на об'єкт типу Node під назвою head, і повертає вказівник на об'єкт типу Node.
    Node *prev = nullptr, *current = head, *next = nullptr;
    
    while (current != nullptr) {
        next = current->next;     // Зберігаємо посилання на наступний вузол перед зміною вказівника next
        current->next = prev;     // Змінюємо вказівник поточного вузла таким чином, щоб він вказував на попередній вузол
        prev = current;           // Переміщаємо вказівник prev на поточний вузол
        current = next;           // Переміщаємо вказівник current на наступний вузол
    }
    
    return prev; // Після завершення циклу поточний вузол (current) буде nullptr, а попередній вузол (prev) стане останнім елементом, тобто новим початком реверсованого списку
}

//Node *prev = nullptr, *current = head, *next = nullptr;: Оголошуються три вказівника: prev, current та next. prev вказуватиме на попередній вузол у зворотньому списку, current на поточний вузол у вихідному списку, а next на наступний вузол у вихідному списку.
//while (current != nullptr) { ... }: Це цикл, який працює до тих пір, поки current не стане nullptr. У кожній ітерації циклу виконуються наступні дії:
//a. next = current->next;: Зберігаємо посилання на наступний вузол у змінну next, щоб не втратити зв'язок під час реверсування.
//b. current->next = prev;: Змінюємо вказівник next поточного вузла так, щоб він вказував на попередній вузол. Це призводить до зворотного зв'язку між вузлами, роблячи реверс списку.
//c. prev = current;: Переміщаємо вказівник prev на поточний вузол, оскільки він стане наступним вузлом у реверсованому списку.
//d. current = next;: Переміщаємо вказівник current на наступний вузол у вихідному списку, для продовження реверсування.
//return prev;: Після завершення циклу змінна prev містить останній елемент реверсованого списку, тобто новий початок. Функція повертає цей вказівник, який тепер вказує на початок реверсованого списку.


// Допоміжна функція для виведення списку
void printList(Node* head) {
    Node* temp = head; // Оголошення вказівника temp, що починається з початку списку (вказівник head)
    while (temp != nullptr) { // Поки вказівник temp не вказує на nullptr (кінець списку)
        cout << temp->numbers << " "; // Виведення числового значення поточного вузла на екран
        temp = temp->next; // Переміщення вказівника temp на наступний вузол списку
    }
    cout << endl; // Виведення порожнього рядка для завершення виводу списку
}

int main() {
    // Створення зразка списку: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(10);   // Node* head: Це оголошення вказівника head типу Node*, що означає, що вказівник буде вказувати на об'єкт 
                                //типу Node. new Node(1): Це виклик оператора new, який створює новий об'єкт типу Node та передає число 1 
                                //як аргумент конструктору цього об'єкта. Kонструктор Node(int val) приймає один аргумент типу int, 
                                //тому це створює новий вузол (елемент) списку з числовим значенням 1. Node* head = ...: Призначаємо 
                                //адресу цього нового об'єкта вказівнику head, тобто зробили так, що head тепер вказує на цей новий 
                                //об'єкт, що був створений оператором new.
    
    head->next = new Node(20); // Оскільки head вказує на перший вузол, head->next означає доступ до поля next першого вузла.
    head->next->next = new Node(30); // Створюємо третій елемент зі значенням 3 та прив'язуємо його до другого через поле next
    head->next->next->next = new Node(40); // Створюємо четвертий елемент зі значенням 4 та прив'язуємо його до третього через поле next
    head->next->next->next->next = new Node(50); // Створюємо п'ятий елемент зі значенням 5 та прив'язуємо його до четвертого через поле next
    
    cout << "Output list: ";
    printList(head);
    
    // Реверсія списку
    head = reverse(head); // Викликаємо функцію reverse для реверсування списку та оновлюємо вказівник head новим початком реверсованого списку
    
    cout << "Reversed list: ";
    printList(head); 
    
    return 0;
}