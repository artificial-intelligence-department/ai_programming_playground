#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedNumbers(vector<int> numbers) {
vector<int> ostacha0, ostacha1, ostacha2;

for (int num : numbers) {
    if (num % 3 == 0) {
        ostacha0.push_back(num);
    } else if (num % 3 == 1) {
    ostacha1.push_back(num);
    } else {
    ostacha2.push_back(num);
    }
}

sort(ostacha0.begin(), ostacha0.end());
sort(ostacha1.begin(), ostacha1.end(), greater<int>());
sort(ostacha2.begin(), ostacha2.end());

vector<int> result = ostacha0;
result.insert(result.end(), ostacha1.begin(), ostacha1.end());
result.insert(result.end(), ostacha2.begin(), ostacha2.end());

auto elements = unique(result.begin(), result.end());
result.erase(elements, result.end());

return result;
}

int main() {
int N;
cin >> N;

vector<int> numbers(N);
for (int i=0; i<N; ++i) {
    cin >> numbers[i];
}

vector<int> Result = sortedNumbers(numbers);
cout << Result.size() << endl;

for (int i=0; i < Result.size(); ++i) {
    cout << Result[i] << " ";
}
return 0;
}