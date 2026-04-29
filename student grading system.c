#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

void removeNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}

void addStudent(Student students[], int *studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter student name: ");
    fgets(students[*studentCount].name, MAX_NAME_LENGTH, stdin);
    removeNewline(students[*studentCount].name);

    printf("Enter grade: ");
    scanf("%f", &students[*studentCount].grade);
    getchar(); // clears leftover newline

    (*studentCount)++;

    printf("Student added successfully.\n");
}

void viewStudents(Student students[], int studentCount) {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n===== STUDENTS =====\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%d. Name: %s | Grade: %.2f\n",
               i + 1,
               students[i].name,
               students[i].grade);
    }
}

float calculateAverage(Student students[], int studentCount) {
    float total = 0;

    if (studentCount == 0) {
        return 0;
    }

    for (int i = 0; i < studentCount; i++) {
        total += students[i].grade;
    }

    return total / studentCount;
}

void showHighestGrade(Student students[], int studentCount) {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    int highestIndex = 0;

    for (int i = 1; i < studentCount; i++) {
        if (students[i].grade > students[highestIndex].grade) {
            highestIndex = i;
        }
    }

    printf("Highest grade: %s with %.2f\n",
           students[highestIndex].name,
           students[highestIndex].grade);
}

void printMenu(void) {
    printf("\n===== STUDENT GRADE SYSTEM =====\n");
    printf("1. Add student\n");
    printf("2. View students\n");
    printf("3. Show average grade\n");
    printf("4. Show highest grade\n");
    printf("5. Exit\n");
}

int main(void) {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printMenu();

        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clears leftover newline

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                viewStudents(students, studentCount);
                break;

            case 3:
                printf("Average grade: %.2f\n",
                       calculateAverage(students, studentCount));
                break;

            case 4:
                showHighestGrade(students, studentCount);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option.\n");
        }

    } while (choice != 5);

    return 0;
}