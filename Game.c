#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choices[3][20] = {"Rock", "Paper", "Scissors"};
    int computerChoice, userChoice, rounds, computerScore = 0, userScore = 0;

    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors!\n");

    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &rounds);

    if (rounds < 1) {
        printf("Please enter a valid number of rounds.\n");
        return 0;
    }

    int round;
    for (round = 1; round <= rounds; round++) {
        computerChoice = rand() % 3;

        printf("\nRound %d:\n", round);
        printf("1 for Rock\n2 for Paper\n3 for Scissors\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            round--;
            continue;
        }

        printf("\nYou chose %s\n", choices[userChoice - 1]);
        printf("Computer chose %s\n", choices[computerChoice]);

        if (userChoice == computerChoice + 1 || (userChoice == 1 && computerChoice == 2)) {
            userScore++;
            printf("You Win this round!\n");
        } else if (userChoice == computerChoice) {
            printf("It's a Tie this round!\n");
        } else {
            computerScore++;
            printf("Computer Wins this round!\n");
        }
    }

    printf("\nGame Over! Final Scores:\n");
    printf("Computer: %d  User: %d\n", computerScore, userScore);

    if (userScore > computerScore) {
        printf("Congratulations! You win the game!\n");
    } else if (userScore < computerScore) {
        printf("Computer wins the game!\n");
    } else {
        printf("It's a Tie! No one wins.\n");
    }

    return 0;
}