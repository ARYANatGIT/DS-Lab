#include <stdio.h>

void printqueue(int queue[], int top, int tail, int len);

void enqueue(int queue[], int *top, int *tail, int len) {
    if ((*tail+1)%len==*top) {
        printf("Queue is full!\n");
        return;
    }

    printf("Enter the data: ");
    int data;
    scanf("%d", &data);

    if (*top==-1 && *tail==-1) {
        *top=*tail=0;
    } else {
        *tail=(*tail+1)%len;
    }

    queue[*tail]=data;
    printqueue(queue, *top, *tail, len);
}

void dequeue(int queue[], int *top, int *tail, int len) {
    if (*top == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("The data getting dequeued is %d.\n", queue[*top]);

    if (*top==*tail) {
        *top=-1;
        *tail=-1;
    } else {
        *top=(*top+1)%len;
    }

    printqueue(queue, *top, *tail, len);
}

void printqueue(int queue[], int top, int tail, int len) {
    if (top==-1){
        printf("Queue is empty!\n");
        return;
    }
    int i=top;
    while (i!=tail) {
        printf("%d ",queue[i]);
        i = (i+1)%len;
    }
    printf("%d\n",queue[tail]);
}

int main() {
    int len;
    printf("Enter the length of the queue: ");
    scanf("%d", &len);
    int queue[len];
    int top=-1, tail=-1;
    int i=1;
    while (i) {
        int opt;
        printf("For performing enqueue press 1, for dequeue press 2, and for displaying the data press 3: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                enqueue(queue, &top, &tail, len);
                break;
            case 2:
                dequeue(queue, &top, &tail, len);
                break;
            case 3:
                printqueue(queue, top, tail, len);
                break;
            default:
                printf("Incorrect choice entered!\n");
        }

        printf("Do you want to continue? Press 1 for yes and 0 for no: ");
        scanf("%d",&i);
    }
    return 0;
}