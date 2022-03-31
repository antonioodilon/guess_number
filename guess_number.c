/*
Written by Antonio de Odilon Brito
Natal/RN, Brazil
March, 2022
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>  // for random number generator seed

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    //int randomNumber = rand()%21;
    int randomNumber = 13; // Hardcoding the variable randomNumber for testing purposes.
    // You can uncomment the line if you would like to test it.
    int userChoice;
    int count = 1;
    printf("Guess a number 0 to 20 (you have 5 tries!): ");
    scanf("%d", &userChoice);
    printf("\n");

    while (userChoice != randomNumber, count <= 5) {
        while (userChoice < 0 || userChoice > 20) {
        // Since numbers greater than 20 or less than 0 aren't valid answers, they won't count as tries.
        // Therefore, the "count" variable isn't being incremented in this inner loop.
            printf("The only valid numbers are between 0 and 20.\n");
            printf("Please insert a valid number: ");
            scanf("%d", &userChoice);
            if (!(userChoice < 0) && !(userChoice > 20)) {
                break;
            };
        };

        if (count >= 5 && userChoice != randomNumber) {
            printf("You've lost. %d wasn't the number; it was %d. Please try again.", userChoice, randomNumber);
            break;
        };

        if (userChoice > randomNumber) {
            ++count;
            printf("This is next guess is your guess number %d. Remember you have 5 tries in total!", count);
            printf("\n %d is too high. Please enter your choice again: ", userChoice);
            scanf("%d", &userChoice);
        } else if (userChoice < randomNumber) {
            ++count;
            printf("This is next guess is your guess number %d. Remember you have 5 tries in total!", count);
            printf("\n %d is too low. Please enter your choice again: ", userChoice);
            scanf("%d", &userChoice);
        } else {
            printf("Congratulations! It was indeed %d\n", randomNumber);
            break;
        };
    };

    return 0;
};
