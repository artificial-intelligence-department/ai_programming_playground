#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

// Функція для перетворення рядка у нижній регістр
std::string to_lower(std::string str) 
{
    for (char& c : str)
    {
        c = tolower(c);
    }
    return str;
}

int main() 
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> words(n);

    // Перший елемент пари - слово
    // Другий елемент пари - кількість входжень слова
    std::map<std::string, int> words_count;

    // Неупорядкована множина для унікальних символів
    std::unordered_set<char> charset;

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> words[i];
        // Нормалізуємо слово (верхній регістр)
        words[i] = to_lower(words[i]);
        words_count[words[i]]++;
    }

    // Проходимося по словах та додаємо символи унікальних слів в множину
    for (const auto& pair : words_count)
    {
        if (pair.second >= k)
        {
            for (char c : pair.first)
            {
                charset.insert(c);
            }
        }
    }
    // Перетворюємо множину вектор та сортуємо в зворотньому порядку
    std::vector<char> chars(charset.begin(), charset.end());
    std::sort(chars.begin(), chars.end());
    std::reverse(chars.begin(), chars.end());

    if (chars.empty()) 
    {
        std::cout << "Empty!";
        return 0;
    }

    std::cout << chars.size() << std::endl;
    // Виводимо унікальні символи
    for (char c : chars)
    {
        std::cout << c << " ";
    }

    return 0;
}
