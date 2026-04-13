#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    bool completed;
} Task;

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // discard extra input
    }
}

int readInt(const char *prompt) {
    int value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1) {
            clearInputBuffer();
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
        clearInputBuffer();
    }
}

void readLine(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void printMenu(void) {
    printf("\n===== TO-DO LIST MENU =====\n");
    printf("1. Add task\n");
    printf("2. View tasks\n");
    printf("3. Mark task as completed\n");
    printf("4. Delete task\n");
    printf("5. Exit\n");
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full. Cannot add more tasks.\n");
        return;
    }

    char title[MAX_TITLE_LENGTH];
    readLine("Enter task title: ", title, sizeof(title));

    if (strlen(title) == 0) {
        printf("Task title cannot be empty.\n");
        return;
    }

    strcpy(tasks[*taskCount].title, title);
    tasks[*taskCount].completed = false;
    (*taskCount)++;

    printf("Task added successfully.\n");
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks in the list.\n");
        return;
    }

    printf("\n===== TASKS =====\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n",
               i + 1,
               tasks[i].completed ? 'X' : ' ',
               tasks[i].title);
    }
}

void markTaskCompleted(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available to mark as completed.\n");
        return;
    }

    viewTasks(tasks, taskCount);

    int taskNumber = readInt("Enter task number to mark as completed: ");

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    if (tasks[taskNumber - 1].completed) {
        printf("Task is already completed.\n");
        return;
    }

    tasks[taskNumber - 1].completed = true;
    printf("Task marked as completed.\n");
}

void deleteTask(Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks available to delete.\n");
        return;
    }

    viewTasks(tasks, *taskCount);

    int taskNumber = readInt("Enter task number to delete: ");

    if (taskNumber < 1 || taskNumber > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    int index = taskNumber - 1;

    for (int i = index; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*taskCount)--;
    printf("Task deleted successfully.\n");
}

int main(void) {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    printf("Welcome to the To-Do List App\n");

    do {
        printMenu();
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                deleteTask(tasks, &taskCount);
                break;
            case 5:
                printf("Exiting program. Goodbye.\n");
                break;
            default:
                printf("Invalid option. Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}