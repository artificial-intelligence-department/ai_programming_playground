#include <iostream>
#include <string>
using namespace std;

int main()
{
   string weather;

   cout << "What is the weather like today" << endl;
   cin >> weather;
   
   switch (weather[0])
   {
   case 's':
      if (weather == "sunny")
      {
         cout << "Wear your favorite sneakers!" << endl;
      }
      else if (weather == "snowy")
      {
         cout << "Snow boots will keep your feet warm!" << endl;
      }
      break;

   case 'r':
      cout << "Rain boots are a good idea!" << endl;
      break;
   case 'w':
      cout << "Wear something sturdy!" << endl;
      break;
   case 'c':
      cout << "Today, any shoe is suitable." << endl;
      break;

   default:
      cout << "Enter the right word" << endl;
      return 0;
   }

   if (weather == "snowy" || weather == "rainy")
   {
      cout << "You need to wear a coat today" << endl;
   }
   else
   {
      cout << "It is warm outside, you don't need a coat" << endl;
   }

   if (weather == "sunny")
   {
      cout << "It's a wonderful day for a picnic" << endl;
   }
   else if (weather == "rainy")
   {
      cout << "Perfect weather to read a book inside!" << endl;
   }
   else if (weather == "cloudy")
   {
      cout << "Maybe visit a museum?" << endl;
   }
   else if (weather == "snowy")
   {
      cout << "How about making a snowman?" << endl;
   }
   else if (weather == "windy")
   {
      cout << "Fly a kite if you have one!" << endl;
   }

   return 0;
}