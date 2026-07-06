#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TEXT 100

typedef struct {
    char name[MAX_TEXT];
    int value;
} Item;

void removeNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}

void addItem(Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Lista llena.\n");
        return;
    }

    printf("Enter name: ");
    fgets(items[*count].name, MAX_TEXT, stdin);
    removeNewline(items[*count].name);

    printf("Enter value: ");
    scanf("%d", &items[*count].value);
    getchar();

    (*count)++;
    printf("Item added.\n");
}

void viewItems(Item items[], int count) {
    if (count == 0) {
        printf("No items found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d\n", i + 1, items[i].name, items[i].value);
    }
}

int main(void) {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        printf("\n1. Add item\n");
        printf("2. View items\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                viewItems(items, count);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 0);

    return 0;
}