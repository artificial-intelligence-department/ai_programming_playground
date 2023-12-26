#include <iostream>
#include <vector>

void customQuickSort(std::vector<int>& numbers, int left, int right) {
    if (left < right) {
        int pivot = numbers[left];
        int i = left + 1;
        int j = right;

        while (i <= j) {
            while (i <= j && numbers[i] <= pivot) {
                i++;
            }

            while (i <= j && numbers[j] > pivot) {
                j--;
            }

            if (i < j) {
                std::swap(numbers[i], numbers[j]);
            }
        }

        std::swap(numbers[left], numbers[j]);

        customQuickSort(numbers, left, j - 1);
        customQuickSort(numbers, j + 1, right);
    }
}

void customSort(std::vector<int>& numbers) {
    customQuickSort(numbers, 0, numbers.size() - 1);
}

void reverseSort(std::vector<int>& numbers) {
    customQuickSort(numbers, 0, numbers.size() - 1);

    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
        std::swap(numbers[i], numbers[j]);
        i++;
        j--;
    }
}

void removeDuplicates(std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            if (numbers[i] == numbers[j]) {
                numbers.erase(numbers.begin() + j);
                --j;
            }
        }
    }
}

int main() {
    using namespace std;

    int N;
    cin >> N;

    vector<int> rem0, rem1, rem2;

    for (int i = 0; i < N; i++) {
        int currentElem;
        cin >> currentElem;

        if (currentElem % 3 == 0) {
            rem0.push_back(currentElem);
        } else if (currentElem % 3 == 1) {
            rem1.push_back(currentElem);
        } else {
            rem2.push_back(currentElem);
        }
    }

    customSort(rem0);
    reverseSort(rem1);
    customSort(rem2);

    vector<int> result = rem0;
    result.insert(result.end(), rem1.begin(), rem1.end());
    result.insert(result.end(), rem2.begin(), rem2.end());

    removeDuplicates(result);

    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
