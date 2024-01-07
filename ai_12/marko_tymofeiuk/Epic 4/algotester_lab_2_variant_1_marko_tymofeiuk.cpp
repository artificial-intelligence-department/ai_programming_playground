#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    int elementNum, maxel, minel, tired;
    std::cin >> elementNum;
    int mainArray[elementNum], delArray[elementNum];
    int opnum = elementNum - 1;
    for (int i = 0; i < elementNum; i++)
    {
        std::cin >> mainArray[i];
    }

    for (int y = 0; y < elementNum; y++)
    {
        int modArray[elementNum];
        for (int i = 0; i < elementNum; i++)
        {
            modArray[i] = mainArray[i];
        }
        for (int k = y; k < (opnum); k++)
        {
            modArray[k] = modArray[k + 1];
        }
        maxel = modArray[0];
        minel = modArray[0];
        for (int m = 1; m < opnum; m++)
        {
            maxel = std::max(maxel, modArray[m]);
            minel = std::min(minel, modArray[m]);
        }
        tired = maxel - minel;
        delArray[y] = {tired};
    }

    int final = delArray[0];
    for (int x = 1; x < elementNum; x++)
    {
        final = std::min(final, delArray[x]);
    }
    std::cout << final;
}