#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define PHONE_LEN 20

typedef struct Node {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    struct Node *next;
} Node;

void removeNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}

Node *createNode(void) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter name: ");
    fgets(newNode->name, NAME_LEN, stdin);
    removeNewline(newNode->name);

    printf("Enter phone: ");
    fgets(newNode->phone, PHONE_LEN, stdin);
    removeNewline(newNode->phone);

    newNode->next = NULL;

    return newNode;
}

void addContact(Node **head) {
    Node *newNode = createNode();

    if (*head == NULL) {
        *head = newNode;
        printf("Contact added.\n");
        return;
    }

    Node *current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    printf("Contact added.\n");
}

void viewContacts(Node *head) {
    if (head == NULL) {
        printf("No contacts found.\n");
        return;
    }

    int count = 1;
    Node *current = head;

    printf("\n===== CONTACTS =====\n");

    while (current != NULL) {
        printf("%d. %s - %s\n", count, current->name, current->phone);
        current = current->next;
        count++;
    }
}

void searchContact(Node *head) {
    char searchName[NAME_LEN];

    printf("Enter name to search: ");
    fgets(searchName, NAME_LEN, stdin);
    removeNewline(searchName);

    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->name, searchName) == 0) {
            printf("Found: %s - %s\n", current->name, current->phone);
            return;
        }

        current = current->next;
    }

    printf("Contact not found.\n");
}

void deleteContact(Node **head) {
    char nameToDelete[NAME_LEN];

    if (*head == NULL) {
        printf("No contacts to delete.\n");
        return;
    }

    printf("Enter name to delete: ");
    fgets(nameToDelete, NAME_LEN, stdin);
    removeNewline(nameToDelete);

    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->name, nameToDelete) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Contact deleted.\n");
}

void freeList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void printMenu(void) {
    printf("\n===== LINKED LIST CONTACT MANAGER =====\n");
    printf("1. Add contact\n");
    printf("2. View contacts\n");
    printf("3. Search contact\n");
    printf("4. Delete contact\n");
    printf("5. Exit\n");
}

int main(void) {
    Node *head = NULL;
    int choice;

    do {
        printMenu();

        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addContact(&head);
                break;
            case 2:
                viewContacts(head);
                break;
            case 3:
                searchContact(head);
                break;
            case 4:
                deleteContact(&head);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 5);

    freeList(head);

    return 0;
}