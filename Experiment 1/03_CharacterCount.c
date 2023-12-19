#include <stdio.h>
#include <string.h>

int main() {
    char statement[100];

    printf("Enter a statement: ");
    fgets(statement, sizeof(statement), stdin);

    statement[strcspn(statement, "\n")] = '\0';

    int charCount = strlen(statement);

    printf("Number of characters: %d\n", charCount);

    return 0;
}
