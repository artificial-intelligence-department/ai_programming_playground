#include <iostream>
#include <algorithm>

const int size1 = 100;

void N_M(int N, int M, int n[], int m[]) // функція для обчислення різниць
{
    int score = 0;
    int temp[size1] = {0};
    int temp1[size1];
    
    // Ініціалізуємо temp масив значеннями з масиву n/m
    for (int i = 0; i < N; i++) 
    {
        temp[i] = n[i];
    }
    for (int i = 0; i < M; i++) 
    {
        temp1[i] = m[i];
    }


    // Перевіряємо, чи елемент n[i]/m[i] є в m/n
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (temp[i] == temp1[j]) 
            {
                temp1[j] = 0;
                // Якщо n[i]/m[i] є в m/n, замінюємо його нулем
                temp[i] = 0;
                score += 1;
                break;
            }
        }
    }
    std::sort(temp, temp + size1);
    std::cout << N-score << std::endl;
    for (int i = 0; i < size1; i++) 
    {
        if (temp[i] != 0) 
        {
            std::cout << temp[i] << " ";
        }
    }
    std::cout << std::endl;
}

void sum(int N, int M, int n[], int m[]) //  перетин
{
    int score = 0;
    int temp[size1];

    // Перевіряємо, чи елемент n[i] є в m
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (n[i] == m[j]) 
            {
                temp[score] = n[i];
                score += 1;
                break;
            }
        }
    }
    std::sort(temp, temp + score);
    std::cout << score << std::endl;
    for (int i = 0; i < score; i++) 
    {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

void suma(int N, int M, int n[], int m[]) // обєднання
{
    int score = 0;
    int temp[N + M];

    for (int i = 0; i < N; i++) 
    {
        temp[i] = n[i];
    }

    // Додаємо унікальні елементи масиву m, які не входять в масив n
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (m[i] == n[j]) 
            {
                break;
            }

            // Якщо цикл завершився і m[i] не знайдено в n, додаємо його до temp
            if (j == N - 1) 
            {
                temp[N + score] = m[i];
                score++;
            }
        }
    }
    std::sort(temp, temp +(N + score));
    std::cout << N + score << std::endl;
    for (int i = 0; i < N + score; i++) 
    {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}

void rizni(int N, int M, int n[], int m[]) // симетрична різниця
{
    int score = 0;
    int temp[size1] = {0};
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (n[i] == m[j]) 
            {
                m[j] = 0;
                break;
            }
            else if(j == M - 1)
            {
                temp[score] = n[i];
                score++;
            }
        }
    }
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (m[i] == n[j]) 
            {
                n[j] = 0;
                break;
            }
            else if(j == N - 1)
            {
                temp[score] = m[i];
                score++;
            }
        }
    }

    int nonZeroCount = 0; // Змінна для збереження кількості ненульових елементів

    for (int i = 0; i < size1; i++) 
    {
        if (temp[i] != 0) 
        {
            nonZeroCount++;
        }
    }

    std::cout << nonZeroCount << std::endl;
    std::sort(temp, temp + size1);
    for (int i = 0; i < size1; i++) 
    {
        if (temp[i] != 0) 
        {
            std::cout << temp[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() 
{
    int N, M;
    int n[size1], m[size1];

    std::cin >> N;
    for (int i = 0; i < N; i++) 
    {
        std::cin >> n[i];
    }

    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        std::cin >> m[i];
    }

    N_M(N, M, n, m);
    N_M(M, N, m, n);
    sum(M, N, m, n);
    suma(N, M, n, m);
    rizni(N, M, n, m);

    return 0;
}
