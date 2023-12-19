#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

bool isDelimiter(char ch) { return strchr(" +-*/,;><=()[]{}", ch) != NULL; }

bool isOperator(char ch) { return strchr("+-*/><=", ch) != NULL; }

bool isKeyword(char *str) {
  char *keywords[] = {"if",       "else",   "while",    "do",    "break",
                      "continue", "int",    "double",   "float", "return",
                      "char",     "case",   "sizeof",   "long",  "short",
                      "typedef",  "switch", "unsigned", "void",  "static",
                      "struct",   "goto"};

  for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
    if (strcmp(str, keywords[i]) == 0) {
      return true;
    }
  }
  return false;
}

bool isInteger(char *str) {
  if (!*str)
    return false;
  while (*str && (isdigit((unsigned char)*str) || (str == str && *str == '-')))
    ++str;
  return !*str;
}

bool isRealNumber(char *str) {
  if (!*str)
    return false;
  int dotCount = 0;
  while (*str) {
    if (!isdigit((unsigned char)*str) && !(str == str && *str == '-')) {
      if (*str != '.' || dotCount > 0)
        return false;
      ++dotCount;
    }
    ++str;
  }
  return dotCount == 1;
}

char *subString(char *str, int left, int right) {
  return strndup(&str[left], right - left + 1);
}

bool validIdentifier(char *str) {
  if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' ||
      str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' ||
      str[0] == '8' || str[0] == '9' || isDelimiter(str[0]) == true)
    return (false);
  return (true);
}

void parse(char *str) {
  int len = strlen(str);
  int left = 0, right = 0;

  while (right <= len) {
    if (isDelimiter(str[right])) {
      if (left == right) {
        if (isOperator(str[right])) {
          printf("'%c' IS A OPERATOR\n", str[right]);
        }
        ++right;
        left = right;
      } else {
        char *subStr = subString(str, left, right - 1);
        if (isKeyword(subStr)) {
          printf("'%s' IS A KEYWORD\n", subStr);
        } else if (isInteger(subStr)) {
          printf("'%s' IS A INTEGER\n", subStr);
        } else if (isRealNumber(subStr)) {
          printf("'%s' IS A REAL NUMBER\n", subStr);
        } else if (!isDelimiter(subStr[0])) {
          printf("'%s' %s\n", subStr,
                 validIdentifier(subStr) ? "IS A VALID IDENTIFIER"
                                         : "IS NOT A VALID IDENTIFIER");
        }
        free(subStr);
        left = right;
      }
    } else {
      ++right;
    }
  }
}

int main() {
  char str[MAX_LENGTH];
  printf("Enter the statement: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  parse(str);
  return 0;
}
