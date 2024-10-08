#include <stdio.h>
#include <string.h>

// Function prototype for parseToken
void parseToken(char *src);

// Main function
int main() {
    // Example source code input for PL1.cpp, PL2.cpp, PL3.cpp
    char source1[] = "cin >> x;";
    char source2[] = "x = 3; y = 4; cout << x + y;";
    char source3[] = "cout << \"hello\";";

    printf("Source 1:\n");
    parseToken(source1);

    printf("\nSource 2:\n");
    parseToken(source2);

    printf("\nSource 3:\n");
    parseToken(source3);

    return 0;
}

// Dummy implementation of parseToken
void parseToken(char *src) {
    // This is a placeholder function
    // In actual implementation, you would replace this with your parsing logic
    printf("Parsing: %s\n", src);
}
