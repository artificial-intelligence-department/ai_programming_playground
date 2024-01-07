#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
  std::string s;
  std::cout << "Введіть строку: ";
  std::getline(std::cin, s);

  std::vector<std::string> words;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] != ' ') {
      std::string word = "";
      while (i < s.length() && s[i] != ' ') {
        word += s[i];
        i++;
      }
      words.push_back(word);
    }
  }

  std::map<std::string, int> word_counts;
  for (const std::string &word : words) {
    word_counts[word]++;
  }

  int max_count = 0;
  std::string most_common_word;
  for (const auto &pair : word_counts) {
    if (pair.second > max_count) {
      max_count = pair.second;
      most_common_word = pair.first;
    }
  }

  std::cout << "Найчастіше зустрічається слово: " << most_common_word << std::endl;
  return 0;
}