#include <stdio.h>

#define N 10
int queue[N];
int front = 0;
int end = 0;

void display() {
    if (front == end) {
        printf("\nQueue underflow\n");
    } else {
        for (int i = front; i < end; i++) {
            printf("data : %d\n", queue[i]);
        }
    }
}

void enqueue() {
    if (end == N) {
        printf("\nQueue overflow\n");
    } else {
        int value;
        printf("Enter data to insert: ");
        scanf("%d", &value);
        queue[end++] = value;
    }
}

void dequeue() {
    if (front == end) {
        printf("\nQueue underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
        if (front == end) {
            front = 0;
            end = 0;
        }
    }
}

void main() {
    int run = 1;
    while (run) {
        int choice;
        printf("\nEnter your choice-\n 1. Display\n 2. Enqueue\n 3. Dequeue\n 9. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            display();
        } else if (choice == 2) {
            enqueue();
        } else if (choice == 3) {
            dequeue();
        } else if (choice == 9) {
            printf("Exit successfully...\n");
            run = 0;
        } else {
            printf("Invalid choice.\n");
        }
    }
}
