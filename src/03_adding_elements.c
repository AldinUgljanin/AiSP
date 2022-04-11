#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE;


void add_element(NODE **root, int value){

    NODE *end_node = malloc(sizeof(NODE));
    if(end_node == NULL) exit(2);

    end_node->data = value;
    end_node->next = NULL;

    NODE *temp = *root;
    while(temp->next != NULL){
	temp = temp->next;
    }

    temp->next = end_node;
}

int main(){

    NODE *root = malloc(sizeof(NODE));
    if(root == NULL) exit(1);

    root->data = 10;
    root->next = NULL;

    add_element(&root, 15);
    add_element(&root, 20);
    add_element(&root, 25);

    for(NODE *current = root; current != NULL; current = current->next){
        printf(" Data: %d\n", current->data);
    }
    


    free(root->next->next->next);
    free(root->next->next);
    free(root->next);
    free(root);
    return 0;
}
