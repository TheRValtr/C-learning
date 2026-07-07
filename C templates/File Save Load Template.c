#include <stdio.h>
#define FILE_NAME "data.txt"
#define MAX_LINE 256

void saveData(void) {
    FILE *file = fopen(FILE_NAME, "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Example saved data\n");

    fclose(file);
    printf("Data saved.\n");
}

void loadData(void) {
    FILE *file = fopen(FILE_NAME, "r");
    char line[MAX_LINE];

    if (file == NULL) {
        printf("No file found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

int main(void) {
    saveData();
    loadData();

    return 0;
}