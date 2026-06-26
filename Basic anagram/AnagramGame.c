// Design anagram game using array with an enhanced frontend.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// ANSI escape codes for clean terminal styling
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"
#define CLEAR_SCR   "\033[H\033[J"

// Helper function to create a scrambled version of the target word as a visual hint
void scramble_word(const char *src, char *dest) {
    int len = strlen(src);
    strcpy(dest, src);
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = dest[i];
        dest[i] = dest[j];
        dest[j] = temp;
    }
}

int main() {
    int n, i;
    srand(time(NULL));

    printf(CLEAR_SCR);
    printf(BOLD CYAN "=============================================\n");
    printf("        ANAGRAM GAME INITIALIZATION          \n");
    printf("=============================================\n" RESET);
    
    printf("\nEnter no. of words to add to the game pool: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf(RED "Invalid number of words.\n" RESET);
        return 1;
    }

    char words[n][100];
    printf("Enter %d words (in lowercase):\n", n);
    for(i = 0; i < n; i++) {
        printf(" Word [%d]: ", i + 1);
        scanf("%s", words[i]);
    }

    int score = 0;       
    char choice;         

    do {
        // Clear screen for a fresh game round interface
        printf(CLEAR_SCR);
        
        int random = rand() % n;
        char hint[100];
        scramble_word(words[random], hint);

        // Visual Header / Score Dashboard
        printf(BOLD BLUE "=============================================\n");
        printf("               ANAGRAM CHALLENGE             \n");
        printf("=============================================\n" RESET);
        printf(BOLD YELLOW " CURRENT SCORE: %d pts\n" RESET, score);
        printf(BLUE "---------------------------------------------\n\n" RESET);

        // Displaying clues with visual emphasis
        printf(" Target Word:       " BOLD CYAN "%s\n" RESET, words[random]);

        char user[100];
        printf(BOLD " Enter Anagram: " RESET);
        scanf("%s", user);

        // Core validation logic from your original structure
        int isAnagram = 1; 
        if(strlen(user) != strlen(words[random])) {
            isAnagram = 0; 
        } else {
            int freq1[26] = {0};
            int freq2[26] = {0};

            for(i = 0; i < strlen(words[random]); i++) {
                freq1[words[random][i] - 'a']++;
            }
            for(i = 0; i < strlen(user); i++) {
                freq2[user[i] - 'a']++;
            }
            for(i = 0; i < 26; i++) {
                if(freq1[i] != freq2[i]) {
                    isAnagram = 0;
                    break;
                }
            }
        }

        // Prevent entering the identical word
        if (strcmp(words[random], user) == 0) {
            printf("\n" RED " [!] That's the exact same word! You need an anagram.\n" RESET);
            isAnagram = 0;
        }

        // Results Presentation
        printf("\n---------------------------------------------\n");
        if(isAnagram) {
            score += 10; 
            printf(BOLD GREEN " [+] HURRAY! Correct Anagram. (+10 pts)\n" RESET);
        } else {
            printf(BOLD RED " [-] OH NO! That is incorrect.\n" RESET);
        }
        printf("---------------------------------------------\n");

        printf("\nDo you want to play another round? (y/n): ");
        scanf(" %c", &choice); 

    } while(choice == 'y' || choice == 'Y');

    // Clean Game Over Screen
    printf(CLEAR_SCR);
    printf(BOLD RED "=============================================\n");
    printf("                  GAME OVER                  \n");
    printf("=============================================\n");

}