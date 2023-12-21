#include <iostream>
#include <vector>

// Функція для сортування масиву
void mySort(std::vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = 0; j < n - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Функція для знаходження максимального елементу
int myMax(const std::vector<int> &arr)
{
  int maxVal = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    if (arr[i] > maxVal)
    {
      maxVal = arr[i];
    }
  }
  return maxVal;
}

// Функція для знаходження мінімального елементу
int myMin(const std::vector<int> &arr)
{
  int minVal = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    if (arr[i] < minVal)
    {
      minVal = arr[i];
    }
  }
  return minVal;
}

int main()
{
  // Зчитування кількості чисел
  int N;
  std::cin >> N;

  // Зчитування масиву чисел
  std::vector<int> road(N);
  for (int i = 0; i < N; ++i)
  {
    std::cin >> road[i];
  }

  // Сортування масиву чисел
  mySort(road);

  // Ініціалізація мінімальної втоми як максимальної можливої
  int minFatigue = myMax(road) - myMin(road);

  // Перевірка втоми для кожного видаленого числа
  for (int i = 0; i < N; ++i)
  {
    std::vector<int> tempRoad = road; // Копія масиву для видалення числа
    tempRoad.erase(tempRoad.begin() + i);

    int currentFatigue = myMax(tempRoad) - myMin(tempRoad);
    minFatigue = std::min(minFatigue, currentFatigue);
  }

  // Виведення результату
  std::cout << minFatigue << std::endl;

  return 0;
}