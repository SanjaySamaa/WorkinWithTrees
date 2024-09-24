#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n;
    n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n-> left = NULL;
    n-> right = NULL;
    return n;
}

void preOrderTraversal(struct node* root){
    if(root!=NULL){
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    }
}

void main(){
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(6);
    struct node *p4 = createNode(5);
    struct node *p5 = createNode(2);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    preOrderTraversal(p1);
}