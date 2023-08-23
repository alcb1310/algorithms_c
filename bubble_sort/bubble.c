#include <stdio.h>
#include <stdlib.h>
#include "../helpers/array.h"

int length;

void bubbleSort(int *haystack){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length - i -1; j++){
            if (haystack[j] > haystack[j+1]){
                int m = haystack[j];
                haystack[j] = haystack[j + 1];
                haystack[j + 1] = m;
            }
        }
    }
}

int main(void) { 
    int foo[] = {9, 3, 7, 4, 69, 420, 42};
    length = sizeof(foo) / sizeof(foo[0]);
    printArray(foo, length);
    bubbleSort(foo);

    printArray(foo, length);

    return EXIT_SUCCESS;
}
