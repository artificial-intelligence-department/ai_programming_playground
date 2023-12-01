#include <iostream>
#include <cmath>
    using namespace std;

        int main(){  

            
            double a, b, c, d, e, f;
            a = 1000.0;
            b = 0.0001;
            
            // Виражаю покрокові дії через змінні c, d, e, f.
            // Рядок коду нижче, є індентичним виразу: (a-b)^2(a^2-2ab)/b^2
            
            c = pow((a-b),2);
            d = pow(a,2);
            e = 2*a*b;
            f = pow(b,2);

            cout << "Відповідь: " << (c-(d-e))/f;



            return 0;
        }