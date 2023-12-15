#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


double double_f()
{
   int x=rand(), y=rand ();
            double a=(1-y)*pow(x+y,2)/pow((x+4,3)/exp(-(x-2))+(pow (x,3)+4));
            double b=(1+cos(y-2))/(pow(x,2)+pow(sin(y-2),2));
            return a/b;  
}
double** a( ) {
    int N=10;
    double** arr = new double* [N];
    for (int i=0; i<N; ++i)
    {
        arr[i]=new double[N];
        for (int j = 0; j < N; j++)
        {
            int x=rand(), y=rand ();
            double a=(1-y)*pow(x+y,2)/pow((x+4,3)/exp(-(x-2))+(pow (x,3)+4));
            double b=(1+cos(y-2))/(pow(x,2)+pow(sin(y-2),2));
            arr[i][j]=a/b;
            
                   }
        
    }
    return arr;
};
double int_f()
{
     int x=rand(), y=rand();
        int a=(1-y)*pow(x+y,2)/pow((x+4,3)/exp(-(x-2))+(pow (x,3)+4));
        int b=(1+cos(y-2))/(pow(x,2)+pow(sin(y-2),2));
        return a/b;
}
int** int_matrix()
{
    int N=10;
    int** arr= new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i]=new int [N];
        for (int j = 0; j <N; j++)
    {
        int x=rand(), y=rand();
        int a=(1-y)*pow(x+y,2)/pow((x+4,3)/exp(-(x-2))+(pow (x,3)+4));
        int b=(1+cos(y-2))/(pow(x,2)+pow(sin(y-2),2));
            arr[i][j]=a/b;

    }

    double** sort_matrix(double** a, int rows=10, int cols=10)
    {
        for (int i = 0; i < rows; i++)
        {
           for (int j = 0; j <cols; i++)
           {
            for (int k=0; k < cols-j-1; k++)
            {
               if (a[i][k]<a[i][k+1]);
               {
               swap(a[i][k], a[i][k+1]);
               }
               
            }
            
           }
           
        }
        return a;
        
    }
return arr;
    }

    int* sum_array(int** a, int rows =10, int cols=10)
    {
        int  N=10;
        int* arr=new int[N];
        for (int i = 0; i < rows; i++)
        {
            int coll=rand()%10, col2,col3;
            do
            {
                int col2=rand()%10;
            } while (col2==col1);
            do
            {
              int col3=rand()%10;
            
            } while (col3==col1 || col3==col2);
            arr[i]=col1+col2+col3;
            rerutn arr;
            
        }
        bool writeToNewFile(constt int*arr, const string& fileName)
        {
            ofstream ouyputFile(fileName);
            if (!outputFile.is_open())
            {
                cerr<<"error opening file"<<endl;
                return false;
            }
            for (int i = 0; i < 10; i++)
            {
                outputFile<<arr[i]<<"  ";
            }
            outputFile.close();
            cout<<"good"<<endl;
            return true;

            
        }
        
    }
    int main()
    {
        const int pull_request_n=876;
        if ( pull_request_n%2==0)
        {

            double** matrix=double_matrix();
            matrix=sort_matrix(matrix);


        }
        else{
            int** matrix = int_matrix();
            matrix=sort_matrix(matrix);

           

        }
        return 0;
        

    }
    
    
    

}






const int CONSTANT_VALUE = 876;

// Функція для створення та заповнення матриці розміром 10x10 значеннями з певної математичної функції
void createMatrix(float matrix[10][10]) {
    // Функція, яка генерує значення для матриці на основі константи та індексів
    auto mathematicalFunction = [](int i, int j) -> float {
        return static_cast<float>(CONSTANT_VALUE * (i + 1) / (j + 1)); // Приклад математичної функції
    };

    // Заповнення матриці значеннями з використанням математичної функції
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = mathematicalFunction(i, j);
        }
    }
}

// Функція сортування стовпців матриці з числами з плаваючою крапкою
void sortColumns(float matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    float temp = matrix[k][i];
                    matrix[k][i] = matrix[k + 1][i];
                    matrix[k + 1][i] = temp;
                }
            }
        }
    }
}

// Функція сортування рядків матриці з цілими числами
void sortRows(int matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 10 - j - 1; ++k) {
                if (matrix[i][k] < matrix[i][k + 1]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

// Перша перевантажена функція для обробки матриці з числами з плаваючою крапкою та додатковим параметром
void manipulateMatrix(float matrix[10][10], float floatValue) {
    sortColumns(matrix);
    std::cout << "Sorted matrix by columns:" << std::endl;
    // Вивід відсортованої матриці з числами з плаваючою крапкою
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << std::fixed << std::setprecision(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Друга перевантажена функція для обробки матриці з цілими числами та додатковим параметром
void manipulateMatrix(int matrix[10][10], int intValue) {
    sortRows(matrix);
    std::cout << "Sorted matrix by rows:" << std::endl;
    // Вивід відсортованої матриці з цілими числами
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    float floatMatrix[10][10];
    createMatrix(floatMatrix); // Виклик функції для створення та заповнення матриці з числами з плаваючою крапкою

    int intMatrix[10][10];
    // Введення числа з плаваючою крапкою з консолі
    float floatValueFromConsole;
    std::cout << "Enter a floating point value from console: ";
    std::cin >> floatValueFromConsole;

    float product = CONSTANT_VALUE * floatValueFromConsole; // Обчислення добутку значення з консолі та константи

    // Виклик першої функції для обробки матриці з числами з плаваючою крапкою
    manipulateMatrix(floatMatrix, product);

    // Виклик другої функції для обробки матриці з цілими числами
    manipulateMatrix(intMatrix, CONSTANT_VALUE);

    return 0;
}


