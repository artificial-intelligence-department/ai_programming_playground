#include <iostream>
#define CHECK_FOR_REMOVED_OBJECT nums[i] != del[0] && nums[i] != del[1] && nums[i] != del[2]

int main()
{
        //prompting
    //розмір масиву
    int n;
    std::cin >> n;

    //самі ці числа
    int nums[n];
    for(int i = 0; i < n; i++)
        std::cin >> nums[i];
    
    //ті, які треба видалити
    int del[3];
    for(int i = 0; i < 3; i++)
        std::cin >> del[i];

        //main logic
    //дізнаємось скільки чисел буде у новому масиві
    int newSize = 0, remaining[n];
    for(int i = 0, j = 0; i < n; i++)
    {
        if(CHECK_FOR_REMOVED_OBJECT)
        {  //якби було >3 числа, які треба перевірити, то можна було б циклом зробити
            newSize++;
            remaining[j++] = nums[i];
        }
    }
    //одразу й виводимо
    if(newSize <= 0)
    {
        std::cout << 0;
        return 0;
    }
    std::cout << newSize - 1 << std::endl;
    
    //створення й вивід нового масиву
    int newNums[newSize - 1];
    for(int i = 0, j = 0; i < newSize - 1; i++)
    {
        newNums[i] = remaining[i] + remaining[i+1];
        std::cout << newNums[i] << " ";
    }
    return 0;
}
