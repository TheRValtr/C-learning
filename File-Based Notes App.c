#include <stdio.h>
#include <string.h>

#define NOTE_FILE "notes.txt"
#define MAX_NOTE_LENGTH 500

void removeNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}

void addNote(void) {
    char note[MAX_NOTE_LENGTH];

    FILE *file = fopen(NOTE_FILE, "a");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Enter your note: ");
    fgets(note, sizeof(note), stdin);
    removeNewline(note);

    if (strlen(note) == 0) {
        printf("Note cannot be empty.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%s\n", note);
    fclose(file);

    printf("Note saved successfully.\n");
}

void viewNotes(void) {
    char line[MAX_NOTE_LENGTH];
    int noteNumber = 1;

    FILE *file = fopen(NOTE_FILE, "r");

    if (file == NULL) {
        printf("No notes found.\n");
        return;
    }

    printf("\n===== SAVED NOTES =====\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d. %s", noteNumber, line);
        noteNumber++;
    }

    fclose(file);

    if (noteNumber == 1) {
        printf("No notes found.\n");
    }
}

void clearNotes(void) {
    FILE *file = fopen(NOTE_FILE, "w");

    if (file == NULL) {
        printf("Error: Could not clear notes.\n");
        return;
    }

    fclose(file);
    printf("All notes cleared.\n");
}

void clearInputBuffer(void) {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        // discard input
    }
}

int readChoice(void) {
    int choice;

    printf("Choose an option: ");

    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();
        return -1;
    }

    clearInputBuffer();
    return choice;
}

void printMenu(void) {
    printf("\n===== NOTES APP =====\n");
    printf("1. Add note\n");
    printf("2. View notes\n");
    printf("3. Clear notes\n");
    printf("4. Exit\n");
}

int main(void) {
    int choice;

    do {
        printMenu();
        choice = readChoice();

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                clearNotes();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }

    } while (choice != 4);

    return 0;
}