#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

const char file[10] = "F2.txt";

double** generateMatrix(const int number) 
{
    double** arr = new double*[10];
    for (int i = 0; i < 10; ++i) 
    {
        //3.в коді використана як мінімум одна дійсний з подвійною точністю змінна
        arr[i] = new double[10];
    }

    if (number % 2 == 0) 
    {
        for (int i = 0; i < 10; ++i) 
        {
            for (int j = 0; j < 10; ++j) 
            {
                //в коді використаний двовимірний масив 
                //в коді використано математичні операції та математичні функції
                arr[i][j] = (sqrt(std::abs(i - 1)) - sqrt(j)) / (1 + std::pow(i, 2) / 2 + std::pow(j, 2) / 4);
                //в коді використано оператори break і continue
                if(arr[i][j] == 0)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    for (int i = 0; i < 10; ++i) 
        {
            for (int j = 0; j < 10; ++j) 
            {
                arr[i][j] = 1 / (tan(exp(j))); ;
            }
        }

    return arr;
}

// Function to sort columns of the matrix using bubble sort and return the sorted matrix
double** bubbleSortColumns(double** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9 - j; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    // Swap elements in the column
                    double temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }

    // Return the sorted matrix
    return matrix;
}


void reversbubbleSortColumns(double** matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9 - j; ++k) {
                if (matrix[k][i] < matrix[k + 1][i]) {
                    // Swap elements in the column
                    double temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }
}

// 12. в коді використано перевантаження функції 
// Function to process and sort the generated matrix
double** fucntion1(double** matrix, int a) 
{
    bubbleSortColumns(matrix);

    // Return the sorted matrix
    return matrix;
}


double** fucntion1(double** matrix)


{
    reversbubbleSortColumns(matrix);

    // Return the sorted matrix
    return matrix;
}

int* calculateSums(double** matrix) 


{
    //в коді використаний одновимірний масив 
    static int sums[10];

    // Seed for random number generation
    std::srand(std::time(0));

    for (int i = 0; i < 10; ++i) {
        int columnSum = 0;

        // Calculate sum of 3 or 4 randomly chosen elements in each column
        for (int j = 0; j < std::min(4, 10); ++j) {
            // Generate a random index within the column
            int randomIndex = std::rand() % 10;

            // Add the integer part of the element to the sum
            columnSum += static_cast<int>(matrix[randomIndex][i]);
        }

        // Store the sum in the array
        sums[i] = columnSum;
    }

    return sums;
}

bool files(const int* arr, int size) 
{
    //в коді використано функції роботи з файлами, для того, щоб записати у файл
    std::ofstream f2(file);

    // Check if file F2.txt was opened successfully
    if (!f2.is_open()) {
        std::cout << "Unable to open F2.txt" << std::endl;
        return false; // Return false in case of a file opening error
    }

    // Write values from the array to the file
    for (int i = 0; i < size; i++) 
    {
        // Check if the value starts with the letter "A"
            // Write the value to file F2.txt
            f2 << arr[i] << std::endl;
        
    }

    // Close the file
    f2.close();

    return true; // Return true to indicate success
}

int files1()
{
     //20. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    // Відкриття файлу F1 для считання
    std::ifstream f1(file);
    
    // Перевірка чи файл F1 вдалося відкрити
    if (!f1.is_open()) 
    {
        std::cout << "Unable to open F1.txt" << std::endl;
        return 1; // Помилка відкриття файлу
    }
    int wordCount = 1;
    int word;

    // Підрахунок слів у файлі F2
    //в коді використаний while цикл
    while (f1 >> word) 
    {
        wordCount *= word;
    }
    std::cout << wordCount << " ";
    f1.close();
    return wordCount;
}

bool deleteFile() 
{
    if (std::remove(file) != 0) {
        std::cout << "Error deleting file: " << file<< std::endl;
        return false; // Return false if deletion fails
    } else {
        std::cout << "File deleted successfully: " << file << std::endl;
        return true; // Return true if deletion is successful
    }
}

int main() 
{
    //в коді використана як мінімум одна цілочисельна константа
    const int number = 810;
    bool coma = false;
    double** result = generateMatrix(number);

    // Display the generated matrix
    //в коді використана як мінімум одна дійсна змінна
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << result[i][j] << "  ";
            if(abs(result[i][j]) < 0.99 )
            {
                coma = true;
            }
        }
        std::cout << std::endl;
    }

    int* sums;
    //в коді використано параметри та аргументи функції
    //в коді використані умовні оператори та розгалуження
    if(coma)
    {
    double** sorted = fucntion1(result, 0);
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << sorted[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    sums = calculateSums(sorted);
    }

    else
    {
    double** reverse = fucntion1(result);
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; j++)
        {
            //в коді використано оператори виведення та введення даних
            std::cout << reverse[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    sums = calculateSums(reverse);
    }

    std::cout << "Sums: ";
    for (int i = 0; i < 10; ++i) 
    {
        std::cout << sums[i] << " ";
    }
    std::cout << std::endl;
    //в коді використана як мінімум одна цілочисельна змінна

    int size = sizeof(sums);

   if(files(sums, size))
   {
        std::cout << "Succes" << std::endl;
        files1();
   }
   else
   {
        std::cout << "Error" << std::endl;
   }

    std::cout << std::endl;
    deleteFile();
    // Don't forget to free the allocated memory
    for (int i = 0; i < 10; i++) 
    {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
