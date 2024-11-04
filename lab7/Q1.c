#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

int minDistance(int dist[], int visited[], int n);
void printPath(int parent[], int j);
void printSolution(int dist[], int n, int parent[], int src);

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index = -1;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("->%d", j + 1); 
}

void printSolution(int dist[], int n, int parent[], int src)
{
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t", src + 1, i + 1);
        if (dist[i] == INF)
        {
            printf("INF\t-");
        }
        else
        {
            printf("%d\t%d", dist[i], src + 1);
            if (i != src) 
                printPath(parent, i);
        }
        printf("\n");
    }
}

void dijkstra(int graph[100][100], int src, int n)
{
    int dist[n];    
    int visited[n]; 
    int parent[n];  

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1; 
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n);

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; 
            }
        }
    }
    
    printSolution(dist, n, parent, src);
}

int main()
{
    int n, src;
    int graph[100][100];
    FILE *file = fopen("str3.txt", "r");

    if (file == NULL)
    {
        printf("Error: Cannot open file\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(file, "%d", &graph[i][j]);

    fclose(file);

    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    src--; 

    dijkstra(graph, src, n);

    return 0;
}
