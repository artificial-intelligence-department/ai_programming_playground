#ifndef book_h
#define book_h

#include <string>
#include <utility>
using std::string;

class Book {
private:
    string name;
    bool isAvailable;

public:
    explicit Book(string name = "", bool isAvailable = true) {
        this->name = std::move(name);
        this->isAvailable = isAvailable;
    }

    string getName() const;
    void setName(string Name);

    bool getIsAvailable() const;
    void setIsAvailable(bool IsAvailable);

    string toString() const;
};


#endif //book_h
