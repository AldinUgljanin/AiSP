#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

int main(){
    Node root, next_node;

    root.data = 15;
    root.next = &next_node;

    next_node.data = 10;
    next_node.next = NULL;
    
    printf("First: %d\n", root.data);
    printf("Second: %d\n", next_node.data);

    // arrow dereference pointer
    printf("Second: %d\n", root.next->data);

    // Create new Node using dynamic memory
    next_node.next = malloc(sizeof(Node));

    next_node.next->data = 5;
    next_node.next->next = NULL;
    printf("Third: %d\n", next_node.next->data);
    free(next_node.next);

    return 0;
}
