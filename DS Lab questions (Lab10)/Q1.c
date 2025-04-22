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

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct node *root=NULL;
    int opt=1,choice;
    while(opt){
        printf("Press 1 for inserting node , 2 for inorder traversal, 3 for preorder traversal and 4 for postorder traversal: ");
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
            printf("Inorder traversal:-\n");
            inorder(root);
            printf("\n");
            break;
            case 3:
            printf("Preorder traversal:-\n");
            preorder(root);
            printf("\n");
            break;
            case 4:
            printf("Postorder traversal:-\n");
            postorder(root);
            printf("\n");
            break;
            default:
            printf("Incorrect choice entered!\n");
        }
        printf("Do you want to continue? press 1 for and 0 for no: ");
        scanf("%d",&opt);
    }
    return 0;
}


