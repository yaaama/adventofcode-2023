#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example vals */

/* 1abc2 */
/* pqr3stu8vwx */
/* a1b2c3d4e5f */
/* treb7uchet */

int lexer(const char *str, int len) {

  int count = 0;
  int index = 0;
  int reached_first = 0;
  char calibration_val[2] = {0};

  // Loop through the string to find the digits...
  while (count < len) {

    // If we reach a digit
    if (isdigit(str[count])) {

      // Check if it is the first digit we have reached
      if (reached_first == 0) {
        reached_first = 1;
        calibration_val[0] = str[count];
        printf("First digit found! %c\n", calibration_val[index]);
      } else {
        calibration_val[1] = str[count];
        printf("Next digit found... %c\n", calibration_val[1]);
      }
    }

    count++;
  }

  // Checking if there was a second value at all...
  if (!calibration_val[1]) {
    calibration_val[1] = calibration_val[0];
  }

  int parsed = atoi(calibration_val);

  printf("Calibration value is: %d\n", parsed);
  return parsed;
}

int main(void) {

  // Example input
  /* int strlength = strlen("1abc2"); */
  /* int returned = lexer("1abc2", strlength); */
  /* printf("Returned: %d\n", returned ); */

  FILE *fileptr;
  fileptr = fopen("input.txt", "r");

  if (fileptr == NULL) {
    perror("Error opening file");
    return -1;
  }

  int total = 0;

  char buffer[1024];

  while (fgets(buffer, 1024, fileptr)) {
    int len = strlen(buffer);

    printf("Parsing string `%s`", buffer);
    // Remove newline character if present
    if (buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
      len--;
    }

    total += lexer(buffer, len);
    printf("Returned: %d\n", total);
  }

  printf("Total: %d\n", total);

  fclose(fileptr);

  return 0;
}
