#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i=start;i<=end;i++) {
        if (inorder[i]==value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart>inEnd)
        return NULL;

    int current=preorder[*preIndex];
    (*preIndex)++;
    struct Node* node=newNode(current);

    if (inStart==inEnd)
        return node;

    int inIndex=search(inorder, inStart, inEnd, current);

    node->left=buildTree(inorder, preorder, inStart, inIndex-1, preIndex);
    node->right=buildTree(inorder, preorder, inIndex+1, inEnd, preIndex);

    return node;
}

void printInorder(struct Node* node) {
    if (node==NULL)
        return;
    printInorder(node->left);
    printf("%d ",node->data);
    printInorder(node->right);
}

void printPreorder(struct Node* node) {
    if (node==NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];
    printf("Enter inorder traversal:\n");
    for (int i=0;i<n;i++)
        scanf("%d", &inorder[i]);

    printf("Enter preorder traversal:\n");
    for (int i=0;i<n;i++)
        scanf("%d", &preorder[i]);

    int preIndex = 0;
    struct Node* root=buildTree(inorder, preorder, 0, n-1, &preIndex);

    printf("Inorder of constructed tree: ");
    printInorder(root);
    printf("\n");

    printf("Preorder of constructed tree: ");
    printPreorder(root);
    printf("\n");

    return 0;
}

