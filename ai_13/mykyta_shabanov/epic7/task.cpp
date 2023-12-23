#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int SumOfRow(int n, int i = 1, int result = 0)
{
    if(n > 1)
        return SumOfRow(n - 1, i + 2, result + i);

    return result + i;
}

int createMatrix(int index)
{
    int squareValue = index;// = SumOfRow(index);

    return squareValue;
}

void sortMatrix(int matrix[10][10], int input, int pr) //b task
{
    int varr = pr * input;
    //bubble sort
    for (int k = 0; k < 9; k++) //для всіх рядків
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9 - i; j++)
            {
                if (matrix[k][j] < matrix[k][j + 1]) //сортування по спаданню
                {
                    int temp = matrix[k][j + 1];
                    matrix[k][j + 1] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            } 
        }
    }
}

    //overload
void sortMatrix(float matrix[10][10], int input, int i) //a task
{
    //bubble sort
    for (int k = 0; k < 9; k++) //для всіх рядків
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9 - i; j++)
            {
                if (matrix[k][j] > matrix[k][j + 1]) //сортування по зростанню
                {
                    int temp = matrix[k][j + 1];
                    matrix[k][j + 1] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            } 
        }
    }
}

void createMetrixFromSum(int oldMatrix[10][10], int newMatrix[10])
{
    //тут без рандому, бо я 4-ий епік не зробив і не знаю як з ним працювати
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sum += oldMatrix[i][j];
        }

        newMatrix[i] = sum;
        sum = 0;  
    }
    
}

bool wrtieToFile(int matrix[10], string str)
{
    ofstream fout(str);
    for (int i = 0; i < 10; i++)
    {
        fout << matrix[i];
    }

    if(fout.is_open())
        return true;
    return false;
}

int readFromFile(string fileName)
{
    ifstream fin(fileName);

    string line;
    int dobutok;
    
    getline(fin, line);
    dobutok = stoi(line);

    while (getline(fin, line))
    {
        dobutok *= stoi(line);
    }

    return dobutok;
}


int main()
{
        //PR link: https://github.com/artificial-intelligence-department/ai_programming_playground/pull/919
    const int prIndex = 919;


    int matrix[10][10];
        //непарна, отже пункт b
        /*
        викликати функцію яка створить та поверне матрицю розміром 10*10
        і буде заповнена значеннями з певної математичної функції 
        і повертає цілі числа
        */
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[j][i] = createMatrix(i);
        }
    }

    float input;
    cout << "input useless data: ";
    //або значення пулл реквесту, або добуток значення пулл реквесту та числа з плаваючою крапкою, що вводиться з консолі
    cin >> input;
    sortMatrix(matrix, input, prIndex); // <- sort matrix


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matrix[i][j] << " ";//
        }
        cout << endl;
    }

    int newMatrix[10];
    createMetrixFromSum(matrix, newMatrix);

    cout << "NEW MATRIX> " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << newMatrix[i] << " ";
    }
    
    const string fileName = "newFile.dat";
    if (wrtieToFile(newMatrix, fileName))
    {
        cout << "info to file wrtie succesesful!" << endl;
    } else {
        cout << "Error while create file> " << endl;
    }


    cout << "dobutok is: " << readFromFile(fileName) << endl;
}