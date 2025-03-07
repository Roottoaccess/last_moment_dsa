/* creating the stack data structure using the singly link list */

/* 
    | |
    |5|
    |4| -> Algorithm (insert at front and delete at front)
*/
#include<stdio.h>
#include<stdlib.h>
// Creating the struct node !
typedef struct node{
    int data;
    struct node *next;
}*node;

node insert_node(int data){
    node n = (node) malloc(sizeof(struct node));
    if(n == NULL){
        printf("Memeory alloaction failed !!");
        return NULL;
    }
    n -> data = data;
    n -> next = NULL;
    return n;
}

node push(node n, int data){
    if(n == NULL){
        return insert_node(data);
    }

    // inserting the element in the front !!
    node new_node = insert_node(data);
    new_node -> next = n;
    return new_node;
}

node pop(node n){
    if(n == NULL){
        printf("There is no node present to pop");
    }
    node temp = n;
    printf("The poped element is: %d \n",temp -> data);
    n = n -> next;
    free(temp);
    return n;
}

void display_stack(node n){
    if(n == NULL){
        printf("No node present in the stack !\n");
        return;
    }
    // node temp = n;
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ", n -> data);
        n = n -> next;
    }
    printf("NULL \n");
}

void peek(node n){
    if(n == NULL){
        printf("There is no node present in the stack to show thw peek !\n");
        return;
    }
    printf("Peek -> %d\n", n -> data);
}

int main(void){
    node head = NULL;
    head = insert_node(2);
    head = push(head , 4);
    head = push(head , 6);
    head = push(head , 8);
    display_stack(head);
    head = pop(head);
    display_stack(head);
    peek(head);
    return 0;
}