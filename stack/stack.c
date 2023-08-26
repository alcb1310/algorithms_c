#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *head = NULL;
int length = 0;

void insert(int value) {
  struct node *lk = (struct node *)malloc(sizeof(struct node));
  lk->value = value;
  length++;

  lk->next = head;
  head = lk;
}

int peek() { return head->value; }

int delete() {
  if (length == 0) {
    return -1;
  }

  length--;
  int val = head->value;
  struct node *lk = head;

  head = lk->next;
  free(lk);

  return val;
}
int main(int argc, char *argv[]) {
    insert(5);
    insert(7);
    insert(9);

    int val = delete();
    if(val != 9){
        printf("Error in pop 9\n");
        return EXIT_FAILURE;
    }
    insert(11);
    val = delete();
    if(val != 11){
        printf("Error in pop 11\n");
        return EXIT_FAILURE;
    }
    val = delete();
    if(val != 7){
        printf("Error in pop 7\n");
        return EXIT_FAILURE;
    }
    if(peek() != 5){
        printf("Error in peek 5\n");
        return EXIT_FAILURE;
    }
    val = delete();
    if(val != 5){
        printf("Error in pop 5\n");
        return EXIT_FAILURE;
    }
    val = delete();
    if(val != -1){
        printf("Error in pop -1\n");
        return EXIT_FAILURE;
    }

    insert(69);
    if(length != 1){
        printf("Error at inserting 69\n");
        return EXIT_FAILURE;
    }
    if(peek()!= 69){
        printf("Error at inserting 69\n");
        return EXIT_FAILURE;
    }



    printf("All heap tests are successful\n");
    return EXIT_SUCCESS;
}
/*

    // just wanted to make sure that I could not blow up myself when i remove
    // everything
    list.push(69);
    expect(list.peek()).toEqual(69);
    expect(list.length).toEqual(1);

    //yayaya
*/
