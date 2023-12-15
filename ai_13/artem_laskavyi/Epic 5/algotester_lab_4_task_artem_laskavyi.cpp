#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector( vector<int> vect ){
   for( int i = 0; i < vect.size() ; i++ ){
      cout << vect[i] << " ";
   }
   cout << endl;
}

int main(){ 

   int N, M, num;
   vector<int> a, b, diffNM, diffMN, intersec, uni, symdiff;
   vector<int>::iterator it;

   cin >> N;
   for (int i=0; i<N; i++){ 
   cin >> num;
   a.push_back(num);
   }

   cin >> M;
   for (int i=0; i<M; i++){ 
   cin >> num;
   b.push_back(num);
   }

   sort(a.begin(), a.end());
   sort(b.begin(), b.end());

   set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersec));
   set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(uni));
   set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(symdiff));

   for(int i = 0; i  < a.size(); i++ ){
      diffNM.push_back(a[i]);
   }

   for(int i = 0; i  < intersec.size(); i++ ){
      auto it = find(diffNM.begin(), diffNM.end(), intersec[i]);
      if (it != a.end()){
         diffNM.erase(it);
      }
   }

   for(int i = 0; i  < b.size(); i++ ){
      diffMN.push_back(b[i]);
   }

   for(int i = 0; i  < intersec.size(); i++ ){
      auto it = find(diffMN.begin(), diffMN.end(), intersec[i]);
      if (it != b.end()){
         diffMN.erase(it);
      }
   }

    cout << diffNM.size() << endl;
    printVector(diffNM);

    cout << diffMN.size() << endl;
    printVector(diffMN);

    cout << intersec.size() << endl;
    printVector(intersec);

    cout << uni.size() << endl;
    printVector(uni);

    cout << symdiff.size() << endl;
    printVector(symdiff);

   return 0;
   }
