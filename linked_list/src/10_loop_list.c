#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
} NODE;

int has_loops(NODE *root);
void reverse(NODE **root);
void deallocate(NODE **root);
void print_list(NODE **root);

void append_element(NODE **root,int value);
void insert_beginning(NODE **root,int value);
void affter_element(NODE **root, int element, int value);
void insert_sorted(NODE **root,int value);
void remove_element(NODE **root,int value);


// MAIN

int main(){

    NODE *root = NULL;
    
    append_element(&root, 30);
    append_element(&root, 40);

    insert_beginning(&root, 20);
    insert_beginning(&root, 10);

    affter_element(&root, 40, 50);
    affter_element(&root, 20, 25);
    affter_element(&root, 30, 35);

    insert_sorted(&root, 51);
    insert_sorted(&root, 26);

    remove_element(&root, 10);
    remove_element(&root, 20);

    reverse(&root);

    if(has_loops(root) == 1){
	printf("Linked list has a loop\n");
	return 1;
    }

    print_list(&root);

    deallocate(&root);

    return 0;
}

// Functions

void append_element(NODE **root,int value){

    NODE *end_node = malloc(sizeof(NODE));
    if(end_node == NULL) exit(1);

    end_node->data = value;
    end_node->next = NULL;

    if(*root == NULL) {
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
    new_node->next = NULL;

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
    if(*root == NULL || (*root)->data >= value) {
	insert_beginning(root, value);
	return;
    }

    NODE *temp = *root;
    while(temp->next != NULL){
	if(temp->next->data >= value) break;
	temp = temp->next;
    }

    affter_element(root, temp->data, value);
}

void remove_element(NODE **root,int value){
    if(*root == NULL) return;

    if((*root)->data == value){
	NODE *to_remove = *root;
	*root = (*root)->next;
	free(to_remove);
	return;
    }

    for(NODE *temp = *root; temp->next != NULL; temp = temp->next){
	if(temp->next->data == value){
	    NODE *to_remove = temp->next;
	    temp->next = temp->next->next;
	    free(to_remove);
	    return;
	}
    }
}

void reverse(NODE **root){
    NODE *prev = NULL;
    NODE *curr = *root;

    while(curr != NULL){
	NODE *next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    *root = prev;
}

int has_loops(NODE *root){
    NODE *slow = root;
    NODE *fast = root;

    while(slow != NULL && fast != NULL && fast->next != NULL){
	slow = slow->next;
	fast = fast->next->next;

	if(slow == fast) return 1;
    }
}
