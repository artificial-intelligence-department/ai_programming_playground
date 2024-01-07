#include <iostream>
#include <cmath> // for cosine and exponent functions
#include <random> // C++ marsanne twister pseudo-random'
#include <fstream>

using std::random_device, std::mt19937, std::uniform_int_distribution;

random_device device;
mt19937 generator(device());

void function(int number);

// Task 1 - Fill in matrix using a function from calculating task
// aij = cos(x^2)*exp(x) (formula from task 2)
double** matrixA();
// bij = |x| (formula from task 4)
int** matrixB();

// Task 2 - order matrix by technical task
int** order(int** arr, int size);
double** order(double** arr, int size);

template<class T>
T* rev_bubble_sort(T* arr, int size);

// Task 3 - calculate sums by technical task
int* sum(int** arr, int size);
int* sum(double** arr, int size);

// Task 4 - write to file
bool write_to_file(int* arr, int size);

// Task 5 - read from file
long long read_from_file_return_product();

// Task 6 - delete file (may be unused)
[[maybe_unused]] bool delete_file();

// size and filename specified in task,
// constexpr makes this variable known at compile time
constexpr int matrix_size = 10;
const std::string file = "file.txt";

int main() {
    constexpr int pull_request = 779;
    function(pull_request);

    return 0;
}

void function(int number) {
    // Remark: this code can be optimized using decltype,
    // so there won't be code repetitions

    bool is_written = false;
    if (number % 2 == 0) {
        double** matrix = matrixA();

        // order matrices
        matrix = order(matrix, matrix_size);

        for (int i = 0; i < matrix_size; i++)
        {
            for (int j = 0; j < matrix_size; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }

        // retrieve sums
        int* sums = sum(matrix, matrix_size);

        // Write and read from file
        is_written = write_to_file(sums, matrix_size);

        // clear memory
        for (int i = 0; i < matrix_size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] sums;
    }
    else {
        int** matrix = matrixB();

        // order matrices
        matrix = order(matrix, matrix_size);

        // retrieve sums
        int* sums = sum(matrix, matrix_size);

        // Write and read from file
        is_written = write_to_file(sums, matrix_size);

        // clear memory
        for (int i = 0; i < matrix_size; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        delete[] sums;
    }

    if (is_written) {
        read_from_file_return_product();
        delete_file();
    }
}

// clear memory of this function
double** matrixA() {
    // auto infers double** type
    auto matrix = new double*[matrix_size];
    for (int i = 0; i < matrix_size; i++) {
        matrix[i] = new double[matrix_size];
    }

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            matrix[i][j] = cos(pow(i + j, 2)) * exp(i + j);
        }
    }

    return matrix;
}

int** matrixB() {
    int** matrix = new int*[matrix_size];
    for (int i = 0; i < matrix_size; i++) {
        matrix[i] = new int[matrix_size];
    }

    uniform_int_distribution<> distribution(-10, 10);

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            matrix[i][j] = abs(distribution(generator));
        }
    }

    return matrix;
}

template<class T>
T* rev_bubble_sort(T* arr, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size - i - 1; j++)
            if (arr[j] < arr[j + 1]) // reverse order
                std::swap(arr[j], arr[j + 1]);

    return arr;
}

// column bubble sort
double** order(double** arr, int size) {
    for (int col = 0; col < size - 1; col++) {
        // sort j-th column in normal order
        for (int row = 0; row < size - 1; row++)
            for (int k = 0; k < size - row - 1; k++)
                if (arr[k][col] > arr[k + 1][col])
                    std::swap(arr[k][col], arr[k + 1][col]);
    }

    return arr;
}

int** order(int** arr, int size) {
    for (int row = 0; row < size; row++) {
        arr[row] = rev_bubble_sort(arr[row], size);
    }

    return arr;
}

int* sum(int** arr, int size) {
    int* sums = new int[size];
    int rand;

    // [0, size]
    uniform_int_distribution<> distribution(0, size - 1);

    for (int col = 0; col < size; col++) {
        sums[col] = 0;
        for (int i = 0; i < 4; i++) {
            rand = distribution(generator);
            sums[col] += arr[rand][col];
        }
    }

    return sums;
}

int* sum(double** arr, int size) {
    int* sums = new int[size];
    int rand;

    // [0, size]
    uniform_int_distribution<> distribution(0, size - 1);

    for (int col = 0; col < size; col++) {
        sums[col] = 0;
        for (int i = 0; i < 4; i++) {
            rand = distribution(generator);
            sums[col] += floor(arr[rand][col]);
        }
    }

    return sums;
}

bool write_to_file(int* arr, int size) {
    using std::ofstream;

    ofstream f(file);

    if (!f) return false;

    for (int i = 0; i < size; i++)
        f << arr[i] << " ";

    return true;
}

// Because we're multiplying 10 numbers, they might be very big
long long read_from_file_return_product() {
    using std::ifstream, std::cout;

    long long product = 1, buf;
    ifstream f(file);

    if (!f) throw std::exception();

    for (int i = 0; i < matrix_size; i++) {
        f >> buf;
        product *= buf;
    }

    // according to the task the value should be printed before return
    cout << product << "\n";
    return product;
}

[[maybe_unused]] bool delete_file() {
    // remove is a C-function
    bool is_removed = remove(file.c_str()) == 0;
    cout << (is_removed ? "File was removed" : "File wasn't removed");
    return is_removed;
}