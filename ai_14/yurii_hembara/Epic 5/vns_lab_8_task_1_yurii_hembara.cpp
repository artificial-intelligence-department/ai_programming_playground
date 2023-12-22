#include <iostream>
#include <fstream>
#include <vector>

struct Student {
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string homeAddress;
    std::string group;
    double rating;
};

// Функція для виведення деталей студента
void printStudent(const Student& student) {
    std::cout << "Last Name: " << student.lastName << std::endl;
    std::cout << "First Name: " << student.firstName << std::endl;
    std::cout << "Middle Name: " << student.middleName << std::endl;
    std::cout << "Home Address: " << student.homeAddress << std::endl;
    std::cout << "Group: " << student.group << std::endl;
    std::cout << "Rating: " << student.rating << std::endl;
    std::cout << "------------------------" << std::endl;
}

// Функція для створення бінарного файлу із елементами студентів
void createBinaryFile(const std::string& fileName, const std::vector<Student>& students) {
    std::ofstream outFile(fileName, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const auto& student : students) {
        outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    outFile.close();
}

// Функція для виведення вмісту файлу, видаляючи студентів з рейтингом менше minRating
void printFileContent(const std::string& fileName, double minRating) {
    std::ifstream inFile(fileName, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rating >= minRating) {
            printStudent(student);
        }
    }

    inFile.close();
}

// Функція для знищення елементів з рейтингом меншим за заданий
void modifyFile(const std::string& fileName, double minRatingToDelete) {
    std::fstream file(fileName, std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Error opening file for reading/writing." << std::endl;
        return;
    }

    std::vector<Student> tempStudents;
    Student currentStudent;
    while (file.read(reinterpret_cast<char*>(&currentStudent), sizeof(Student))) {
        if (currentStudent.rating >= minRatingToDelete) {
            tempStudents.push_back(currentStudent);
        }
    }

    // Перезаписуємо файл з новими даними
    file.close();
    file.open(fileName, std::ios::binary | std::ios::out | std::ios::trunc);
    for (const auto& student : tempStudents) {
        file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    file.close();
}

int main() {
    // Створюємо вектор студентів для формування файлу
    std::vector<Student> students = {
        {"Mazur", "Oleg", "Nazarovych", "Chimichna Street 1", "Group1", 11.1},
        {"Chorniy", "Orest", "Igorovych", "Chimichna Street 2", "Group2", 22.2},
        {"Molyachchiy", "Yulian", "Yaroslavovych", "Chimichna Street 3", "Group3", 33.3}
    };

    // Встановлюємо рейтинг для знищення елементів
    double minRatingToDelete;
    std::cout << "Enter the minimum rating to delete students: ";
    std::cin >> minRatingToDelete;

    // Формуємо файл
    createBinaryFile("students.bin", students);

    // Виводимо вміст файлу перед модифікацією
    std::cout << "File content before modification:" << std::endl;
    printFileContent("students.bin", minRatingToDelete);

    // Змінюємо файл (видаляємо елементи)
    modifyFile("students.bin", minRatingToDelete);

    // Виводимо вміст файлу після модифікації
    std::cout << "File content after modification:" << std::endl;
    printFileContent("students.bin", minRatingToDelete);

    return 0;
}
