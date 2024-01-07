#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M, number_n, number_m;
    vector <int> n;
    vector <int> m;

    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> number_n;
        n.push_back(number_n);
    }

    cin >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> number_m;
        m.push_back(number_m);
    }

    sort(n.begin(), n.end());
    sort(m.begin(), m.end());

    vector <int> difference1;
    vector <int> m_copy = m;

    for(int i = 0; i < n.size(); i++)
    {
        bool is = true;
        
        for(int j = 0; j < m_copy.size(); j++)
        {
            if(n[i] == m_copy[j])
            {
                m_copy[j] = -1;
                is = false;
                break;
            }
        }
        
        if(is)
        {
            difference1.push_back(n[i]);
        }
    }

    cout << difference1.size() << endl;
    
    for(int i = 0; i < difference1.size(); i++)
    {
        cout << difference1[i] << " ";
    }
    
    cout << endl << "\n";

    vector <int> difference2;
    vector <int> n_copy = n;

    for(int i = 0; i < m.size(); i++)
    {
        bool is = true;
        for(int j = 0; j < n_copy.size(); j++)
        {
            if(m[i] == n_copy[j])
            {
                n_copy[j] = -1;
                is = false;
                break;
            }
        }
        if(is)
        {
            difference2.push_back(m[i]);
        }
    }

    cout << difference2.size() << endl;
    
    for(int i = 0; i < difference2.size(); i++)
    {
        cout << difference2[i] << " ";
    }
    
    cout << endl << "\n";

    vector <int> crossing;

    for(int i = 0; i < n.size(); i++)
    {
        if(n_copy[i] == -1)
        {
            crossing.push_back(n[i]);
        }
    }

    cout << crossing.size() << endl;
    
    for(int i = 0; i < crossing.size(); i++)
    {
        cout << crossing[i] << " ";
    }
    
    cout << endl << "\n";

    vector <int> unification;

    for(int i = 0; i < difference1.size(); i++)
    {
        unification.push_back(difference1[i]);
    }

    for(int i = 0; i < difference2.size(); i++)
    {
        unification.push_back(difference2[i]);
    }

    for(int i = 0; i < crossing.size(); i++)
    {
        unification.push_back(crossing[i]);
    }

    sort(unification.begin(), unification.end());

    cout << unification.size() << endl;
    
    for(int i = 0; i < unification.size(); i++)
    {
        cout << unification[i] << " ";
    }
    
    cout << endl << "\n";

    vector <int> symmetric;

    for(int i = 0; i < difference1.size(); i++)
    {
        symmetric.push_back(difference1[i]);
    }

    for(int i = 0; i < difference2.size(); i++)
    {
        symmetric.push_back(difference2[i]);
    }

    sort(symmetric.begin(), symmetric.end());

    cout << symmetric.size() << endl;
    
    for(int i = 0; i < symmetric.size(); i++)
    {
        cout << symmetric[i] << " ";
    }
    
    cout << endl << "\n";

    return 0;
}
