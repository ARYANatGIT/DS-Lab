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

int depth(struct node *root,int key){
    int dep=0;

    while(root!=NULL){
        if(key==root->data){
            return dep;
        }
        else if(key<=root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
        dep++;
    }
    return -1;
}

int main(){
    struct node *root=NULL;
    int opt=1,choice;
    while(opt){
        printf("Press 1 for inserting node , 2 for finding depth of a node: ");
        scanf("%d",&choice);
        switch(choice){
            int data,finddepth;
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
            printf("Enter the data of the node: ");
            scanf("%d",&data);
            finddepth=depth(root,data);
            printf("The depth of %d is %d.",data,finddepth);
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

