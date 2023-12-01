#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
 vector <string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
 vector <bool> available={true,true,true,true};
 string bookName;
 int choice;
 
 do{
 
 cout<<"What do you want? \n"<<"1.List all books\n"<<"2.Take a book\n"<<"3.Return a book\n"<<"4.Exit\n"<<"Chose one option below :";
 cin>>choice;
 switch(choice){
   case 1: { 
       
       cout<<"List of all books:\n";
       for( string &book:books){
         int bookIndex=&book-&books[0];
         cout<<book<<" ("<<(available[bookIndex]?"Available:))\n":"Not available :()\n");
    } 
    break;}
    
   case 2:{
    cin.ignore();
    cout<<"Please enter the name of book you want to take:\n";
    getline(cin,bookName);
   

   for (int i = 0; i < books.size(); ++i) {
      if (bookName == books[i]) {
          if (available[i]) {
              available[i] = false;
              cout << "Enjoy reading " << books[i] << "!\n";}
          else {cout << "Sorry, this book is not available.\n";}
      break; }

      else if (i == books.size() - 1){cout << "Book not found in the library. Try again.\n";
              }
      }
      break;}
      
   case 3:{
   cout<<"Please enter the name of book you want to return\n";
   cin.ignore();
   getline(cin,bookName);
   

   for (int i = 0; i < books.size(); ++i) {
      if (bookName == books[i]) {
          if(!available[i]){
              available[i]=true;
              cout<<"Book returned successfully\n";} 
          else{cout<<"Seems like book is already available";}
      break;}
      else if(i==books.size()-1){ cout<<bookName<<" is not in the library. Or you put incorrect name.\n";
       }
       
       }
       break;}
   
   case 4:{
      cout<<"Exiting a library. Bye!\n";
      return 0;}
   default:{
  cout<<"Invalid choice. Go back to menu\n"; 
 }
 }
 }while(choice!=4);
    return 0;
}