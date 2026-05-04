#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define PHONE_LEN 20

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Contact;

// ---------- Utilities ----------

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// ---------- Core Functions ----------

void addContact(Contact **contacts, int *size) {
    *contacts = realloc(*contacts, (*size + 1) * sizeof(Contact));

    if (*contacts == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter name: ");
    fgets((*contacts)[*size].name, NAME_LEN, stdin);
    removeNewline((*contacts)[*size].name);

    printf("Enter phone: ");
    fgets((*contacts)[*size].phone, PHONE_LEN, stdin);
    removeNewline((*contacts)[*size].phone);

    (*size)++;
    printf("Contact added.\n");
}

void viewContacts(Contact *contacts, int size) {
    if (size == 0) {
        printf("No contacts.\n");
        return;
    }

    printf("\n--- Contacts ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact *contacts, int size) {
    char search[NAME_LEN];

    printf("Enter name to search: ");
    fgets(search, NAME_LEN, stdin);
    removeNewline(search);

    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, search) == 0) {
            printf("Found: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void deleteContact(Contact *contacts, int *size) {
    int index;

    if (*size == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    viewContacts(contacts, *size);

    printf("Enter contact number to delete: ");
    scanf("%d", &index);
    getchar(); // clear newline

    if (index < 1 || index > *size) {
        printf("Invalid index.\n");
        return;
    }

    index--; // convert to 0-based

    for (int i = index; i < *size - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*size)--;
    printf("Contact deleted.\n");
}

// ---------- Menu ----------

void printMenu(void) {
    printf("\n=== Contact Manager ===\n");
    printf("1. Add Contact\n");
    printf("2. View Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

// ---------- Main ----------

int main(void) {
    Contact *contacts = NULL;
    int size = 0;
    int choice;

    do {
        printMenu();
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addContact(&contacts, &size);
                break;
            case 2:
                viewContacts(contacts, size);
                break;
            case 3:
                searchContact(contacts, size);
                break;
            case 4:
                deleteContact(contacts, &size);
                break;
            case 5:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    free(contacts);
    return 0;
}