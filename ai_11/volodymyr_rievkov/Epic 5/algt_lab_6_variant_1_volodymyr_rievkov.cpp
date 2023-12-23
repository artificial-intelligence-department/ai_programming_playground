#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int border_1 = 1;
const int border_2 = 10e5;

bool check_number(int number, int lower_bound, int upper_bound)
{
    return (number >= lower_bound && number <= upper_bound);
}

void process_input(vector<string>& all_words_vector, vector<int>& word_count_vector, int N, int K)
{
    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;

        for (int j = 0; j < word.size(); ++j)
        {
            word[j] = tolower(word[j]);
        }

        int index = -1;
        for (int j = 0; j < all_words_vector.size(); ++j)
        {
            if (all_words_vector[j] == word)
            {
                index = j;
                break;
            }
        }

        if (index != -1)
        {
            word_count_vector[index]++;
        }
        else
        {
            all_words_vector.push_back(word);
            word_count_vector.push_back(1);
        }
    }
}

void print_sorted_result(const vector<string>& all_words_vector, const vector<int>& word_count_vector, int K)
{
    vector<char> sorted_chars;
    for (int i = 0; i < all_words_vector.size(); ++i)
    {
        if (word_count_vector[i] >= K)
        {
            for (int j = 0; j < all_words_vector[i].size(); ++j)
            {
                sorted_chars.push_back(all_words_vector[i][j]);
            }
        }
    }

    sort(sorted_chars.begin(), sorted_chars.end());
    sorted_chars.erase(unique(sorted_chars.begin(), sorted_chars.end()), sorted_chars.end());
    reverse(sorted_chars.begin(), sorted_chars.end());

    if (!sorted_chars.empty())
    {
        cout << sorted_chars.size() << endl;

        for (int i = 0; i < sorted_chars.size(); ++i)
        {
            cout << sorted_chars[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Empty!" << endl;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    if (!check_number(N, border_1, border_2) || !check_number(K, border_1, N))
    {
        return 0;
    }

    vector<string> all_words_vector;
    vector<int> word_count_vector;

    process_input(all_words_vector, word_count_vector, N, K);
    print_sorted_result(all_words_vector, word_count_vector, K);
}