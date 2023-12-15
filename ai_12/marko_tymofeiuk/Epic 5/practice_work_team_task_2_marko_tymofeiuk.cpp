#include <iostream>
#include <fstream>

enum FileOpResult{Success, Failure};

FileOpResult copy_file (const char *file_from, const char *file_to){
    std::ifstream inputFile(file_from);
    std::ofstream outputFile(file_to);

    if (!inputFile.is_open()){
        std::cerr << "Error opening source file: " << file_from << std::endl;
        return Failure;
    }

    if (!outputFile.is_open()){
        std::cerr << "Error opening destination file: " << file_to << std::endl;
        return Failure;
    }

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();
    return Success;
}

int main(){
    char input[512], output[512];
    std::cout << "Enter the name of the file you want to copy from: ";
    std::cin.getline(input, sizeof(input));
    std::cout << "Enter the name of the file you want to copy to: ";
    std::cin.getline(output, sizeof(output));

    FileOpResult result = copy_file(input, output);

    if (result == Success){
        std::cout << "File was copied successfully.";
    } else {
        std::cout << "File copy failed. Sorry.";
    }

    return 0;
}