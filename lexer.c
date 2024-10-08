#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum TokenType { IDENTIFIER, NUMBER, KEYWORD, SYMBOL, STRING, END };

struct Token {
    enum TokenType type;
    char value[100];
};

char *keywords[] = {"cin", "cout", NULL};
char *symbols[] = {">>", "<<", "+", "=", ";", NULL};

// Check if a string is a keyword
int isKeyword(char *str) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if a character is a symbol
int isSymbol(char ch) {
    for (int i = 0; symbols[i] != NULL; i++) {
        if (ch == symbols[i][0])
            return 1;
    }
    return 0;
}

// Tokenize the input
struct Token getToken(char **src) {
    struct Token token;
    token.type = END;

    while (isspace(**src)) (*src)++;

    if (isdigit(**src)) {
        token.type = NUMBER;
        int i = 0;
        while (isdigit(**src)) token.value[i++] = *(*src)++;
        token.value[i] = '\0';
    } else if (isalpha(**src)) {
        int i = 0;
        while (isalnum(**src)) token.value[i++] = *(*src)++;
        token.value[i] = '\0';
        token.type = isKeyword(token.value) ? KEYWORD : IDENTIFIER;
    } else if (isSymbol(**src)) {
        token.type = SYMBOL;
        token.value[0] = *(*src)++;
        token.value[1] = '\0';
    } else if (**src == '"') {
        (*src)++;
        token.type = STRING;
        int i = 0;
        while (**src != '"') token.value[i++] = *(*src)++;
        (*src)++;
        token.value[i] = '\0';
    }

    return token;
}
