// Rock Paper Scissors in C. Various debug statements commented out.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>

const char choices[3][9] = {"Rock", "Paper", "Scissors"};

int rand_max(int);
void get_player_move(char[]);
int find_winner(char[], char[]);
void display_winner(int, int*, int*);
int get_max_rounds();

int rand_max(int max) {
    int n = rand() % max + 1;
    return n;
}

int get_max_rounds() {
    int rounds;
    printf("Enter the amount of rounds you want this to be best out of. Must be odd and less than 11.\n");
    while (true) { 
        scanf("%d", &rounds);
        if (rounds > 0 && rounds < 11 && !(rounds % 2 == 0)) {
            // printf("You chose %d rounds.\n", rounds);
            return rounds;
        }
        else {
        printf("Invalid input for rounds\n"); 
        }
    }
}

void get_player_move(char playerMove[]) {
    printf("Please input one of the following: Rock, Paper, Scissors\n");
    while (true) {
        char move[9];
        gets(move);
        // printf("Value of move: %s\n", move);
        if (strcmp(move, choices[0]) != 0 && strcmp(move, choices[1]) != 0 && strcmp(move, choices[2]) != 0) {
            printf("Invalid input\n");
        }
        else {
            strcpy(playerMove, move);
            break;
        }
    }
}

int find_winner(char playerMove[], char computerMove[]) {
    if (strcmp(playerMove, computerMove) == 0) {
        return 2;
    }  
    else if ((strcmp(playerMove, choices[0]) == 0) && strcmp(computerMove, choices[2]) == 0) {
        return 1;
    }
    else if ((strcmp(playerMove, choices[1]) == 0) && strcmp(computerMove, choices[0]) == 0) {
        return 1;
    }
    else if ((strcmp(playerMove, choices[2]) == 0) && strcmp(computerMove, choices[1]) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void display_winner(int winner, int* playerRounds, int* computerRounds) {
    if (winner == 2) {
        printf("It was a tie!\n");
    }
    else if (winner == 1) {
        printf("You win!\n");
        *playerRounds += 1;
    }
    else if (winner == 0) {
        printf("Computer wins!\n");
        *computerRounds += 1;
    }
    else {
        printf("Something went wrong. The value passed was %d\n", winner);
    }
}

int main() {

    srand((unsigned int)time(NULL));
    int roundMax;
    int playerRounds = 0;
    int computerRounds = 0;
    roundMax = get_max_rounds();
    int roundBreak = ceil(roundMax / 2) + 1;
    // printf("Max rounds: %d\n", (int)ceil(roundMax / 2) + 1);

    while (playerRounds != roundBreak && computerRounds != roundBreak){
        char playerMove[9];
        get_player_move(playerMove);
        // printf("You chose %s\n", playerMove);

        char computerMove[9];
        strcpy(computerMove, choices[rand_max(2)]);
        printf("Computer chose %s\n", computerMove);

        int winner = find_winner(playerMove, computerMove);
        display_winner(winner, &playerRounds, &computerRounds);
        printf("Player: %d | Computer: %d\n", playerRounds, computerRounds);
    }
}
