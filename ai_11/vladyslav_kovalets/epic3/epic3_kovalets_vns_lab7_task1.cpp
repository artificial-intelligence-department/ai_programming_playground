    #include <iostream>

    double mult(int count, float args[])
    {
        float dobutok = 1;

        for (int i = 0; i < count; ++i)
        {
            dobutok = dobutok * args[i];
        }

        return dobutok;
    }

    int main()
    {
        float result1 = mult(3, new float[]{7.1, 3.0, 1.0});
        float result2 = mult(7, new float[]{7.0, 2.5, 1.0, 9.0, 4.0, 1.1, 2.4, 1.0});
        float result3 = mult(11, new float[]{1.0, 1.0, 3.0, 5.0, 4.0, 0.1, 8.0, 1.0, 4.2, 5.0, 1.1, 0.1});

        std::cout << "Result 1: " << result1 << std::endl;
        std::cout << "Result 2: " << result2 << std::endl;
        std::cout << "Result 3: " << result3 << std::endl;

        return 0;
    }
