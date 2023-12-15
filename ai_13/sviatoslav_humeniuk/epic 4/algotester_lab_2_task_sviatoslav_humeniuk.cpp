//Мінімальна втома
#include <iostream>
#include <vector>
#include <sstream> // Для роботи з строками
#include <algorithm> // Для конвертації рядків у числові значення

using namespace std;

int main() {
    vector<long long> vec; 
    long long n, v, mindif, rem;

    do {
        cin >> n;
    } while (n < 1 || n > 100000);
    
    
    string input;
    getline(cin, input);  

    getline(cin, input);
    istringstream iss(input); // Перетворюємо введену строку на числове значення
    

    for (int i = 0; i < n; i++) {
        if (iss >> v) {
            if (v > 100000) {
                return 1;
            }
            vec.push_back(v);  
        }
    }
    

    if (n>2) {
        for (int i = 0; i < vec.size(); i++) {
    
        long long removed = vec[i];
        vec.erase(vec.begin() + i);


        auto min = *min_element(vec.begin(), vec.end()); // Використовуємо auto для автоматичного визначення типу змінної
        auto max = *max_element(vec.begin(), vec.end());


        if (max - min < mindif) {
            mindif = max - min;
            rem = removed;
        }


        vec.insert(vec.begin() + i, removed);
    }


    vec.erase(remove(vec.begin(), vec.end(), rem), vec.end());

    cout << mindif << endl;

    }
    
    else if (n==2) {
    
        auto min = *min_element(vec.begin(), vec.end());
        auto max = max_element(vec.begin(), vec.end()); // Не використовуємо вказівник, оскільки пізніше повинні виконати операцію
        vec.erase(max);
        cout << min << endl;
    }

    else  {
        cout << 0;
    }

    return 0;
}