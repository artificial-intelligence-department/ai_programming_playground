#include <utility>
#include "book.h"

string Book::getName() const {
    return this->name;
}
void Book::setName(string Name) {
    this->name = std::move(Name);
}

bool Book::getIsAvailable() const {
    return this->isAvailable;
}
void Book::setIsAvailable(bool IsAvailable) {
    this->isAvailable = IsAvailable;
}

string Book::toString() const {
    return this->name + " (" +
           (isAvailable ? "Available" : "Unavailable")
           + ")";
}
