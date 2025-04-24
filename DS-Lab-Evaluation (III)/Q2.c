#include <stdio.h>

#define SIZE 32

int main() {
    int num, queue[SIZE];
    int front=0,rear=-1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num==0) {
        queue[++rear]=0;
    } else {
        while (num>0) {
            queue[++rear]=num%2;
            num/=2;
        }
    }

    printf("Binary: ");
    for (int i=rear;i>=front;i--) {
        printf("%d", queue[i]);
    }
    printf("\n");

    return 0;
}

