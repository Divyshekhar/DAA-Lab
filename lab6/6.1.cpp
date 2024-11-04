#include <stdio.h>
#include <stdlib.h>

struct pair {
    int parent;
    int child;
    int weight;   
};

void swap(struct pair *a, struct pair *b) {
    struct pair tmp = *a;
    *a = *b;
    *b = tmp;
}

void minheapify(struct pair arr[], int N, int i) {
    int min = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < N && arr[l].weight < arr[min].weight)
        min = l;
    if (r < N && arr[r].weight < arr[min].weight)
        min = r;
    
    if (min != i) {
        swap(&arr[i], &arr[min]);
        minheapify(arr, N, min);
    }
}

void buildminHeap(struct pair arr[], int N) {
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        minheapify(arr, N, i);
    }
}

int main() {
    FILE *ptr;
    int n = 0, c = 0;
    
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    int ar[n][n];
    int out[n][n];
    int visited[n];
    
    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Dynamically allocate the heap array with correct size
    struct pair *heap = (struct pair *)malloc(n * n * sizeof(struct pair));

    ptr = fopen("read.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(ptr, "%d", &ar[i][j]);
            out[i][j] = 0; // Initialize output matrix to 0
        }
    }
    fclose(ptr);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }

    heap[c].child = 0;
    heap[c].weight = 0;
    heap[c].parent = -1;
    c++;
    
    int sum = 0;

    while (c > 0) {
        c--; // Decrement c to point to the last element
        int par = heap[c].parent;
        int chi = heap[c].child;
        int wt = heap[c].weight;

        if (visited[chi] == 1)
            continue;

        visited[chi] = 1;
        sum += wt;
        //ar[chi][par]=0;
        
        if (par != -1) {
            out[chi][par] = wt;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] != 1 && ar[chi][i] != 0) {
                heap[c].child = i;
                heap[c].parent = chi;
                heap[c].weight = ar[chi][i];
                c++;
                buildminHeap(heap, c);
            }
        }
    }

    printf("Minimum Spanning Tree (MST) edges with their weights:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (out[i][j] != 0) {
                printf("%d - %d: %d\n", j, i, out[i][j]);
            }
        }
    }
    
    printf("Total Cost: %d\n", sum);
    free(heap);
    
    return 0;
}

