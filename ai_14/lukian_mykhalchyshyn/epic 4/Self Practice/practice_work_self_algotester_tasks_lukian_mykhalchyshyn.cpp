#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    string message;

    cout << "Введіть кількість входжень\n";
    cin >> k;
    
    cout << "Введіть повідомлення\n";
    cin >> message;

    int amount = 0;  // кількість знайдених входжень 
    size_t found = 0; // знаходження позиції TOILET
     
       while ((found = message.find("TOILET")) != string::npos) //умова перевірки чи знайшовся TOILET
       {                                                        
            amount++;
            message = message.substr(found + 6); //стирання всіх символів після першого TOILET   
       }

    if (amount >= k)
    {
        cout << "YES\n";
    }
    else
    { 
        cout << "NO\n";
    }
    
    return 0;
}