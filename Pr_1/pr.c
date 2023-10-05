
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    char surname[50];
    int age;
    struct Person *next;
} Person;

Person* createPerson(char name[], char surname[], int age) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    if (newPerson == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newPerson->name, name);
    strcpy(newPerson->surname, surname);
    newPerson->age = age;
    newPerson->next = NULL;

    return newPerson;
}

void displayList(Person* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List of persons:\n");
    while (head != NULL) {
        printf("Name: %s %s, Age: %d\n", head->name, head->surname, head->age);
        head = head->next;
    }
}

int main() {
    Person* head = NULL;
    Person* tail = NULL;

    char name[50];
    char surname[50];
    int age;
    char choice;

    do {
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter surname: ");
        scanf("%s", surname);
        printf("Enter age: ");
        scanf("%d", &age);

        Person* newPerson = createPerson(name, surname, age);

        if (head == NULL) {
            head = newPerson;
            tail = newPerson;
        } else {
            tail->next = newPerson;
            tail = newPerson;
        }

        printf("Do you want to add another person? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Display menu
    printf("\nMenu:\n");
    printf("1. Press </> to see all list\n");

    // Handle user choice
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);
    if (choice == '/') {
        displayList(head);
    } else {
        printf("Invalid choice.\n");
    }

    // Free allocated memory for the list
    while (head != NULL) {
        Person* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

