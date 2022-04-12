#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE;

void add_element(NODE **root, int value);

int main(){
    NODE *root = malloc(sizeof(NODE));
    if(root == NULL) exit(1);

    root->next = NULL;
    root->data = 10;
    add_element(&root, -2);
    add_element(&root, 2);
    add_element(&root, 4);

    for(NODE *temp = root; temp != NULL; temp = temp->next){
	printf("%d\n", temp->data);
    }
    printf("%d\n", root->next->next->next->data);

    free(root->next->next->next);
    free(root->next->next);
    free(root->next);
    free(root);

    return 0;
}

void add_element(NODE **root, int value){
    NODE *new_node = malloc(sizeof(NODE));
    if(new_node == NULL) exit(2);

    new_node->next = NULL;
    new_node->data = value;

    if(*root == NULL){
	*root = new_node;
	return;
    }

    NODE *curr = *root;
    while(curr->next != NULL) curr = curr->next;
    curr->next = new_node;
} 
