#include <stdio.h>
#include <string.h>

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=');
}

int countOperators(char* statement) {
    int count = 0;
    int len = strlen(statement);

    for (int i = 0; i < len; i++) {
        if (isOperator(statement[i])) {
            count++;
        }
    }

    return count;
}

int main() {
    char statement[100];

    printf("Enter a statement: ");
    fgets(statement, sizeof(statement), stdin);

    int operatorCount = countOperators(statement);

    printf("Number of operators: %d\n", operatorCount);

    return 0;
}