#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE;

void append_element(NODE **root, int value);

void deallocate(NODE **root);

void print_list(NODE **root);

void insert_beginning(NODE **root,int value);

// MAIN

int main(){

    NODE *root = NULL;
    
    append_element(&root, 10);
    append_element(&root, 20);

    insert_beginning(&root, 30);
    insert_beginning(&root, 40);

    print_list(&root);

    deallocate(&root);

    return 0;

}

// Functions

void append_element(NODE **root, int value){

    NODE *end_node = malloc(sizeof(NODE));
    if(end_node == NULL) exit(1);

    end_node->data = value;
    end_node->next = NULL;

    if(*root == NULL){
	*root = end_node;
	return;
    }

    NODE *temp = *root;
    while(temp->next != NULL) temp = temp->next;
    temp->next = end_node;
}

void deallocate(NODE **root){

    NODE *temp = *root;
    while(temp != NULL){
	NODE *aux = temp;
	temp = temp->next;
	free(aux);
    }
    *root = NULL;

}

void print_list(NODE **root){

    for(NODE *temp = *root; temp != NULL; temp = temp->next){
	printf(" Data: %d\n", temp->data);
    }

}

void insert_beginning(NODE **root,int value){
    NODE *new_node = malloc(sizeof(NODE));
    if(new_node == NULL) exit(3);

    new_node->data = value;
    new_node->next = *root;

    *root = new_node;
}
