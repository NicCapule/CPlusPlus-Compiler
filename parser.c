#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Forward declarations
enum TokenType { IDENTIFIER, NUMBER, KEYWORD, SYMBOL, STRING, END };
struct Token {
    enum TokenType type;
    char value[100];
};

struct Token getToken(char **src); // Forward declaration for getToken

void parseToken(char *src) {
    struct Token token;
    token = getToken(&src); // Fetch the first token

    while (token.type != END) {
        if (token.type == KEYWORD && strcmp(token.value, "cin") == 0) {
            token = getToken(&src); // expect ">>"
            if (strcmp(token.value, ">>") == 0) {
                token = getToken(&src); // expect identifier
                if (token.type == IDENTIFIER) {
                    printf("READ %s\n", token.value); // Generate machine code for input
                }
            }
        } else if (token.type == KEYWORD && strcmp(token.value, "cout") == 0) {
            token = getToken(&src); // expect "<<"
            if (strcmp(token.value, "<<") == 0) {
                token = getToken(&src);
                if (token.type == IDENTIFIER) {
                    printf("PRINT %s\n", token.value); // Generate machine code for output
                } else if (token.type == STRING) {
                    printf("PRINT_STRING %s\n", token.value);
                }
            }
        } else if (token.type == IDENTIFIER) {
            char var[100];
            strcpy(var, token.value); // store variable name
            token = getToken(&src);    // expect "="
            if (strcmp(token.value, "=") == 0) {
                token = getToken(&src); // expect number or identifier
                if (token.type == NUMBER) {
                    printf("STORE %s, %s\n", var, token.value); // Store variable assignment
                }
            }
        }
        token = getToken(&src);
    }
}

// Main function
int main() {
    // Example source code input for parsing
    char source[] = "cin >> x; cout << \"hello\"; x = 5;";
    parseToken(source);
    return 0;
}
