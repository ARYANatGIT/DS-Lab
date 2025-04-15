
#include <stdio.h>
#include <stdlib.h>

struct patient {
    char name[15];
    int age;
    int waitingNumber;
    struct patient *next;
};

int waitingCounter = 0;

struct patient *head = NULL, *temp = NULL, *tail = NULL;

void giveWatitngNumber () {
    temp = head;
    int counter = 0;
    while (temp != NULL) {
        temp->waitingNumber = counter++;
        temp = temp->next;
    }
    waitingCounter = counter;
}

int registerPatient () {
    struct patient *newPatient = (struct patient *) malloc (sizeof(struct patient));

    if (newPatient == NULL) {
        printf("\nError registering new patient!!\n");
        return -1;
    }

    printf("\nEnter patient's details-\n Patient's name : ");
    scanf("%s", newPatient->name);
    printf("|\n| Patient's age : ");
    scanf("%d", &newPatient->age);

    newPatient->waitingNumber = waitingCounter++;
    newPatient->next = NULL;

    if (head == NULL && tail == NULL) {
        head = newPatient;
        tail = newPatient;
    } else {
        tail->next = newPatient;
        tail = newPatient;
    }

    return 0;
}

int patientCalled () {
    if (head == NULL) {
        printf("\nNo patient to call!!\n");
        return -1;
    }

    temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }

    giveWatitngNumber();
    return 0;
}

int display () {
    if (head == NULL) {
        printf("\nQueue underflow!!\n");
        return -1;
    }

    temp = head;
    while (temp != NULL) {
        printf("\nPatient's details-\n\n Patient's name : %s\n Patient's age : %d\n Patient's waiting number : %d\n", temp->name, temp->age, temp->waitingNumber);
        temp = temp->next;
    }

    return 0;
}

int main () {
    int run = 1;
    while (run) {
        printf("\nEnter choice-\n\n 1. Register new patient\n\n 2. Display all patient(s)\n\n 3. Patient is being called\n\n 9. Exit\n\n\n Enter your choice : ");
        int choice;
        scanf ("%d", &choice);

        if (choice == 1) {
            registerPatient();
        } else if (choice == 2) {
            display();
        } else if (choice == 3) {
            patientCalled();
        } else if (choice == 9) {
            printf("\nExited successfully\n");
            run = 0;
        }
    }

    return 0;
}