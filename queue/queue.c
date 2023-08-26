#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
int length = 0;

void enqueue(int value) {
  struct node *lk = (struct node *)malloc(sizeof(struct node));
  lk->value = value;
  length++;
  if (tail == NULL) {
    lk->next = NULL;
    head = lk;
    tail = lk;
    return;
  }

  tail->next = lk;
  tail = lk;
}

int dequeue() {
  if (length == 0) {
    return -1;
  }
  int val = head->value;
  length--;

  struct node *rem = head;
  
  head = rem->next;
  rem->next = NULL;
  free(rem);
  return val;
}

int peek() { return head->value; }

int main(void) {
    enqueue(5);
    enqueue(7);
    enqueue(9);

    if(dequeue() != 5){
        printf("failed on 5");
        return EXIT_FAILURE;
    }
    if(length != 2){
        printf("Failed on length 2");
        return EXIT_FAILURE;
    }
    
    enqueue(11);
    if(dequeue() != 7){
        printf("failed on 7");
        return EXIT_FAILURE;
    }
    if(dequeue() != 9){
        printf("failed on 9");
        return EXIT_FAILURE;
    }
    if(peek() != 11){
        printf("failed on peek 11");
        return EXIT_FAILURE;
    }
    if(dequeue() != 11){
        printf("failed on 11");
        return EXIT_FAILURE;
    }
    if(dequeue() != -1){
        printf("failed on -1");
        return EXIT_FAILURE;
    }
    if(length != 0){
        printf("Failed on length 0");
        return EXIT_FAILURE;
    }


    printf("All tests where successful\n");
    return EXIT_SUCCESS;
}
/*
    // just wanted to make sure that I could not blow up myself when i remove
    // everything
    list.enqueue(69);
    expect(list.peek()).toEqual(69);
    expect(list.length).toEqual(1);
*/
