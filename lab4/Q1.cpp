#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[100];
    int age;
    int height;
    int weight;
};

void displayMenu() {
    printf("\nMAIN MENU (HEAP)\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on the age\n");
    printf("3. Create a Max-heap based on the weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Insert a new person into the Min-heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");
}

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct person *heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].age < heap[smallest].age)
        smallest = left;
    if (right < n && heap[right].age < heap[smallest].age)
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void maxHeapify(struct person *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].weight > heap[largest].weight)
        largest = left;
    if (right < n && heap[right].weight > heap[largest].weight)
        largest = right;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

void readData(struct person **people, int *n) {
    FILE *file;
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Could not open file data.txt\n");
        return;
    }
    fscanf(file, "%d", n);
    *people = (struct person *)malloc(*n * sizeof(struct person));
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %s %d %d %d", &(*people)[i].id, (*people)[i].name, &(*people)[i].age, &(*people)[i].height, &(*people)[i].weight);
    }
    fclose(file);
    printf("Data successfully read from file.\n");
}

void displayPeople(struct person *people, int n) {
    if (n == 0) {
        printf("No data available.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Person %d: ID=%d, Name=%s, Age=%d, Height=%d, Weight=%d\n", 
                i + 1, people[i].id, people[i].name, people[i].age, people[i].height, people[i].weight);
    }
}

void createMinHeap(struct person *people, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(people, n, i);
    }
    printf("Min-heap created based on age.\n");
    displayPeople(people, n);


}

void createMaxHeap(struct person *people, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(people, n, i);
    }
    printf("Max-heap created based on weight.\n");
    displayPeople(people, n);

}

void displayWeightOfYoungest(struct person *people, int n) {
    if (n == 0) {
        printf("No data available.\n");
        return;
    }
    createMinHeap(people, n);
    printf("Weight of the youngest person: %d\n", people[0].weight);
}

void insertPersonMinHeap(struct person **people, int *n) {
    struct person newPerson;
    printf("Enter id, name, age, height, and weight: ");
    scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);

    *people = (struct person *)realloc(*people, (*n + 1) * sizeof(struct person));
    (*people)[*n] = newPerson;
    (*n)++;
    for (int i = *n / 2 - 1; i >= 0; i--) {
        minHeapify(*people, *n, i);
    }

    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Could not open file data.txt\n");
        return;
    }
    fprintf(file, "%d\n", *n);
    for (int i = 0; i < *n; i++) {
        fprintf(file, "%d %s %d %d %d\n", (*people)[i].id, (*people)[i].name, (*people)[i].age, (*people)[i].height, (*people)[i].weight);
    }
    fclose(file);
    printf("Person inserted into min-heap and written to file.\n");
}

void deleteOldestPerson(struct person **people, int *n) {
    if (*n == 0) {
        printf("No data available.\n");
        return;
    }
    createMaxHeap(*people, *n);
    printf("Deleting person with id %d, name %s, age %d, height %d, weight %d\n",
           (*people)[0].id, (*people)[0].name, (*people)[0].age, (*people)[0].height, (*people)[0].weight);
    (*people)[0] = (*people)[*n - 1];
    (*people) = (struct person *)realloc(*people, (*n - 1) * sizeof(struct person));
    (*n)--;
    maxHeapify(*people, *n, 0);
    printf("Oldest person deleted.\n");
}

int main() {
    struct person *people = NULL;
    int n = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readData(&people, &n);
                displayPeople(people, n);
                break;
            case 2:
                createMinHeap(people, n);
                break;
            case 3:
                createMaxHeap(people, n);
                break;
            case 4:
                displayWeightOfYoungest(people, n);
                break;
            case 5:
                insertPersonMinHeap(&people, &n);
                break;
            case 6:
                deleteOldestPerson(&people, &n);
                break;
            case 7:
                free(people);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
