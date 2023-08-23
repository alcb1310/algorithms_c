#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int length;

bool linear_search(int *haystack, int needle) {
  for (int i = 0; i < length; i++) {
    if (haystack[i] == needle) {
      return true;
    }
  }

  return false;
}

int main(void) {
  int foo[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  length = sizeof(foo) / sizeof(foo[0]);

  if (!linear_search(foo, 69)) {
    printf("Unsuccessful test with 69\n");
    return EXIT_FAILURE;
  }

  if (linear_search(foo, 1336)) {
    printf("Unsuccessful test with 1336\n");
    return EXIT_FAILURE;
  }

  if (!linear_search(foo, 69420)) {
    printf("Unsuccessful test with 69420\n");
    return EXIT_FAILURE;
  }

  if (linear_search(foo, 69421)) {
    printf("Unsuccessful test with 69421\n");
    return EXIT_FAILURE;
  }

  if (!linear_search(foo, 1)) {
    printf("Unsuccessful test with 1\n");
    return EXIT_FAILURE;
  }

  if (linear_search(foo, 0)) {
    printf("Unsuccessful test with 0\n");
    return EXIT_FAILURE;
  }

  printf("All tests successful\n");
  return EXIT_SUCCESS;
}
