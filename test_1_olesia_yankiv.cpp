//926
//створити констатнту яка дорівнює номеру вашого пулл реквесту в 7-му епіку і якщо вона парна то:
	//а. написати та викликати функцію, яка створить та поверне матрицю розміром 10*10 і буде заповнена 
	//значеннями з певної математичної функції і повертає числа з плаваючою крапкою
//якщо вона не парна то:
	//b. викликати функцію яка створить та поверне матрицю розміром 10*10 і буде заповнена значеннями з певної 
	//математичної функції і повертає цілі числа
//(Для матриць забороняється використання векторів. Математичну функцію виберіть з одного з завдань з вашої розрахункової. 
//Код напишіть так, що він працюватиме навіть якщо коснтанту змінити на парну чи не парну, тобто якщо ви писали код під цифру 70, 
//а я перепишу під цифру 71, програма мала б запускатись в обох випадках.)
. //отриману матрицю потрібно передати як параметр іншій створеній та перевантаженій функції, яка має два варіанти реалізації:
//а. таку що отримує матрицю з числами з плаваючою крапкою, та отримує значення з плаваючою крапкою 
//	(ця функція має сортувати стовпці по зростанню методом бульбашки та повертати матрицю)
//b. таку що отримує матрицю з цілими числами, та отримує ціло-чисельне значення 
//	(ця функція має сортувати рядки по спаданню методом бульбашки та повертати матрицю)
//(другий параметр при виклику функції це, або значення пулл реквесту, або добуток значення пулл реквесту та числа з плаваючою крапкою, 
//що вводиться з консолі)

//3.  отриману матрицю передати у функцію яка рахує 10 сум для 3-х або 4-х рандомно взятих елементів у кожному з стовпців, 
//та створює новий цілочисельний статичний масив з 10 елементів, які містять вищезгадану суму 
//(у коді має бути передбачено умову, що якщо сума має дробову частину то вона відкидається і тільки тоді записується у масив. 
//Якщо не виходить написати код який бере 3-4 рандомні елементи масиву у стовпці, то пишіть про це коментар і рахуйте суму всіх елементів стовпця). 
//Функція повертає новостворений статичний масив. 

4//. Новостворений статичний масив повинен буде переданий іншій створеній функції, 
//яка створює файл та записує значення статичного масиву у цей файл. 
//Функція повертає true якщо дія відбулась і false, якщо ні.

#include <iostream>
#include <fstream>
#include <ctime>
#include
using namespace std;

const int size = 10;
const int CONST = 926;

void matrixCreation(float matrix[size][size], int constant)  //matrix size 10x10 
{
    for (int i = 0; i < size; i++) { //nested function for 
        for (int j = 0; j < size; j++) {
            matrix[i][j] = constant + (i + j);
        }
    }
}

void sortColumns(float matrix[size][size]) 
{
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size - i - 1; k++) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    float temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}
void sortRows(float matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    float temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

bool writeToFile(int result[size]) {
    const char* filename = "output.txt"; // File to write the output values
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) 
	{
        cerr << "ERROR" << endl;
        return false; 
    }

    for(int i = 0; i < size; i++) 
	{
    outputFile << result[i] << " "; 
    }

    outputFile.close(); 
    return true; 
}
//генерація рандомних чисел
int randomNumbers (int minimum, int maximum)
{
	return rand () % (maximum-minimum+1) + minimum;
}

int* sumCalculation (float matrix [size][size], int CONST)
{
    int* resultArray = new int [size];

}
srand(static_cast<unsigned>(time(0)));

for (int j= 0; j<size; j++)
{
	int sum =0;
	for (int i= 0; i<3||i<4; i++)
	{
		int randomPow = getRandomValue (0, size -1);
		sum += static_cast<int>(matrix[randomRow][j]);
	}
	resultArray [j] = sum;
	return resultValue;
}

int main()
{
	const int constant = 962;
	float matrix [SIZE][SIZE];
	createMatrix (matrix, constant);

	setColumns (matrix);

	int pullRequest;
	cout<<"Your pull request" <<endl;
	int pullRequestValue;  // Значення пулл реквесту або його добуток
    std::cout << "Enter pull request value or its product with a float value: ";
    std::cin >> pullRequestValue;

    // Вибір функції для сортування в залежності від типу значення
    if (pullRequestValue % 1 == 0) {
       
        int intMatrix[SIZE][SIZE];
       

        sortRows(intMatrix);
    } else {
        
        float floatMatrix[SIZE][SIZE];
        

        sortColumns(floatMatrix);
    }

    
    int* resultArray = calculateSums(matrix, pullRequestValue);

   
    bool success = writeToFile(resultArray);

    
    if (success) 
	{
        std::cout << "Array successfully written to file." << std::endl;
    } else {
        std::cout << "Failed to write array to file." << std::endl;
    }

    return 0;
}