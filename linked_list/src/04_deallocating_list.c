#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data; 
    struct NODE *next;
} NODE;

void append_element(NODE **root, int value);

void deallocate(NODE **root);

int main(){

    NODE *root = NULL;
    
    append_element(&root, 10);
    append_element(&root, 20);

    printf(" Data: %d\n", root->data);
    printf(" Data: %d\n", root->next->data);

    deallocate(&root);
    return 0;

}

void append_element(NODE **root, int value){

    NODE *new_node = malloc(sizeof(NODE));
    if(new_node == NULL) exit(1);

    new_node->data = value;
    new_node->next = NULL;

    if(*root == NULL){
	*root = new_node;
	return;
    }

    NODE *temp = *root;
    while(temp->next != NULL) temp = temp->next;
    temp->next = new_node;
}

void deallocate(NODE **root){

    NODE *temp = *root;
    while(temp != NULL){
	// this node copy temp node
	NODE *paraller = temp;
	// this node move to next node
	temp = temp->next;
	// deallocate current node
	free(paraller);
    }
    *root = NULL;

}
