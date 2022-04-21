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
void affter_element(NODE **root, int element, int value);
void insert_sorted(NODE **root,int value);

// MAIN

int main(){

    NODE *root = NULL;
    
    append_element(&root, 10);
    append_element(&root, 20);
    insert_beginning(&root, 30);
    insert_beginning(&root, 40);

    affter_element(&root, 40, 50);
    affter_element(&root, 20, 25);
    affter_element(&root, 30, 35);

    insert_sorted(&root, 21);
    insert_sorted(&root, 26);

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

void affter_element(NODE **root, int element, int value){

    NODE *new_node = malloc(sizeof(NODE));
    if(new_node == NULL) exit(4);
    new_node->data = value;

    NODE *temp = *root;
    while(temp != NULL){
	if(temp->data == element){
	    new_node->next = temp->next;
	    temp->next = new_node;
	    break;
	}
	temp = temp->next;
    }

}

void insert_sorted(NODE **root,int value){
    NODE *new_node = malloc(sizeof(NODE));
    if(new_node == NULL) exit(5);
    new_node->data = value;
    new_node->next = NULL;

    NODE *temp = *root;
    while(temp != NULL){
	if(new_node->data > temp->data && temp->next == NULL){
	    new_node->next = temp->next;
	    temp->next = new_node;
	    break;
	} else if(new_node->data > temp->data && new_node->data <= temp->next->data){
	    new_node->next = temp->next;
	    temp->next = new_node;
	    break;
	}
	temp = temp->next;
    }
}
