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

    if(value<=root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }

    return root;
}

int height(struct node *root){
    if (root==NULL){
        return 0;
    }

    int leftheight=height(root->left);
    int rightheight=height(root->right);

    return 1+(leftheight > rightheight ? leftheight : rightheight);
}

int main(){
    struct node *root=NULL;
    int opt=1,choice;
    while(opt){
        printf("Press 1 for inserting node, 2 for finding height of binary tree: ");
        scanf("%d",&choice);
        int data,findheight;
        switch(choice){
            case 1:
            if(root==NULL){
                printf("Enter data: ");
                scanf("%d",&data);
                root=insert(root,data);
            }
            else{
                printf("Enter data: ");
                scanf("%d",&data);
                insert(root,data);
            }
            break;
            case 2:
            findheight=height(root);
            printf("The height of the tree is %d.\n",findheight);
            break;
            default:
            printf("Incorrect choice entered!\n");
            break;
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d",&opt);
    }
    return 0;
}

