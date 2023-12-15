#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* information) {
    ofstream file(name);

    if (!file.is_open()) {
        return Failure;
    }

    file << information << endl;

    if (file.fail()) {
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    const char* file = "test.txt";
    char information[50];

    cout << "Enter information to write to the file: ";
    cin.getline(information, sizeof(information));

    FileOpResult result = write_to_file(file, information);

    if (result == Success)
        cout << "Success." << endl;
    else
        cout << "Failure." << endl;


    return 0;
}

//#include <iostream> 
//#include <fstream> 
//using namespace std;
//
//enum FileOpResult { Success, Failure };
//
//FileOpResult write_to_file(char* name, char* content) {
//	ofstream file(name);
//
//	if (!file.is_open()) {
//		return Failure;
//	}
//	else
//	{
//		file << content;
//		file.close();
//		return Success;
//	}
//}
//
//FileOpResult copy_file(const char* f1, const char* f2) {
//
//	ifstream file1 (f1, ios::binary);
//	ofstream file2(f2, ios::binary);
//
//	if (!file1.is_open() || !file2.is_open()) {
//
//		return Failure;
//
//	}
//	file2 << file1.rdbuf();//вказівник на буфер потоку
//
//	if (file2.fail()) {
//		file1.close();
//		file2.close();
//		return Failure;
//
//	}
//	file1.close();
//	file2.close();
//
//	return Success;
//
//}
//
//int main() {
//
//	const char* source = "f1.txt";
//	const char* destination = "f2.txt";
//
//	FileOpResult result = copy_file(source, destination);
//
//	if (result == Success) 
//		cout << "Success" << endl;
//	else 
//		cout << "Failure" << endl;
//
//	return 0;
//
//}

