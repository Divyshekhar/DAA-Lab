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

void insertMinHeap(struct pair arr[], int *N, struct pair newPair) {
    arr[*N] = newPair;
    int i = *N;
    (*N)++;

    while (i && arr[(i - 1) / 2].weight > arr[i].weight) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct pair extractMin(struct pair arr[], int *N) {
    struct pair min = arr[0];
    arr[0] = arr[*N - 1];
    (*N)--;
    minheapify(arr, *N, 0);
    return min;
}

int main() {
    FILE *ptr;
    int n = 0, c = 0;
    
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    int ar[n][n];
    int out[n][n];
    int visited[n];
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    struct pair *heap = (struct pair *)malloc(n * n * sizeof(struct pair));

    ptr = fopen("read.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(ptr, "%d", &ar[i][j]);
            out[i][j] = 0;
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

    int heapSize = 0;
    struct pair start = { -1, 0, 0 };
    insertMinHeap(heap, &heapSize, start);
    
    int sum = 0;

    while (heapSize > 0) {
        struct pair minEdge = extractMin(heap, &heapSize);
        int par = minEdge.parent;
        int chi = minEdge.child;
        int wt = minEdge.weight;

        if (visited[chi])
            continue;

        visited[chi] = 1;
        sum += wt;
        
        if (par != -1) {
            out[chi][par] = wt;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] != 1 && ar[chi][i] != 0) {
                struct pair newEdge = { chi, i, ar[chi][i] };
                insertMinHeap(heap, &heapSize, newEdge);
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
