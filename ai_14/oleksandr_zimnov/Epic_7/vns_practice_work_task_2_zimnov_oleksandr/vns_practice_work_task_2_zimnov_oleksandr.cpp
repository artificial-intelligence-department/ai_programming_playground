#include <iostream> 
#include <fstream>
#include <cmath> 
#include <string>

using namespace std; 
void writeToFile(const string& filename, const float& content, int temp) { //19. в коді використано функції роботи з файлами, для того, щоб записати у файл
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "x["<<temp<<"] is: "<<content<<endl;
    } else {
        cout << "Error" << endl;
    }
    file.close();
}

void readFromFile(const string& filename) { //20. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    ifstream file(filename);
    string content;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        cout<<content;
    } else {
        cout << "Error" << endl;
    }

    file.close();
}

int main() {
    float y=0, xi[10]; 
    int x=3, temp=0;
    string filename = "file.txt";
    while(temp<10){ //9. в коді використаний while цикл
        temp++; 
        xi[temp-1]=(pow(x,temp))/temp; //6. в коді використаний одновимірний масив
        writeToFile(filename, xi[temp-1], temp); 
        y+=xi[temp-1];
    }
    readFromFile(filename);
    cout<<"Sum of each function y="<<y;
}
