 #include <iostream>
using namespace std;

int main() {
    int rowNum, columnNum;
    cout << "Enter the amount of rows: ";
    cin >> rowNum;
    cout << "\nEnter the amount of columns: ";
    cin >> columnNum;

    int matrix[rowNum][columnNum];
   
    for (int i = 0; i<rowNum; ++i) {
        for (int j = 0; j<columnNum; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i<rowNum; ++i) {
        for (int j = 0; j<columnNum; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i=0; i<rowNum; ++i){
        for (int j=0; j<columnNum; ++j) {
            int interim = matrix[i][j];
            int maxRow = interim;
            int minColumn = interim;
            
            for(int a=0; a<columnNum; ++a) {
                if(matrix[i][a]>maxRow) {
                    maxRow = matrix[i][a];
                }
            }

            for(int b=0; b<rowNum; ++b) {
                if(matrix[b][j]<minColumn) {
                    minColumn = matrix[b][j];
                }
            }

            if(maxRow == interim && minColumn == interim) {
                cout << "Saddle point: " << "(" << i << ", " << j << ")" << endl;
            }
        }
    }

    for (int i=0; i<rowNum; ++i){
        for (int j=0; j<columnNum; ++j) {
            int interim = matrix[i][j];
            int minRow = interim;
            int maxColumn = interim;
            
            for(int a=0; a<columnNum; ++a) {
                if(matrix[i][a]<minRow) {
                    minRow = matrix[i][a];
                }
            }

            for(int b=0; b<rowNum; ++b) {
                if(matrix[b][j]>maxColumn) {
                    maxColumn = matrix[b][j];
                }
            }

            if(minRow == interim && maxColumn == interim) {
                cout << "Saddle point: " << "(" << i << ", " << j << ")" << endl;
            }
        }
    } 

    return 0; 
}