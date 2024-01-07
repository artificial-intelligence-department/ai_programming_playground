#include <iostream>
#include <cmath>
#include <fstream>
#include<vector>
using namespace std;


double matrix_a(double matrix[10][10])
{

    for(int x = 10;x <= 100; x+=10 ) {
        for (int a = 10, b = 10; a <= 100 && b <= 100; a+=10, b+=10) {

            double result = pow(b, 3) * pow(tan(x), 2) - (a / pow(sin(x / a), 2));
            matrix[x%10][a%10] = result;
        }

    }
    return matrix[10][10];
}
int matrix_a(int matrix[10][10])
{

    for(int x = 10;x <= 100; x+=10) {
        for (int a = 10, b = 10; a <= 100 && b <= 100; a+=10, b+=10) {

            int result = pow(b, 3) * pow(tan(x), 2) - (a / pow(sin(x / a), 2));
            matrix[x%10][a%10] = result;
        }

    }
    return matrix[10][10];
}
void print_arr(double arr[10][10])
{
    for(int x = 0;x < 10; x++ ) {
        for (int a = 0; a < 10 ; a++) {
            cout << arr[x][a]<<' ';
        }
        cout<<endl;
}
}
void print_arr(int arr[10][10])
{
    for(int x = 0;x < 10; x++ ) {
        for (int a = 0; a < 10 ; a++) {
            cout << arr[x][a]<<' ';
        }
        cout<<endl;
    }
}
void print_arr_o(int arr[10])
{
    for(int x = 0;x < 10; x++ ) {

            cout << arr[x]<<' ';

        cout<<endl;
    }
}
double sort(double matrix[10][10], double num)
{

    for (int x = 0; x < 10; x++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[j][i] > matrix[j + 1][i]) {

                    double buff = matrix[j][i];
                    matrix[j][i] = matrix[j + 1][i];
                    matrix[j + 1][i] = buff;
                }
            }
        }
    }
    return matrix[10][10];
}
int sort(int matrix[10][10], int num)
{
    for (int x = 0; x < 10; x++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (matrix[i][j] < matrix[i][j + 1]) {
                    // Swap elements if they are in the wrong order
                    int buff = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = buff;
                }
            }
        }
    }
    return matrix[10][10];
}
void write( int number)
{
    ofstream file;
    file.open("output.txt",ios_base::app);
    if (!file){

        cout<< "Failure" ;
        return;

    }
    file << number<<"; ";

    file.close();
}
void sum(double matrix[10][10])
{
    double sum = 0;
    int sum_arr[10];
    for (int x = 0; x < 10; x++) {
        for (int i = 0; i < 4; i++)
        {
            int index = rand() % 10;
            sum += matrix[x][index];
        }
        int sum_i = sum;
        if(sum - sum_i == 0)
        {
            sum_arr[x] = sum;
            write(sum);
        }
    }
    cout<<"\nSum: ";
    print_arr_o(sum_arr);


}
void deleteAllData(string path){
    ofstream file(path, ios::trunc);
    file.close();
}
vector<string> parse(string text)
{
    vector<string> data;
    string buff;
    for(int i = 0 ;i < text.size(); i++)
    {
        bool is_separator_found = false;
        if (text[i] == ';')
        {
            is_separator_found = true;
        }

    if (is_separator_found)
    {
        data.push_back(buff);
        buff = "";
    }
    else
    {
        if (text[i]!=' ')
        {
            buff += text[i];
        }

    }
    }
    return data;
}

string read(string path)
{
    string output;
    string line;
    ifstream file;
    file.open(path, ios_base::app);
    if (!file){

        return "Failure" ;

    }
    while(getline(file , line))
    {
        output += line;
        cout<< line<<"\n";
    }

    file.close();
    return output;
}
int main() {
    const int number_pr = 798;
    if (number_pr % 2 == 0)
    {
        double matrix[10][10];
        matrix_a(matrix);
        print_arr(matrix);
        (sum(matrix));
        sort(matrix,0.3);
        cout << "\nSorted matrix: ";
        print_arr(matrix);
        deleteAllData("output.txt");

    }
    else
    {
        int matrix[10][10];
        matrix_a(matrix);
        print_arr(matrix);
        sort(matrix,1);
        cout << "\nSorted matrix: ";
        print_arr(matrix);
    }

}