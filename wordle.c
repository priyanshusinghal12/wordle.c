#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 5
#define WORDS_ARRAY_SIZE 10

const char* wordList[] = {
    "apple",
    "table",
    "phone",
    "house",
    "mouse",
    "bread",
    "water",
    "grass",
    "chair",
    "music"
};

int getRandom(int max) {
    return rand() % max;
}

void initializeWord(char* word, const char* list[]) {
    int index = getRandom(WORDS_ARRAY_SIZE);
    strcpy(word, list[index]);
}

void displayWordle() {
    printf("\nWelcome to Wordle!\n");
    printf("You have %d attempts to guess a %d-letter word.\n", MAX_ATTEMPTS, WORD_LENGTH);
}

int main() {
    srand(time(0));
    
    char hiddenWord[WORD_LENGTH + 1];
    char guess[WORD_LENGTH + 1];
    int attempts = 0;
    
    initializeWord(hiddenWord, wordList);
    
    displayWordle();
    
    while (attempts < MAX_ATTEMPTS) {
        printf("\nAttempt %d/%d\n", attempts + 1, MAX_ATTEMPTS);
        printf("Enter your %d-letter word guess: ", WORD_LENGTH);
        scanf("%s", guess);
        
        if (strlen(guess) != WORD_LENGTH) {
            printf("Your guess should be %d letters long.\n", WORD_LENGTH);
        } else {
            if (strcmp(guess, hiddenWord) == 0) {
                printf("Congratulations! You've guessed the word: %s\n", hiddenWord);
                break;
            } else {
                printf("Incorrect guess. Try again.\n");
            }
            attempts++;
        }
    }
    
    if (attempts == MAX_ATTEMPTS) {
        printf("You've run out of attempts. The hidden word was: %s\n", hiddenWord);
    }
    
    printf("Thanks for playing Wordle!\n");
    
    return 0;
}
