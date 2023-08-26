#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;

void printList() {
    struct node *p = head;
    
    printf("\n[ ");

    while (p != NULL){
        printf("%d, ", p->data);
        p = p->next;
    }

    printf(" ]\n");

}

void insertatbegin(int data){
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;

    if (head ==  NULL && tail == NULL ){
        lk->next = NULL;
        head = lk;
        tail = lk;
        return;
    }

    lk->next = head;
    head = lk;
}

void insertatend(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = NULL;

    if (head ==  NULL && tail == NULL ){
        lk->next = NULL;
        head = lk;
        tail = lk;
        return;
    }

    tail->next = lk;
    tail = lk;
}

int peekFirst() {
    return head->data;
}

int peekLast() {
    return tail->data;
}

int main(){
   int k=0;
   insertatbegin(12);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatbegin(22);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatbegin(30);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatbegin(44);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatbegin(50);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatend(22);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatend(30);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatend(44);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   insertatend(50);
   printf("First %d\n", peekFirst());
   printf("Last %d\n", peekLast());
   printf("Linked List: ");
   // print list
   printList();


   return EXIT_SUCCESS;
}
