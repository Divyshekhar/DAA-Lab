#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct person {
    int id;
    char name[100];
    int age;
    int height;
    int weight;
};
void swap(struct person *a, struct person *b) {
    struct person tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxheapify(struct person arr[], int N, int i) {
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l].weight > arr[largest].weight)
        largest = l;
    if (r < N && arr[r].weight > arr[largest].weight)
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, N, largest);
    }
}

void buildmaxHeap(struct person arr[], int N) {
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        maxheapify(arr, N, i);
    }
}

void minheapify(struct person arr[], int N, int i) {
    int min = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l].age < arr[min].age)
        min = l;
    if (r < N && arr[r].age < arr[min].age)
        min = r;
    if (min != i) {
        swap(&arr[i], &arr[min]);
        minheapify(arr, N, min);
    }
}

void buildminHeap(struct person arr[], int N) {
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        minheapify(arr, N, i);
    }
}
void deleteOldest(struct person arr[], int *N) 
{
   if (*N <= 0) {
        printf("Heap is empty\n");
        return;
    }
    int maxIdx = 0;
    for (int i = 1; i < *N; i++) {
        if (arr[i].age > arr[maxIdx].age) {
            maxIdx = i;
        }
    }
    arr[maxIdx] = arr[--(*N)];
    buildminHeap(arr, *N);
}
int main() {
    FILE *ptr;
    int ch = 1;
    struct person persons[100];
    struct person minheap[100];
    struct person maxheap[100];
    int c = 0;
    while (ch) {
        printf("MAIN MENU (HEAP)\n1. Read Data\n2. Create a Min-heap based on the age\n3. Create a Max-heap based on the weight\n4. Display weight of the youngest person\n5. Insert a new person into the Min-heap\n6. Delete the oldest person\n7. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                ptr = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 4\\Data.txt", "r");
                char line[150];
                c=0;

                while (fgets(line, sizeof(line), ptr)) {
                    sscanf(line, "%d %[^0-9] %d %d %d", &persons[c].id, persons[c].name, &persons[c].age, &persons[c].height, &persons[c].weight);
                    c++;
                }

                fclose(ptr);

				printf("Id\t Name\t        Age  Height  Weight\n");
                for (int i = 0; i < c; i++) {
                    printf("%d\t%s\t%d\t%d\t%d \n", persons[i].id, persons[i].name, persons[i].age, persons[i].height, persons[i].weight);
                }
                break;
            }
            case 2: 
			{
				for(int i=0;i<c;i++)
				minheap[i]=persons[i];
				buildminHeap(minheap,c);
				printf("Id\t Name\t        Age  Height  Weight\n");
                for (int i = 0; i < c; i++) {
                    printf("%d\t%s\t%d\t%d\t%d \n", minheap[i].id, minheap[i].name, minheap[i].age, minheap[i].height, minheap[i].weight);
                }
                break;
            }
            case 3: {
				for(int i=0;i<c;i++)
				maxheap[i]=persons[i];
				buildmaxHeap(maxheap,c);
				printf("Id\t Name\t        Age  Height  Weight\n");
                for (int i = 0; i < c; i++) {
                    printf("%d\t%s\t%d\t%d\t%d \n", maxheap[i].id, maxheap[i].name, maxheap[i].age, maxheap[i].height, maxheap[i].weight);
                }
                break;
            }
            case 4: {
                printf("Weight of youngest : %d \n",minheap[0].weight);
                break;
            }
            case 5: {
                printf("Enter Id Name Age Height Weight of person");
                scanf("%d%[^0-9]%d%d%d",&minheap[c].id,minheap[c].name,&minheap[c].age,&minheap[c].height,&minheap[c].weight);
                c++;
                buildminHeap(minheap,c);
				printf("Id\t Name\t        Age  Height  Weight\n");
                for (int i = 0; i < c; i++) {
                    printf("%d\t%s\t%d\t%d\t%d \n", minheap[i].id, minheap[i].name, minheap[i].age, minheap[i].height, minheap[i].weight);
                }
                break;
            }
            case 6: 
			{
				deleteOldest(minheap, &c);
                printf("Oldest person deleted successfully!\n");
                printf("Id\t Name\t        Age  Height  Weight\n");
                for (int i = 0; i < c; i++) {
                    printf("%d\t%s\t%d\t%d\t%d \n", minheap[i].id, minheap[i].name, minheap[i].age, minheap[i].height, minheap[i].weight);
                }
                break;
            }
            case 7: {
                ch = 0;
                break;
            }
            default: {
                printf("Wrong Choice\n");
            }
        }
    }
    return 0;
}
               

