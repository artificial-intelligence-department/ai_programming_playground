#include <iostream>
#include <cstdlib>  
#include <ctime> 
#include <fstream>
#include <cstdio>

using namespace std; 
int* calculateSumsAndCreateArray(double** matrix, int rows, int cols) {
	const int numberOfSums = 10;
	int* sumsArray = new int[numberOfSums];

	srand(time(nullptr));

	for (int j = 0; j < cols; ++j) {
		int sum = 0; //в коді використана як мінімум одна дійсна змінна
		for (int i = 0; i < numberOfSums; ++i) {
			int randomRow = rand() % rows;
			sum += matrix[randomRow][j];
		}

		sumsArray[j] = static_cast<int>(sum);
	}

	return sumsArray;
}
    double** matrix(int rows, int columns) {		
		double** matrix = new double*[rows]; // в коді використаний двовимірний масив
		for (int i = 0; i < rows; i++) {
			matrix[i] = new double[columns];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i][j] = cos(j)-i; //в коді використано математичні операції та математичні функції
			}
		}
		return matrix;
	}
	void printMatrix(double** mas, int rows, int columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout<<"Element ["<<i+1<<"]["<<j+1<<"]: "<<mas[i][j]<<endl;
			}
		}
	}
	void printMatrix(int mas[], int columns) {
		for (int i = 0; i < columns; ++i) {
			cout << mas[i] << " ";
		}
	}
	void sortColumns(double** matrix, int rows, int columns) {
		for (int j = 0; j < columns; ++j) {
			for (int i = 0; i < rows - 1; ++i) {
				for (int k = 0; k < rows - i - 1; ++k) {
					if (matrix[k][j] > matrix[k + 1][j]) {
						double temp = matrix[k][j];
						matrix[k][j] = matrix[k + 1][j];
						matrix[k + 1][j] = temp;
					}
				}
			}
		}
	}
	void sortColumns(double matrix[], int rows) { //в коді використано перевантаження функції
		for (int i = 0; i < rows - 1; ++i) { //в коді використаний for цикл
			for (int j = 0; j < rows - i - 1; ++j) {
				if (matrix[j] > matrix[j + 1]) {
					int temp = matrix[j];
					matrix[j] = matrix[j + 1];
					matrix[j + 1] = temp;
				}
			}
		}
	}
	bool saveArrayToFile(const int* array, int size, const string& filename) {
		ofstream file(filename); //в коді використано функції роботи з файлами, для того, щоб записати у файл

		if (!file.is_open()) {
			cout << "Unable to open file" << endl;
			return false;
		}
		for (int i = 0; i < size; ++i) {
			file << array[i] << " ";
		}
		file.close();
		return true;
	}
	long long calculateProductFromFile(const string& filename) {
		ifstream file(filename); //в коді використано функції роботи з файлами, для того, щоб зчитати з файлу

		if (!file.is_open()) {
			cout << "Unable to open file" << endl;
			return 0; 
		}
		long long product = 1;
		int value;
		while (file >> value) {
			product *= value;
		}
		file.close();
		return product;
	}
	void deleteFile(const string& filename) {
		if (remove(filename.c_str()) != 0) {
			cout << "Error deleting file" << std::endl;
		}else
		cout << "File deleted"<< endl;
	}

int main() { 
	int rows = 10, columns = 10;  //в коді використана як мінімум одна цілочисельна змінна
	const int PR = 840; //в коді використана як мінімум одна цілочисельна константа
	double** mas=matrix(rows, columns); //в коді використана як мінімум одна дійсний з подвійною точністю змінна
	const string filename = "file.txt";
	cout << "Standart matrix" << endl;
	printMatrix(mas, rows, columns); //в коді використано параметри та аргументи функції
	sortColumns(mas, rows, columns);
	cout << "Matrix after sort" << endl; //в коді використано оператори виведення та введення даних
	printMatrix(mas, rows, columns);
	int* sumsArray = calculateSumsAndCreateArray(mas, rows, columns); //в коді використаний одновимірний масив
	cout << "Sum of array:" << endl;
	printMatrix(sumsArray, rows);
	cout << endl;
	if (saveArrayToFile(sumsArray, columns, filename)) { //в коді використані умовні оператори та розгалуження
		cout << "Sums Array saved to file" << endl;
	}
	else {
		cout << "Error saving Sums Array to file" << endl;
	}
	long long product = calculateProductFromFile(filename);
	cout << "Product of elements in the file: " << product << endl;
	deleteFile(filename);
}