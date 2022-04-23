#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *prev;
    struct NODE *next;
} NODE;

void free_memory(NODE **tail, NODE **head);

int main(){
    NODE *tail = malloc(sizeof(NODE));
    if(tail == NULL) exit(1);

    tail->data = 1;
    tail->prev = NULL;

    tail->next = malloc(sizeof(NODE));
    tail->next->data = 3;
    tail->next->prev = tail;

    tail->next->next = malloc(sizeof(NODE));
    tail->next->next->data = 7;
    tail->next->next->prev = tail->next;
    tail->next->next->next = NULL;
    NODE *head = tail->next->next;

    NODE *temp = head;
    while(temp != NULL){
	printf(" Data: %d\n", temp->data);
	temp = temp->prev;
    }

    free_memory(&tail, &head);
    
    return 0;
}

void free_memory(NODE **tail, NODE **head){
    if(*tail == NULL) return;

    NODE *temp = *tail;
    while(temp->next != NULL){
	temp = temp->next;
	free(temp->prev);
    }

    free(temp);

    *tail = NULL;
    *head = NULL;
}
