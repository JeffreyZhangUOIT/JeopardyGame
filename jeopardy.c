/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Jehro Celemin, Jeffrey Zhang, Nicolas Zarfino, Kabilan Sivagnanasundaram>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players);
void game_on(char **token, player *players);


int main(void)
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    // Prompt for players names
    printf("Now begins a game of Jeopardy for 4 players! Please enter your names:\n");
    for(int i = 0; i < 4; i++) {
        scanf("%s", players[i].name);
    }
    printf("The 4 players are confirmed.\n");
    
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        char **token = NULL;
        initialize_game();
        
        // Execute the game until all questions are answered
        game_on(token, players);
        return 0;
    }
}

// Shows the corresponding scores for each player
void show_results(player *players) {
    for(int i = 0; i <= 4; i++) {
        printf("Name: %s\tScore:%d\n", players[i].name, players[i].score);
    }
}

// tokenizer
void tokenize(char *input, char **tokens){

    char *first_token = strtok(input, " ");
    first_token = strtok(input, " ");

    for(int i = 0; first_token != NULL; i++){
        strcpy(tokens[i], first_token);
        first_token = strtok(NULL, " ");
    }       
}
    
// structures how the game is run
void game_on(char **token, player *players){
    // All questions must be answered to end game
    int num_of_questions_left = sizeof(questions);
    bool correct;
    char *category;  
    int value = 0;
    char reply[BUFFER_LEN] = {0};
    int i =0;
    category = (char *) calloc(BUFFER_LEN, sizeof(char));

    while(num_of_questions_left > 0) {
        printf("It is %s's turn.\nPlease choose from the provided categories and the available amounts left.\n(Protocol: [category] ENTER [value] ENTER):\n", players[i].name);

        display_categories();

        printf("\n");
        scanf("%s", category);
        scanf("%d", &value);
        printf("You have chosen: %s %d.\n", category, value);
        // printf("\n");

        if(already_answered(category, value)) {
            printf("Already answered. Please choose another.\n");
            
        }
        else if (valid_input(category, value))
        {
            display_question(category, value);
            scanf("%s", reply);

            //tokenize(reply, token);
            correct = valid_answer(category, value, reply);
            if(correct){
                question_answered(category, value);
                printf("Correct! Choose the next question.\n\n");
                players[i].score += value;
            }
            else{
                printf("Incorrect!\n");
                i++;
            }

            fflush(stdin);
            num_of_questions_left--;
            if(num_of_questions_left<=0)
            {
                break;
            }
        }
        else 
        {
            printf("Invalid question. Please choose another.\n");
        } 

        
    }

    // Display the final results and exit
    show_results(players);
}
