#include <iostream>
#include <vector>
using namespace std;

    int jlength{0};
    int klength{0};

int displayArr ( int *arr) {



     for (int j = 0; j < jlength; j++)
    {   cout<< "{";
        for (int k = 0; k < klength; k++)
        {
            
            cout<<" "<<*(arr + j * klength + k);
        }
        cout <<"}"<<endl;
        
        
    }
    


}

    

int findMin (vector<int>& uniqAr){
    int min{0};
    
    
      
    for (vector<int>::iterator it = uniqAr.begin(); it != uniqAr.end(); it++)
    {
        if (it==uniqAr.begin())
        {
            min=*it;
        }else if(*it <min){
            min=*it;
        }
        
    }
    cout<< min<<endl;
    
    

}
    

    vector<int> findUnique (int *arr) {
        vector<int> uniqAr;
        

        for (int j = 0; j < jlength; j++)
    {   
        for (int k = 0; k < klength; k++)
        {
            int curr = *(arr + j * klength + k);
            bool isUnique = true; 
            for (int i = 0; i < jlength*klength; i++)
            {
                if(i== j * klength + k)
                    {
                        continue;
                    }
                   if(curr == *(arr + i) )
                   {

                    isUnique=false;
                    break;
                    
                    }
                
            }
            if(isUnique)
                {
                    
                    uniqAr.push_back(curr);
                  
                }
            
        }
       

        
        
        
        
    }
    findMin(uniqAr);
    
    return uniqAr;
    }

    
    



int main(int argc, char const *argv[])
{
    
    cout<< "Size of 2d array:";
    cin>> jlength;
    cin>> klength;

    int array[jlength * klength];
    for (size_t j = 0; j < jlength; j++)
    {
        cout<< "enter "<<j+1 <<" array";
        for (size_t k = 0; k < klength; k++)
        {
            
            cin >> *(array + j * klength + k);
        }
        cout<<endl;
        
    }
    cout<<endl;
   
    displayArr(array);
    findUnique(array);


    return 0;
}
