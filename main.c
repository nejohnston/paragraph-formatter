#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

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
////            paragraphCounter++;
//        }
        if ((paragraph[paragraphCounter+1] == ' ' && paragraph[paragraphCounter] != ' ') ) {
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
int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int *characterCounter, int totalNumberOfWords,
                                int numberOfWordsProcessedSoFar, int lineLength) {
    int whiteSpaceCount = 0;
    int characterCount = 0;
    int arrayCounter = 0;
    do {
        arrayCounter++;
        characterCount += strlen(tokens[arrayCounter]) + arrayCounter;
        whiteSpaceCount++;
    } while ((characterCount+arrayCounter)<lineLength && *tokens[arrayCounter] != '\0');
    *characterCounter = characterCount;
    return arrayCounter;
}

/*
 * Print a string followed by a number of spaces
 */
void printWordAndSpaces(char word[MAX_WORD_LENGTH], double numberOfSpaces) {
    int totalSpaces = numberOfSpaces*strlen(word);
    char spaces[totalSpaces+1];
    for (int index = 0; index<=numberOfSpaces; index++) {
        spaces[index] = ' ';
    }
    printf("%s%s", word, spaces);
}

/*
 *
 */
void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords,
                               int numberOfWordsOnNextLine, double lineLength,
                               int numberOfWordsProcessedSoFar) {
    double characterCount = 0;
    for (int index = 0; index<=numberOfWordsOnNextLine; index++) {
        characterCount += strlen(tokens[index]);
    }

    double numberOfSpacesRemaining = lineLength - characterCount;
    double numberOfSpacesBetweenWords = numberOfWordsOnNextLine - 1;
    for (int index = numberOfWordsProcessedSoFar; index<=(numberOfWordsOnNextLine+numberOfWordsProcessedSoFar); index++) {
        int numberOfSpaces = ceil(numberOfSpacesRemaining/numberOfSpacesBetweenWords);
        printWordAndSpaces(tokens[index], numberOfSpaces);
        numberOfWordsOnNextLine--;
        numberOfSpacesRemaining -= ceil(numberOfSpacesRemaining/numberOfWordsOnNextLine);
    }
}

//void formatAndPrintWords(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int lineLength) {
//
//}

void formatAndPrintParagraph(char *paragraph, int lineLength){
    char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int numberOfWordsProcessedSoFar = 0;
    int characterCount = 0;
    int totalNumberOfWords = tokenize(paragraph, tokens);
    int numberOfWordsOnNextLine = getNumberOfWordsForNextLine(tokens, &characterCount, totalNumberOfWords, numberOfWordsProcessedSoFar,
                                                              lineLength);
    printf("%d %d %d\n", numberOfWordsOnNextLine, numberOfWordsProcessedSoFar, characterCount);
    formatAndPrintCurrentLine(tokens, totalNumberOfWords, numberOfWordsOnNextLine, lineLength, numberOfWordsProcessedSoFar);
//    numberOfWordsProcessedSoFar += numberOfWordsOnNextLine;
//    for (int index = 0; index<22; index++) {
//        printf("%s\n", tokens[index]);
//    }
}

int main() {
    char paragraph[] = "Hi  everyone. This is the 2nd assignment. Please make sure you start early as this is going to "
                       "take some time!";
    formatAndPrintParagraph(paragraph, 20);
}