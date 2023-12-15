#include <iostream>
#include <vector>
#include <string>
using namespace std;
void pArray(vector <string> books){
  for(int i = 0; i<books.size(); i++){
    cout<<books[i]<<endl;
  }
}
int main(){
  vector <string> books = {"Dead Inside","Kaneki Ken 993", "Dota 2 Guide", "Oksana The Best"};
  vector <bool> available = {true, true, true};
  int choice;
  string bookName;

  menu:
  cout << "Library Management\n";
  cout << "1. List all books\n";
  cout << "2. Borrow a book\n";
  cout << "3. Return a book\n";
  cout << "4. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  switch(choice) {
    case 1: 
    pArray(books);
    break;
    case 2:
    cin.ignore(); //used to ignore or clear one or more characters from the input buffer
    cout << "Enter book name to borrow: "; 
    getline(cin, bookName);
    for (int i2 = 0; i2<books.size(); i2++) {
      if (books[i2] == bookName) {
        if (available[i2]) {
          available[i2] = false;
          cout << "Book borrowed successfully!\n";
          break;
        } 
        else {
          cout << "Book is already borrowed.\n";
          break;
        }
      }
    }
    break;
  case 3:
  cin.ignore(); //used to ignore or clear one or more characters from the input buffer
  cout << "Enter book name to return: ";
  getline(cin, bookName);
  for (int i3 = 0; i3<books.size(); i3++) {
      if (books[i3] == bookName) {
        if (!available[i3]) {
          available[i3] = true;
          cout << "Book returned successfully!\n";
          break;
        } 
        else {
          cout << "Book wasn't borrowed.\n";
          break;
        }
      }
    }
    break;
  case 4:
  cout << "Goodbye!";
  return 0;
  default:
  cout << "Invalid choice.\n";
  goto menu;
}


char secondChoice;
    do {
        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> secondChoice;
    } while (secondChoice!= 'Y' && secondChoice != 'N' && secondChoice != 'y' && secondChoice != 'n');
    
    if (secondChoice == 'Y' || secondChoice == 'y') {
        goto menu;
    } else {
        std::cout << "Goodbye!";
    }



}