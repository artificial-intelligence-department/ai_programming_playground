#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    char questions[][100] = {"1. When did Ukraine become an independent country?: ",
                             "2. What country has the highest population in the world?:",
                             "3. Which of these people is a Ukrainian?:"};
    char options[][100] = {"A. 1989 ", "B. 1990 ", "C. 1991 ", "D. 1992 ",
                           "A. India ", "B. China ", "C. USA ", "D. Japan ",
                           "A. Jackie Chan ", "B. Charlie Chaplin ", "C. Igor Sikorsky ", "D. Vin Disel "};
    char answers[3] = {'C', 'A', 'C'};

    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score;

    printf("***QUIZ GAME***\n");
    for (int i = 0; i < numberOfQuestions; i++)
    {
        printf("******************\n");
        printf("%s\n", questions[i]);
        printf("******************\n");
        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }
        printf("guess: ");
        cin >> guess;
        guess = toupper(guess); // converts small letter in big

        if (guess == answers[i])
        {
            printf("CORRECT!\n");
            score++;
        }
        else
        {
            printf("WRONG! The correct answer is: %c\n", answers[i]);
        }
    }
    cout << "******************" << endl;
    printf("Final score: %d/%d\n", score, numberOfQuestions);
    cout << "******************";
    return 0;
}
