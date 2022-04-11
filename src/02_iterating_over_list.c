#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE;

int main(){
    NODE root;
    root.data = 15;
    root.next = malloc(sizeof(NODE));
    root.next->data = 10;
    root.next->next = malloc(sizeof(NODE));
    root.next->next->data = 5;
    root.next->next->next = NULL;

    NODE *curr = &root;

    printf("\n");

    while(curr != NULL){
	printf(" Data: %d\n", curr->data);
	curr = curr->next;
    }

    printf("\n");

    for(NODE *current = &root; current != NULL; current = current->next){
	printf(" Data: %d\n", current->data);
    }

    printf("\n");

    free(root.next->next);
    free(root.next);
    return 0;
}
