#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

struct Student {
    std::string fullName;
    std::string phoneNumber;
    std::string group;
    std::vector<int> grades;
};

double calculateAverage(const std::vector<int>& grades) {
    if (grades.empty()) {
        return 0.0;
    }

    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}

int main() {
    const int maxStudents = 5;
    const int requiredGrade = 75; // Задайте вашу константу тут

    std::vector<Student> students;

    char addAnotherStudent = 'y';

    while (addAnotherStudent == 'y' && students.size() < maxStudents) {
        Student currentStudent;

        std::cout << "Enter data for a student:\n";
        std::cout << "Full Name: ";
        std::getline(std::cin, currentStudent.fullName);

        std::cout << "Phone Number: ";
        std::getline(std::cin, currentStudent.phoneNumber);

        std::cout << "Group: ";
        std::getline(std::cin, currentStudent.group);

        std::cout << "Enter grades for 3 subjects:\n";
        for (int j = 0; j < 3; ++j) {
            int grade;
            std::cout << "Subject " << (j + 1) << ": ";
            std::cin >> grade;
            currentStudent.grades.push_back(grade);
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        students.push_back(currentStudent);

        if (students.size() < maxStudents) {
            std::cout << "Do you want to add another student? (y/n): ";
            std::cin >> addAnotherStudent;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Maximum number of students reached.\n";
        }
    }

    // Відкриття файлу для запису
    std::ofstream outputFile("students_data.txt");

    // Перевірка чи вдалося відкрити файл
    if (outputFile.is_open()) {
        // Запис даних у файл
        for (const auto& student : students) {
            outputFile << "Full Name: " << student.fullName << "\n";
            outputFile << "Phone Number: " << student.phoneNumber << "\n";
            outputFile << "Group: " << student.group << "\n";
            outputFile << "Grades: ";
            for (const auto& grade : student.grades) {
                outputFile << grade << " ";
            }
            outputFile << "\n\n";
        }

        // Закриття файлу
        outputFile.close();
        std::cout << "Data has been written to students_data.txt.\n";
    } else {
        std::cerr << "Unable to open the file for writing.\n";
        return 1;
    }

    // Перевірка та видалення студентів
    for (auto it = students.begin(); it != students.end(); ) {
        if (calculateAverage(it->grades) < requiredGrade) {
            std::cout << "Average grade is below the required grade for student "
                      << it->fullName << ". Removing from the file.\n";

            // Видалення даного студента
            it = students.erase(it);
        } else {
            ++it;
        }
    }

    // Оновлення файлу зі списком студентів
    std::ofstream updatedFile("updated_students_data.txt");

    // Перевірка чи вдалося відкрити файл
    if (updatedFile.is_open()) {
        // Запис оновлених даних у файл
        for (const auto& student : students) {
            updatedFile << "Full Name: " << student.fullName << "\n";
            updatedFile << "Phone Number: " << student.phoneNumber << "\n";
            updatedFile << "Group: " << student.group << "\n";
            updatedFile << "Grades: ";
            for (const auto& grade : student.grades) {
                updatedFile << grade << " ";
            }
            updatedFile << "\n\n";
        }

        // Закриття файлу
        updatedFile.close();
        std::cout << "Data has been updated and written to updated_students_data.txt.\n";
    } else {
        std::cerr << "Unable to open the file for writing.\n";
        return 1;
    }

    return 0;
}
