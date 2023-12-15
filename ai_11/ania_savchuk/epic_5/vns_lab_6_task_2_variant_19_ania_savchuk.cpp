#include <iostream>
#include <stdio.h>
#include <string.h>
using  namespace std;

bool identificator(string word){
    // Перевірка, чи ідентифікатор не є ключовим словом
    const string keywords[96] = {
        "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit", "atomic_noexcept", "auto", "bitand", "bitor", 
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", 
        "constexpr", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", 
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "import", 
        "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", 
        "protected", "public", "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert", 
        "static_cast", "struct", "switch", "synchronized", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", 
        "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };

    for (int i = 0; i < 96; i++){
        if(word == keywords[i]){
            return false;
        }
    }

    //Перевірка чи індентифікатор починається з букви 
    if(!((word[0] >= 'a' && word[0] <='z') || (word[0] >= 'A' && word[0] <='Z') || word[0] == '_')){
        return false;
    }
  
    return true;
}

void remove(char str[]){
    char new_string[255];
    int current_position = 0; 
    char *token;
    token = strtok(str, " ");
    while(token != nullptr){
        if (identificator(token)) {
            int len = strlen(token);

            for (int i = 0; i < len; i++) {
                new_string[current_position++] = token[i];
            }
            new_string[current_position++] = ' ';
        }
        token = strtok(nullptr, " ");

    }

    for(int i = 0; i < strlen(new_string); i++) {
        str[i] = new_string[i];
    }
    str[current_position] = '\0';
}

int main(){
    char input[255];

    cout << "Enter a string: ";
    cin.getline(input, sizeof(input));

    remove(input);

    cout << "Modified string: " << input << endl;
    return 0; 
}