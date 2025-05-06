#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Hello World!\n");
  fprintf(stdout, "Hello World!\n"); // the same as normal printf

  char buffer[1024];
  sprintf(buffer, "Hello World!\n");
  printf("%s", buffer); // prints Hello World!

  char buffer_short[10];
  sprintf(buffer_short, "Hello World!\n");
  printf("%s", buffer_short); // prints Hello World! Potential stack overflow

  snprintf(buffer_short, 10,"Hello World!\n");
  printf("%s", buffer_short); // prints Hello Wor Avoids potential stack overflow
}