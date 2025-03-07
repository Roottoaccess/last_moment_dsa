/*

Write a program to Construct a BST
Delete a node
Return inorder traversal
Return inorder successor of a node
Return inorder predecessor of a node

*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*node;

node create_tree(int x){

    if(x == -1){
        return NULL;
    }
    node n = (node) malloc (sizeof(struct node));

    if(n == NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    n -> data = x;
    n -> left = NULL;
    n -> right = NULL;

    return n;
}

node insert_in_bst(node n, int value){
    if(n == NULL){
        return create_tree(value);
    }

    if(value < n -> data){
        n -> left = insert_in_bst(n -> left, value);
    } else if(value > n -> data){
        n -> right = insert_in_bst(n -> right, value);
    } else{
        printf("Duplicate values are not allowed to insert !!");
    }

    return n;
}

void inorder_traversal(node n){
    if(n == NULL){
        return;
    }
    inorder_traversal(n -> left);
    printf("%d ", n -> data);
    inorder_traversal(n -> right);
}

int main(void){
    node root = NULL;
    int value;
    printf("Enter the root node: ");
    scanf("%d",&value);
    root = create_tree(value);

    if(root == NULL){
        printf("Tree is empty !\n");
        return 0;
    }

    while(1){
        printf("Enter the values (Enter -1 to stop): ");
        scanf("%d",&value);
        if(value == -1){
            break;
        }
        root = insert_in_bst(root, value);
    }

    printf("Inorder traversal -> ");
    inorder_traversal(root);
    printf("\n");
}