#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(char *file_from, char *file_to) {
    ifstream src(file_from, ios::binary); // Відкривання вихідного файлу
    ofstream dst(file_to, ios::binary); // Відкривання цільового файлу
    if (!src.is_open() || !dst.is_open()) {
        return Failure;
    }
    dst << src.rdbuf(); // Копіювання вмісту вихідного файлу у цільовий файл
    if (src.bad() || dst.bad()) {
        return Failure;
    }
    return Success;
}