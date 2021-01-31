#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20

#define MAX_NUMBER_OF_WORDS 100

/*
 * Move pointer to first non-blank character
 */
char *moveToBeginningOfNextToken(char *inputString){
//    int index = 0;
//    if (inputString[index] != ' '){
//        return
//    }
}

/*
 * Determine size of first word
 *
 * precondition: no leading whitespace
 */
int getCurrentTokenSize(char *inputString) {
    return strlen(inputString);
}

/*
 * Add individual words to array tokens
 */
int tokenize(char * paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]){
    int firstDCounter = 0;
    int secondDCounter = 0;
    int paragraphCounter = 0;
    while (paragraphCounter<=strlen(paragraph)) {
        if (paragraph[paragraphCounter] != ' ') {
            tokens[firstDCounter][secondDCounter] = paragraph[paragraphCounter];
            paragraphCounter+=1;
            secondDCounter+=1;
        }
        else {
            paragraphCounter+=1;
            firstDCounter+=1;
            secondDCounter=0;
        }
    }
    printf("%s", tokens);
}

/*
 * Determine words to be printed on next line
 */
int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
                                int totalNumberOfWords, int lineLength);

/*
 * Print a string followed by a number of spaces
 */
void printWordAndSpaces( char word[MAX_WORD_LENGTH], int numberOfSpaces);

/*
 *
 */
void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
                               int numberOfWordsOnNextLine, int lineLength);

void formatAndPrintWords(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int lineLength);

void formatAndPrintParagraph(char *paragraph, int lineLength){
//    printf("%lu %s", sizeof(paragraph), paragraph);
//    for(int index = 0; index<lineLength; index++) {
//        printf("\n%c",paragraph[index]);
//    }

    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    tokenize(paragraph, tokens);
}

int main() {
    char paragraph[] = "hello world i went for a walk today it was raining";
    formatAndPrintParagraph(paragraph, 25);
}