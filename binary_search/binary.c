#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int length;

bool binary_search(int *haystack, int needle) {
  int lo = 0;
  int hi = length;

  do {
    int m = lo + (hi - lo) / 2;
    int val = haystack[m];

    if (val == needle) {
        return true;
    } else if (val > needle) {
        hi = m ;
    } else {
        lo = m + 1;
    }
  } while (lo < hi);

  return false;
}

int main(int argc, char *argv[]) {

  int foo[11] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  length = sizeof(foo) / sizeof(foo[0]);

  if (!binary_search(foo, 69)) {
    printf("Test fail on value 69\n");
    return EXIT_FAILURE;
  }
  if (!binary_search(foo, 69420)) {
    printf("Test fail on value 69420\n");
    return EXIT_FAILURE;
  }
  if (!binary_search(foo, 1)) {
    printf("Test fail on value 1\n");
    return EXIT_FAILURE;
  }
  if (binary_search(foo, 1336)) {
    printf("Test fail on value 1336\n");
    return EXIT_FAILURE;
  }
  if (binary_search(foo, 69421)) {
    printf("Test fail on value 69421\n");
    return EXIT_FAILURE;
  }
  if (binary_search(foo, 0)) {
    printf("Test fail on value 0\n");
    return EXIT_FAILURE;
  }

  printf("All tests successful\n");

  return EXIT_SUCCESS;
}
