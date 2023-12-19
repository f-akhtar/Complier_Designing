#include <ctype.h>
#include <stdio.h>

int main() {
  FILE *file;
  char filename[100];
  char ch;
  int vowelCount = 0, consonantCount = 0, digitCount = 0;

  printf("Enter the file name: ");
  scanf("%s", filename);

  file = fopen(filename, "r");

  if (file == NULL) {
    printf("File not found or unable to open.\n");
    return 1;
  }

  while ((ch = fgetc(file)) != EOF) {
    if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' ||
        tolower(ch) == 'o' || tolower(ch) == 'u') {
      vowelCount++;
    }
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      consonantCount++;
    }
    else if (isdigit(ch)) {
      digitCount++;
    }
  }

  fclose(file);

  printf("Number of vowels: %d\n", vowelCount);
  printf("Number of consonants: %d\n", consonantCount);
  printf("Number of digits: %d\n", digitCount);

  return 0;
}
