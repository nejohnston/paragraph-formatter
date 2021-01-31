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
int tokenize(char *paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]){
    int firstDCounter = 0;
    int secondDCounter = 0;
    int paragraphCounter = 0;
    while (paragraphCounter<=strlen(paragraph)) {
        if (paragraph[paragraphCounter] != ' ') {
            tokens[firstDCounter][secondDCounter] = paragraph[paragraphCounter];
            secondDCounter++;
        }
//        else {
//            firstDCounter++;
//            secondDCounter = 0;
//            paragraphCounter++;
//        }
        if (paragraph[paragraphCounter-1] == ' ' && paragraph[paragraphCounter] != ' ') {
            firstDCounter++;
            secondDCounter = 0;
        }
        paragraphCounter++;
    }
    return firstDCounter;
}

/*
 * Determine words to be printed on next line
 */
int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int lineLength) {
//    int totalNumberOfWords, int numberOfWordsProcessedSoFar,
    int whiteSpaceCount = 0;
    unsigned long characterCount = 0;
    int arrayCounter = 0;

    while (characterCount<lineLength) {
        arrayCounter+=1;
        characterCount += strlen(tokens[arrayCounter]) + arrayCounter;
        whiteSpaceCount++;
    }

    return arrayCounter;
}

/*
 * Print a string followed by a number of spaces
 */
void printWordAndSpaces(char word[MAX_WORD_LENGTH], int numberOfSpaces);

/*
 *
 */
void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int numberOfWordsOnNextLine,
                               int lineLength) {
    for (int index = 0; index<=numberOfWordsOnNextLine; index++) {
        printf("%s", tokens[index]);
    }
}

//void formatAndPrintWords(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int lineLength) {
//
//}

void formatAndPrintParagraph(char *paragraph, int lineLength){
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int totalNumberOfWords = tokenize(paragraph, tokens);
    int nextLineWords = getNumberOfWordsForNextLine(tokens, lineLength);
    printf("%d", nextLineWords);
    formatAndPrintCurrentLine(tokens, totalNumberOfWords, nextLineWords, lineLength);
}

int main() {
    char paragraph[] = "hello world i went  for a  walk today it was raining";


    formatAndPrintParagraph(paragraph, 25);
}