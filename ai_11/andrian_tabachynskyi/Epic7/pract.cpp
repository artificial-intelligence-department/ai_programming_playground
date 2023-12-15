#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

float calculatevalue(float pullRequestNumber) {
    return pow(pullRequestNumber, 0.5) * 2;
}

vector<vector<float>> createfloatmatrix() {
    vector<vector<float>> matrix(10, vector<float>(10));
    for (int i = 0; i < 10; ++i) {//10 використання циклу for
        for (int j = 0; j < 10; ++j) {
            float randomValue = static_cast<float>(rand()) / RAND_MAX;
            matrix[i][j] = calculatevalue(randomValue);
        }
    }
    return matrix;
}


void sortColumns(vector<vector<float>>& matrix) {
    for (int col = 0; col < matrix[0].size(); ++col) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix.size() - i - 1; ++j) {
                if (matrix[j][col] > matrix[j + 1][col]) {
                    swap(matrix[j][col], matrix[j + 1][col]);
                }
            }
        }
    }
}


void sortRows(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size() - i - 1; ++j) {
            if (matrix[j][0] < matrix[j + 1][0]) {
                swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}

vector<vector<int>> createintmatrix() {
    vector<vector<int>> matrix(10, vector<int>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            float randomValue = static_cast<float>(rand()) / RAND_MAX;
            matrix[i][j] = static_cast<int>(calculatevalue(randomValue));
        }
    }
    return matrix;
}

int* calculateSums(vector<vector<float>>& matrix) {
    static int sums[10] = { 0 }; 
    for (int col = 0; col < matrix[0].size(); ++col) {
        int elementsToSum = min(4, static_cast<int>(matrix.size())); 
        float columnSum = 0.0;
        for (int i = 0; i < elementsToSum; ++i) {
            columnSum += matrix[i][col];
        }
        sums[col] = static_cast<int>(columnSum); 
    }
    return sums;
}
//в коді використано функції роботи з файлами, для того, щоб записати у файл
//в коді використано функції роботи з файлами, для того, щоб зчитати з файлу


bool ArrayToFile(const int* array, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 10; i++) {
            file << array[i] << ' ';
        }
        file.close();
        return true;
         
    }
    return false;
}

int calculateelementsinfile(const string& filemane) {
    ifstream file(filemane);
    int m = 1;
    if (file.is_open()) {
        int value;
        while (file >> value) {
            m *= value;
        }
        file.close();
    }
    return m;
}
bool filedelete(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        return true;
    }
    return false;
}

int main() {
    const int pullRequestNumber = 1004;

    const string filename = "F1.txt";
    bool isEven = pullRequestNumber % 2 == 0;


    if (isEven) {
        vector<vector<float>> matrix = createfloatmatrix();
        sortColumns(matrix);

        for (const auto& row : matrix) {
            for (float value : row) {
                cout << value << ' ';
            }
            cout << endl;
        }
        int* sums = calculateSums(matrix);
        cout << "Sum of row: " << endl;
        for (int i = 0; i < 10; i++) {
            cout << sums[i] << ' ';
        }
        cout << endl;

        if (ArrayToFile(sums, "F1.txt")) {
            cout << "Sums have wrote in file" << endl;
        }
        else {
            cout << "Sums hsven`t wrote in file" << endl;
        }

        int m = calculateelementsinfile(filename);
        cout << "Calculating:" << m << endl;

        if (filedelete(filename)) {
            cout << "File is deleted." << endl;
        }
        else {
            cout << "File isn`t deleted" << endl;
        }

    }
    else {
        vector<vector<int>> matrix = createintmatrix();
        sortRows(matrix);

        for (const auto& row : matrix) {
            for (int value : row) {
                cout << value << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}