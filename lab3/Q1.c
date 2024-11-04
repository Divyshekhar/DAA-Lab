#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500

int count = 0;
void merge(int ar[], int lb, int mid, int ub)
{
    int b[500];
    int i = lb, j = mid + 1, k = lb;
    while (i <= mid && j <= ub)
    {
        count++;
        if (ar[i] < ar[j])
            b[k++] = ar[i++];
        else
            b[k++] = ar[j++];
    }
    while (i <= mid)
        b[k++] = ar[i++];
    while (j <= ub)
        b[k++] = ar[j++];
    for (int i = lb; i <= ub; i++)
        ar[i] = b[i];
}

void mergesort(int ar[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(ar, lb, mid);
        mergesort(ar, mid + 1, ub);
        merge(ar, lb, mid, ub);
    }
}

void merger(int ar[], int lb, int mid, int ub)
{
    int n = ub - lb + 1;
    int b[500];
    int i = lb, j = mid + 1, k = lb;
    while (i <= mid && j <= ub)
    {
        count++;
        if (ar[i] > ar[j])
            b[k++] = ar[i++];
        else
            b[k++] = ar[j++];
    }
    while (i <= mid)
        b[k++] = ar[i++];
    while (j <= ub)
        b[k++] = ar[j++];
    for (int i = lb; i <= ub; i++)
        ar[i] = b[i];
}
void mmergesort(int ar[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mmergesort(ar, lb, mid);
        mmergesort(ar, mid + 1, ub);
        merger(ar, lb, mid, ub);
    }
}

void generate(int a, int range)
{
    int random;
    FILE *ptr;
    ptr = fopen("q1.txt", "w");
    if (ptr == NULL)
        printf("Error opening the file");
    for (int i = 0; i < a; i++)
    {
        random = (rand() % (range + 1));
        fprintf(ptr, "%d \n", random);
    }
    fclose(ptr);
}

void readData(char *filename, int arr[], int *size)
{
    FILE *file = fopen("q1.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF)
    {
        i++;
    }
    *size = i;
    fclose(file);
}

void writeData(char *filename, int arr[], int size)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
        printf("error opening file");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d \n", arr[i]);
    }
    fclose(file);
}

int main()
{
    int arr[MAX];
    int size;
    int inp;
    while (1)
    {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1) Ascending\n");
        printf("2) Descending\n");
        printf("3) Random Data\n");
        printf("4) EXIT\n");
        scanf("%d", &inp);

        switch (inp)
        {
        case 1:
            readData("q1.txt", arr, &size);
            mergesort(arr, 0, 4);
            writeData("output.txt", arr, size);
            for (int i = 0; i < 5; i++)
            {
                printf("%d \t", arr[i]);
            }
            break;
        case 2:
            readData("q1.txt", arr, &size);
            mmergesort(arr, 0, 4);
            writeData("output.txt", arr, size);
            break;
        case 3:
            int a;
            int range;
            printf("enter the number you want");
            scanf("%d", &a);
            printf("enter the range");
            scanf("%d", &range);
            generate(a, range);
            break;
        case 4:
            return 0;
            break;
        default: 
            printf("default");
        }
    }
    return 0;
}