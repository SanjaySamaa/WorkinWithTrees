#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
   int data;
   struct node* left;
   struct node* right;
};

struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n-> left = NULL;
    n->right = NULL;
    // printf("%d",(*n).data);
};

void inOrder(struct node* root){
   if(root!=NULL){
    inOrder(root->left);
    printf("%d",root->data);
    inOrder(root->right);
   };
}

int isBst(struct node* root){
    static struct node* prev = NULL;
    if(root!=NULL){
        if(!isBst(root->left)){
            return 0;}
            if(prev!=NULL && root->data <= prev->data){
                return 0;
            }
            prev = root;
            return isBst(root->right);
        }else{
            return 1;
        }
    }


void main(){
    struct node* n1 = createNode(5);
    struct node* n2 = createNode(3);
    struct node* n3 = createNode(6);
    struct node* n4 = createNode(1);
    struct node* n5 = createNode(4);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    inOrder(n1);
    printf("%d",isBst(n1));

}