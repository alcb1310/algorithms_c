#include <stdio.h>

void printArray(int *haystack, int length){
    printf("[ ");
    for (int i = 0; i < length; i++){
        printf("%i ", haystack[i]);
        if (i != length - 1){
            printf(", ");
        }
    }
    printf(" ]\n");
}
