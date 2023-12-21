#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void prost(vector<vector<int>> parameters)
{   
    bool isProst=true;
    for (int r = 0; r < parameters.size(); r++)
        {
            vector<int> parameter = parameters[r];
            
                
                    for (int n = parameter[0]; n <= parameter[1]; n++)
                        {   
                            for (int i=2; i <= sqrt(n); i++)
                                {
                                    if (n%i==0)
                                        { 
                                            isProst=false;
                                            break;
                                        }
                                }
                            if(isProst==true)
                            cout << n << "\t";
                            else
                            isProst=true;
                        }
        }
    cout << "\n";

}
int main()
{   
    prost({{1, 10}, {16, 22}, {23, 32}});
    prost({{1, 10}, {16, 22}, {23, 32}, {50, 60}, {70, 80}});
    prost({{1, 10}, {16, 22}, {23, 32}, {50, 60}, {70, 80}, {90, 98} });
    return 0;
}