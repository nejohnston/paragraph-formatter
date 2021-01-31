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
int tokenize(const char *paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]){
    int firstDCounter = 0;
    int secondDCounter = 0;
    int paragraphCounter = 0;
    int characterCounter = 0;
    while (paragraph[paragraphCounter]<=strlen(paragraph)) {
        if (paragraph[paragraphCounter] != ' ') {
            tokens[firstDCounter][secondDCounter] = paragraph[paragraphCounter];
            secondDCounter++;
        }
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
int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords,
                                int lineLength) {
    int whiteSpaceCount = -1;
    unsigned long characterCount = 0;
    int arrayCounter = 0;

    while (whiteSpaceCount+characterCount<=lineLength) {
        whiteSpaceCount++;
        characterCount += strlen(tokens[arrayCounter]);
        arrayCounter++;
    }
}

/*
 * Print a string followed by a number of spaces
 */
void printWordAndSpaces(char word[MAX_WORD_LENGTH], int numberOfSpaces);

/*
 *
 */
void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
                               int numberOfWordsOnNextLine, int lineLength) {

}

void formatAndPrintWords(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int lineLength) {

}

void formatAndPrintParagraph(char *paragraph, int lineLength){
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int totalNumberOfWords = tokenize(paragraph, tokens);
    getNumberOfWordsForNextLine(tokens, totalNumberOfWords, lineLength);
}

int main() {
    char paragraph[] = "hello world i went for a walk today it was raining";
    formatAndPrintParagraph(paragraph, 25);
}