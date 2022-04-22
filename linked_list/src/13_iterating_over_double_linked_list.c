#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *prev;
    struct NODE *next;
} NODE;

int main(){
    NODE *tail = malloc(sizeof(NODE));
    if(tail == NULL) exit(1);

    tail->data = 1;
    tail->prev = NULL;

    tail->next = malloc(sizeof(NODE));
    if(tail->next == NULL) exit(2);

    tail->next->data = 3;
    tail->next->prev = tail;

    tail->next->next = malloc(sizeof(NODE));
    if(tail->next->next == NULL) exit(3);

    NODE *head = tail->next->next;
    head->data = 7;
    head->prev = tail->next;
    head->next = NULL;

    NODE *temp = tail;
    while(temp != NULL){
	printf(" Data: %d\n", temp->data);
	temp = temp->next;
    }

    printf("\n ----------------- \n");
    // Revers

    NODE *curr = head;
    while(curr != NULL){
	printf(" Data: %d\n", curr->data);
	curr = curr->prev;
    }

    free(tail->next->next);
    free(tail->next);
    free(tail);

    return 0;
}
