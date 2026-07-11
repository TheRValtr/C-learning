int *numbers = malloc(4 * sizeof(int));

if (numbers == NULL) {
    return 1;
}

numbers[0] = 10;
numbers[1] = 20;

free(numbers);
return 0;