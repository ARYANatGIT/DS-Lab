#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp = NULL, *tail = NULL;

int enqueue () {
    struct node *nnode = (struct node *) malloc (sizeof(struct node));

    if (nnode == NULL) {
        printf("\nError registering new node!!\n");
        return -1;
    }

    printf("\nEnter data : ");
    scanf("%d", &nnode->data);

    nnode->next = NULL;

    if (head == NULL && tail == NULL) {
        head = nnode;
        tail = nnode;
    } else {
        tail->next = nnode;
        tail = nnode;
    }

    return 0;
}

int dequeue () {
    if (head == NULL) {
        printf("\nUnderflow condition\n");
        return -1;
    }

    temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }
    return 0;
}

int display () {
    if (head == NULL) {
        printf("\nQueue underflow!!\n");
        return -1;
    }

    temp = head;
    while (temp != NULL) {
        printf("\nData : %d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}

int main () {
    int run = 1;
    while (run) {
        printf("\nEnter choice-\n|\n| 1. Enqueue\n|\n| 2. Display all node(s)\n|\n| 3. Dequeue\n|\n| 9. Exit\n|\n|\n|| Enter your choice : ");
        int choice;
        scanf ("%d", &choice);

        if (choice == 1) {
            enqueue();
        } else if (choice == 2) {
            display();
        } else if (choice == 3) {
            dequeue();
        } else if (choice == 9) {
            printf("\nExited successfully\n");
            run = 0;
        }
    }

    return 0;
}