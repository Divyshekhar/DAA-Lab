#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
int bc = 0;
int wc = 0;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int ar[], int lb, int ub)
{
    int pivot = ar[lb];
    int i = lb, j = ub;
    while (i < j)
    {
        while (ar[i] <= pivot)
        {
            i++;
            count++;
        }
        while (ar[j] > pivot)
        {
            j--;
            count++;
        }
        if (i < j)
        {
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[lb], &ar[j]);
    return j;
}

void readData(char *filename, int arr[], int *size)
{
    FILE *file = fopen("q2.txt", "r");
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

void quicksort(int ar[], int lb, int ub)
{
    if (lb < ub)
    {
        int pos = partition(ar, lb, ub);
        int mid = (lb + ub) / 2;
        if (pos == lb || pos == ub)
            wc++;
        else if (pos == mid || pos == mid + 1 || pos == mid - 1)
            bc++;
        quicksort(ar, lb, pos - 1);
        quicksort(ar, pos + 1, ub);
    }
}
int partition_desc(int ar[], int lb, int ub)
{
    int pivot = ar[lb];
    int i = lb, j = ub;
    while (i < j)
    {
        while (ar[i] >= pivot)
        {
            i++;
            count++;
        }
        while (ar[j] < pivot)
        {
            j--;
            count++;
        }
        if (i < j)
        {
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[lb], &ar[j]);
    return j;
}

void generate(int a, int range)
{
    int random;
    FILE *ptr;
    ptr = fopen("q2.txt", "w");
    if (ptr == NULL)
        printf("Error opening the file");
    for (int i = 0; i < a; i++)
    {
        random = (rand() % (range + 1));
        fprintf(ptr, "%d \n", random);
    }
    fclose(ptr);
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

void quickrsort(int ar[], int lb, int ub)
{
    if (lb < ub)
    {
        int pos = partition_desc(ar, lb, ub);
        int mid = (lb + ub) / 2;
        if (pos == lb || pos == ub)
            wc++;
        else if (pos == mid || pos == mid + 1 || pos == mid - 1)
            bc++;
        quickrsort(ar, lb, pos - 1);
        quickrsort(ar, pos + 1, ub);
    }
}

int main()
{
    int ar[500];
    int size;
    int inp;
    char str[100];
    int ch = 0, k = 0, ind = 0, x = 0;
    while (1)
    {
        printf("MAIN MENU (Quick Sort)\n");
        printf("1) Ascending\n");
        printf("2) Descending\n");
        printf("3) Random Data\n");
        printf("4) EXIT\n");
        scanf("%d", &inp);

        switch (inp)
        {
        case 1:
        {
            readData("q1.txt", ar, &size);
            printf("\n\n");
            quicksort(ar, 0, ind - 1);
            writeData("output2.txt", ar, size);
            for (int i = 0; i < 5; i++)
            {
                printf("%d \t", ar[i]);
            }
            break;
        }
        case 2:
        {
            readData("q2.txt", ar, &size);
            quickrsort(ar, 0, ind - 1);
            writeData("output2.txt", ar, size);
            break;
        }
        case 3:
        {
            int a;
            int range;
            printf("enter the number you want");
            scanf("%d", &a);
            printf("enter the range");
            scanf("%d", &range);
            generate(a, range);
            break;
        }
        case 4:
            return 0;
            break;
        default:
            printf("Wrong Choice");
        }
    }
    return 0;
}