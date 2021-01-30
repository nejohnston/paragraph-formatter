#define MAX_WORD_LENGTH 20

#define MAX_NUMBER_OF_WORDS 100

char *moveToBeginningOfNextToken(char *inputString);

int getCurrentTokenSize(char *inputString);

int tokenize(char * paragraph, char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH]);

int getNumberOfWordsForNextLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
                                int totalNumberOfWords, int lineLength);

void printWordAndSpaces( char word[MAX_WORD_LENGTH], int numberOfSpaces);

void formatAndPrintCurrentLine(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int numberOfWordsProcessedSoFar,
                               int numberOfWordsOnNextLine, int lineLength);

void formatAndPrintWords(char tokens[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH], int totalNumberOfWords, int lineLength);

void formatAndPrintParagraph(char *paragraph, int lineLength);
