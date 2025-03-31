#include <stdio.h>
#include <string.h>

int main() {
  int n;
  printf("How many strings ? ");
  scanf("%d", &n);

  char *strings[n];
  char content[n][128];

  // fill char array with actual strings
  for (int i = 0; i < n; i++) {
    printf("Enter string %d: ", i + 1);
    scanf("%s", content[i]);
  }

  // build index with pointers
  for (int i = 0; i < n; i++) {
    strings[i] = content[i];
  }

  // print content
  for (int i = 0; i < n; i++) {
    printf("%s\n", content[i]);
  }

  // print content using the index
  for (int i = 0; i < n; i++) {
    printf("%s\n", strings[i]);
  }
}