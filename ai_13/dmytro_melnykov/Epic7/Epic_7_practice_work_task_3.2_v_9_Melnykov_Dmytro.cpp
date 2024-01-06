#include <iostream>

int main() {
    //Інінціалізація значень
    int wordsonpage = 30;
    int totalPages = 948;
    int popularword = 5;
    double size = 2.0;

    //обчислємо кількість стлів та довжину
    int totalWords = wordsonpage * totalPages;
    double length = popularword * size;
    double alllenght = totalWords * length;

    //результат
    std::cout << "кількість рос слів в словнику: " << totalWords << std::endl;
    std::cout << "Довжина відрізку рос слів: " << alllenght << " мм" << std::endl;

    return 0;
}
