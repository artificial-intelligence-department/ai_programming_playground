#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, b, a;
    char command;
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984", "To hell and back", "The Godfather"};
    vector<bool> availability(books.size(), true);
    invalid_input:
    cout << "Щоб порахувати кількість книг, введіть 'c'\n";
    cout << "Щоб взяти книгу, введіть 't'\n";
    cout << "Щоб повернути книгу, введіть 'r'" << endl;
    cout << "Щоб вийти, введіть 'x'\n";
    do {
        cout << "Список книг:\n";
        for (int s=0; s<1; s++)
        {
            for (int i=0; i<6; i++)
            {
                cout<< i+1 << ") "<< books[i];
                if (availability[i]) 
                {
                    cout << " " << "Доступно" << endl;
                }
                else
                {
                    cout << " " << "Не доступно" << endl;
                }
            }
            break;
        }
    cout << "Введіть команду\n";
    cin >> command;
    if(command!='c' && command!='t' && command!='r' && command!='x')
    {
        cout << "Неправильна команда\n"<< endl;
        goto invalid_input;
    }
        switch (command)
        {
            case 'c':
                {
                    int n = 0;
                for (int k = 0; k < 6; k++)
                {
                    if (availability[k])
                    {
                        n++;
                    }
                }
                    cout << "Книг у наявності: ";
                    cout << n << "\n"<< endl;
                    break;
                }
            case 't':
                {
                    cout << "Ведіть номер книги\n";
                    cin >> a;
                    if (availability[a-1])
                    {
                        cout << "Книгу " << books[a-1] << " надано\n" << endl;
                        availability[a-1]=false;
                    }
                    else
                    {
                        cout << "Книги немає в доступі\n"<< endl;
                    }
                        break;
                }
            case 'r':
                {
                    int s;
                    cout << "Ведіть номер книги\n";
                    cin >> s;
                    if (!availability[s-1])
                    {
                        availability[s-1]=true;
                        cout << "Книгу " << books[s-1] << " взято, дякуємо\n" << endl;
                    }
                    else
                    {
                        cout << "Книга вже є\n" << endl;
                    }
                    break;
                    
                }
               
        }
    }
    while(command!='x');
    
    return 0;
}