#include <stdio.h>
#include <limits.h>
#include<stdlib.h>

#define INF INT_MAX

typedef struct
{
        int vertex;
        int weight;
} Edge;

typedef struct
{
        int numVertices;
        Edge *edges;
} Graph;

typedef struct
{
        int numVertices;
        int *parent;
        int *key;
        int *inMST;
} PriorityQueue;

void printMatrix(int **matrix, int numVertices)
{
        for (int i = 0; i < numVertices; i++)
        {
                for (int j = 0; j < numVertices; j++)
                {
                        printf("%d ", matrix[i][j]);
                }
                printf("\n");
        }
}

void primMST(Graph *graph, int startVertex, int **mstMatrix, int *totalWeight)
{
        int numVertices = graph->numVertices;
        PriorityQueue queue;
        queue.numVertices = numVertices;
        queue.parent = (int *)malloc(numVertices * sizeof(int));
        queue.key = (int *)malloc(numVertices * sizeof(int));
        queue.inMST = (int *)malloc(numVertices * sizeof(int));

        for (int i = 0; i < numVertices; i++)
        {
                queue.key[i] = INF;
                queue.inMST[i] = 0;
        }

        queue.key[startVertex - 1] = 0;
        queue.parent[startVertex - 1] = -1;

        for (int i = 0; i < numVertices - 1; i++)
        {
                int minKey = INF;
                int minIndex = -1;
                for (int j = 0; j < numVertices; j++)
                {
                        if (!queue.inMST[j] && queue.key[j] < minKey)
                        {
                                minKey = queue.key[j];
                                minIndex = j;
                        }
                }

                queue.inMST[minIndex] = 1;

                for (int j = 0; j < numVertices; j++)
                {
                        if (!queue.inMST[j] && graph->edges[minIndex * numVertices + j].weight != 0 &&
                            queue.key[j] > graph->edges[minIndex * numVertices + j].weight)
                        {
                                queue.key[j] = graph->edges[minIndex * numVertices + j].weight;
                                queue.parent[j] = minIndex + 1;
                        }
                }
        }

        *totalWeight = 0;
        for (int i = 0; i < numVertices; i++)
        {
                if (queue.parent[i] != -1)
                {
                        mstMatrix[queue.parent[i] - 1][i] = queue.key[i];
                        mstMatrix[i][queue.parent[i] - 1] = queue.key[i];
                        *totalWeight += queue.key[i];
                }
        }
}

int main()
{
        int numVertices;
        printf("Enter the Number of Vertices: ");
        scanf("%d", &numVertices);

        int startVertex;
        printf("Enter the Starting Vertex: ");
        scanf("%d", &startVertex);

        Graph graph;
        graph.numVertices = numVertices;
        graph.edges = (Edge *)malloc(numVertices * numVertices * sizeof(Edge));

        FILE *file = fopen("text.txt", "r");
        for (int i = 0; i < numVertices; i++)
        {
                for (int j = 0; j < numVertices; j++)
                {
                        fscanf(file, "%d", &graph.edges[i * numVertices + j].weight);
                        graph.edges[i * numVertices + j].vertex = j + 1;
                }
        }
        fclose(file);

        int *mstMatrix = (int *)malloc(numVertices * sizeof(int *));
        for (int i = 0; i < numVertices; i++)
        {
                mstMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        }

        int totalWeight;
        primMST(&graph, startVertex, mstMatrix, &totalWeight);

        printf("Minimum Spanning Tree:\n");
        printMatrix(mstMatrix, numVertices);
        printf("Total Weight of the Spanning Tree: %d\n", totalWeight);

        return 0;
}