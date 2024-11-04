#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int* arr, int n, int* comparisons) {
    *comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }
        arr[j + 1] = key;
        (*comparisons)++;
    }
}

int readFile(const char* filename, int** arr) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }
    int value;
    int size = 0;
    int capacity = 10;
    *arr = (int*)malloc(capacity * sizeof(int));
    while (fscanf(file, "%d", &value) != EOF) {
        if (size >= capacity) {
            capacity *= 2;
            *arr = (int*)realloc(*arr, capacity * sizeof(int));
        }
        (*arr)[size++] = value;
    }
    fclose(file);
    return size;
}

void writeFile(const char* filename, int* arr, int size) {
    FILE* file = fopen(filename, "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

void displayFileContent(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    int value;
    printf("Sorted content of %s: ", filename);
    while (fscanf(file, "%d", &value) != EOF) {
        printf("%d ", value);
    }
    printf("\n");
    fclose(file);
}

void menu() {
    int choice;
    int* data = NULL;
    int comparisons = 0;
    int size = 0;

    do {
        printf("\nMAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        const char* inputFile;
        const char* outputFile;

        switch (choice) {
            case 1:
                inputFile = "inAsce.dat";
                outputFile = "outInsAsce.dat";
                break;
            case 2:
                inputFile = "inAsce.dat";
                outputFile = "outInsDesc.dat";
                break;
            case 3:
                inputFile = "inAsce.dat";
                outputFile = "outInsRand.dat";
                break;
            case 4:
                printf("Exiting the program.\n");
                free(data);
                return;
            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }

        size = readFile(inputFile, &data);
        if (size > 0) {
            insertionSort(data, size, &comparisons);
            writeFile(outputFile, data, size);
            displayFileContent(outputFile);
            printf("Number of comparisons made: %d\n", comparisons);

            if (choice == 1) {
                if (comparisons == size - 1) {
                    printf("Best Case (Already sorted in ascending order).\n");
                } else {
                    printf("Average Case.\n");
                }
            } else if (choice == 2) {
                printf("Worst Case (Initially sorted in descending order).\n");
            } else {
                printf("Random Case.\n");
            }
        }

    } while (choice != 4);

    free(data);
}

int main() {
    menu();
    return 0;
}

