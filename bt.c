// Binary Tree Traversal (Using Linked List): Write a function to perform in-order, pre-order, and post-order traversal on a binary tree represented using a linked list.
#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}*node;

// creating the tree structure....
node creat_tree(){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(struct node));
    if(n == NULL){
        printf("Memory allocation failed....");
        return NULL;
    }
    int x; printf("Enter the root node: ");
    scanf("%d",&x);
    n -> data = x;

    if(x == -1){
        return NULL;
    }

    printf("Enter the left node of %d (Enter -1 for no node): ",n -> data);
    n -> left = creat_tree();
    printf("Enter the right node of %d (Enter -1 for no node): ",n -> data);
    n -> right = creat_tree();

    return n;
}

// creating the inorder traversal....
void inorder_traversal(node n){
    if(n == NULL){
        return;
    }
    // left -> root -> right !!
    inorder_traversal(n -> left);
    printf("%d ", n -> data);
    inorder_traversal(n -> right);
}

// creating the preorder traversal.....
void preorder_traversal(node n){
    if(n == NULL){
        return;
    }
    // root -> left -> right !!
    printf("%d ",n->data);
    preorder_traversal(n -> left);
    preorder_traversal(n -> right);
}

// creating the postorder traversal.....
void postorder_traversal(node n){
    if(n == NULL){
        return;
    }
    // left -> right -> root !!
    postorder_traversal(n -> left);
    postorder_traversal(n -> right);
    printf("%d ",n->data);
}

// creating the main function....
int main(void){
    node root = NULL;
    root = creat_tree();
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("Preorder Traversal: ");
    preorder_traversal(root);
    printf("Postorder Traversal: ");
    postorder_traversal(root);
    return 0;
}