#include <iostream>
#include <fstream>

enum FileOpResult {Success, Failure};

FileOpResult write_to_file (const char *name, char *content){
    std::ofstream outputFile(name);

    if(!outputFile.is_open()){
        std::cerr << "Error opening file: " << name << std::endl;
        return Failure;
    }

    outputFile << content;
    outputFile.close();
    return Success;
}

int main(){
    char content[1024];
    const char *name = "testfile.txt";
    std::cout << "Enter the content of the file:" << std::endl;
    std::cin.getline(content, sizeof(content));
    FileOpResult result = write_to_file(name, content);

    if (result == Success){
        std::cout << "File was written successfully.";
    } else {
        std::cout << "File write failed. Sorry.";
    }

    return 0;
}
