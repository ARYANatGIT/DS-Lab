#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createnode(int value){
    struct node *nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=value;
    nnode->left=NULL;
    nnode->right=NULL;
    return nnode;
}

struct node *insert(struct node *root,int value){
    if(root==NULL){
        return createnode(value);
    }

    if(value<root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }

    return root;
}

void countnodes(struct node *root,int *leafcount,int *internalcount){
    if (root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        (*leafcount)++;
    }else{
        (*internalcount)++;
    }
    countnodes(root->left,leafcount,internalcount);
    countnodes(root->right,leafcount,internalcount);
}

int main(){
    struct node *root=NULL;
    int opt=1,choice,leafcount=0,internalcount=0;
    while(opt){
        printf("Press 1 for inserting node , 2 for finding number of leaf nodes and internal nodes in the search tree: ");
        scanf("%d",&choice);
        switch(choice){
            int data;
            case 1:
            if(root==NULL){
                printf("Enter data: ");
                scanf("%d",&data);
                root=insert(root,data);
            }else{
                printf("Enter data: ");
                scanf("%d",&data);
                insert(root,data);
            }
            break;
            case 2:
            countnodes(root,&leafcount,&internalcount);
            printf("The number of leaf nodes and internal nodes are %d and %d respectively.\n,",leafcount,internalcount);
            break;
            default:
            printf("Incorrect choice entered!\n");
        }
        printf("Do you want to continue? press 1 for and 0 for no: ");
        scanf("%d",&opt);
    }
    return 0;
}

