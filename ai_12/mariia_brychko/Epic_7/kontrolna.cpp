#include <iostream> // Включення заголовкового файлу для вводу/виводу зі стандартною бібліотеки С++
#include <cstdlib> // Включення заголовкового файлу для rand(), srand()
#include <fstream> // Включення заголовкового файлу для роботи з файлами в С++
#include <cstdio> // для функції remove()

const int ROWS = 10;     //оголошення констант
const int COLS = 10;
const int NUM_SUMS = 10;
const int CONSTANT = 1003;
const std::string FILENAME = "output.txt"; // Константа з іменем файлу


// Функція для генерування матриці з цілими числами
int** generateIntMatrix() {   // Повертає вказівник на двомірний масив цілих чисел - матрицю
     int** matrix = new int*[ROWS];  // Оголошується двомірний масив (матриця) з вказівниками на цілі числа
    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = new int[COLS];  // Кожному вказівнику рядка призначається новий масив для кожного стовпчика у рядку
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = CONSTANT / (i + j + 1);  // Заповнення кожного елементу матриці цілим числом
        }
    }
    return matrix;  // Повернення готової матриці
}

// Функція для виводу матриці з цілими числами
// matrix - вказівник на двомірний масив цілих чисел (матрицю), яку ми хочемо вивести
void printIntMatrix(int** matrix) {
    for (int i = 0; i < ROWS; ++i) {  // Ітерація через рядки матриці
        for (int j = 0; j < COLS; ++j) {  // Ітерація через стовпці матриці
            std::cout << matrix[i][j] << " ";  // Виведення кожного елемента матриці
        }
        std::cout << std::endl;  // Перехід на новий рядок після виведення всіх елементів у рядку
    }
}

// Функція для підрахунку сум для випадкових елементів у стовпцях матриці
// matrix - вказівник на двомірний масив цілих чисел (матрицю), з якою ми працюємо
// sums - вказівник на одномірний масив цілих чисел, куди зберігаються обчислені суми
void calculateSums(int** matrix, int* sums) {
    for (int i = 0; i < COLS; ++i) { // Ітерація через стовпці матриці
        int sum = 0; // Ініціалізація змінної для зберігання суми
        for (int j = 0; j < NUM_SUMS; ++j) { // Ітерація для обчислення суми для випадкових елементів
            int randomRow = rand() % ROWS; // Генерація випадкового рядка
            sum += matrix[randomRow][i]; // Додавання випадкових елементів у суму
        }
        sums[i] = sum; // Зберігання обчисленої суми в масиві sums
    }
}

// Функція для запису значень цілочисельного масиву у файл
// arr - вказівник на цілочисельний масив, значення якого будуть записані у файл
// filename - назва файлу, у який відбуватиметься запис
bool writeArrayToFile(const int* arr, const std::string& filename) {
    std::ofstream file(filename); // Відкриття файлу для запису
    if (file.is_open()) { // Перевірка чи файл вдалося відкрити
        for (int i = 0; i < NUM_SUMS; ++i) { // Ітерація через елементи масиву
            file << arr[i] << " "; // Запис значень масиву у файл
        }
        file.close(); // Закриття файлу після запису
        return true; // Повернення true, якщо запис відбувся успішно
    }
    return false; // Повернення false, якщо не вдалося відкрити файл
}

// Функція для розрахунку добутку елементів, що записані у файлі
// filename - назва файлу, з якого читаються значення для обчислення добутку
long long calculateProductFromFile(const std::string& filename) {
    std::ifstream file(filename); // Відкриття файлу для читання
    long long product = 1; // Ініціалізація змінної для збереження добутку

    if (file.is_open()) { // Перевірка чи файл вдалося відкрити
        int value;
        while (file >> value) { // Зчитування значень з файлу та обчислення добутку
            product *= value;
        }
        file.close(); // Закриття файлу після читання
    } else {
        std::cerr << "Unable to open file '" << filename << "'" << std::endl; // Повідомлення про помилку, якщо не вдалося відкрити файл
    }

    return product; // Повернення обчисленого добутку
}

// Функція для видалення файлу
// filename - назва файлу, який слід видалити
void deleteFile(const std::string& filename) {
    if (remove(filename.c_str()) == 0) { // Виклик функції remove для видалення файлу
        std::cout << "File '" << filename << "' has been deleted successfully." << std::endl; // Виведення повідомлення про успішне видалення файлу
    } else {
        std::cerr << "Error deleting file '" << filename << "'" << std::endl; // Виведення повідомлення про помилку, якщо видалення файлу не вдалося
    }
}

// Основна функція програми
int main() {
    srand(time(NULL)); // Ініціалізація генератора випадкових чисел

    // Створення та вивід початкової матриці
    int** intMatrix = generateIntMatrix();
    std::cout << "Original Integer Matrix:" << std::endl;
    printIntMatrix(intMatrix);

    // Підрахунок сум для випадкових елементів у стовпцях матриці та вивід результатів
    int sums[NUM_SUMS] = {0}; // Масив для зберігання сум
    calculateSums(intMatrix, sums);
    std::cout << "\nSums for randomly selected elements in each column:" << std::endl;
    for (int i = 0; i < NUM_SUMS; ++i) {
        std::cout << "Sum " << i + 1 << ": " << sums[i] << std::endl;
    }

    // Створення нового цілочисельного статичного масиву з 10 елементів, які містять суму (без дробової частини)
    int newIntArray[NUM_SUMS] = {0};
    for (int i = 0; i < NUM_SUMS; ++i) {
        newIntArray[i] = static_cast<int>(sums[i]); // Відкидання дробової частини
    }

    // Вивід нового цілочисельного масиву
    std::cout << "\nNew Integer Array with sums (without decimal part):" << std::endl;
    for (int i = 0; i < NUM_SUMS; ++i) {
        std::cout << newIntArray[i] << " ";
    }
    std::cout << std::endl;

    // Звільнення пам'яті, що була виділена для матриці
    for (int i = 0; i < ROWS; ++i) {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;

    // Запис значень нового статичного масиву у файл та вивід результату запису
    std::string filename = "output.txt";
    bool writeSuccess = writeArrayToFile(newIntArray, filename);
    if (writeSuccess) {
        std::cout << "\nValues have been written to the file '" << filename << "' successfully." << std::endl;
    } else {
        std::cout << "\nFailed to write values to the file '" << filename << "'." << std::endl;
    }

    // Розрахунок добутку значень, записаних у файл, та вивід результату
    long long product = calculateProductFromFile(FILENAME);
    if (product != 1) {
        std::cout << "\nProduct of values in the file '" << FILENAME << "': " << product << std::endl;
    } else {
        std::cout << "\nThe file '" << FILENAME << "' is empty or does not exist." << std::endl;
    }

    // Видалення файлу та вивід результату видалення
    deleteFile(FILENAME);

    return 0; // Повернення нуля, що означає успішне завершення програми
}