#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int main()
{
    FILE *ptr1;
    FILE *ptr2;
    int ar[500];
    char str[100];
    int ch = 0, k = 0, ind = 0, x = 0;
    struct timespec start, end;
    printf("MAIN MENU (MERGE SORT)\n 1. Ascending Data\n 2. Descending Data\n 3. Random Data\n 4. ERROR (EXIT)\n\n");
    printf("Enter choice\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    {
        ptr1 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\inAsce.dat", "r");
        while ((ch = fgetc(ptr1)) != EOF)
        {
            if (ch == ' ' || ch == '\n')
            {
                str[k] = '\0';
                ar[ind++] = atoi(str);
                k = 0;
            }
            else
            {
                str[k++] = ch;
            }
        }
        fclose(ptr1);
        printf("Before Sorting:");
        for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
        printf("\n\n");
        clock_gettime(CLOCK_MONOTONIC, &start);
        mergesort(ar, 0, ind - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        double elapsed = seconds * 1e9 + nanoseconds;
        printf("After Sorting:");
        for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
        printf("\n");
        printf("No Of Comparisons : %d\n", count);
        printf("Execution Time: %.0f ns\n", elapsed);
        break;
    }
    case 2:
    {
        ptr1 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\inDesc.dat", "r");
        while ((ch = fgetc(ptr1)) != EOF)
        {
            if (ch == ' ' || ch == '\n')
            {
                str[k] = '\0';
                ar[ind++] = atoi(str);
                k = 0;
            }
            else
            {
                str[k++] = ch;
            }
        }
        fclose(ptr1);

        printf("Before Sorting:");
        for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
        printf("\n\n");

        clock_gettime(CLOCK_MONOTONIC, &start);
        mmergesort(ar, 0, ind - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        double elapsed = seconds * 1e9 + nanoseconds;

        printf("After Sorting:");
        for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
        printf("\n");
        printf("No Of Comparisons : %d\n", count);
        printf("Execution Time: %.0f ns\n", elapsed);
        break;
    }
    case 3:
    {
        ptr1 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\inRand.dat", "r");
        while ((ch = fgetc(ptr1)) != EOF)
        {
            if (ch == ' ' || ch == '\n')
            {
                str[k] = '\0';
                ar[ind++] = atoi(str);
                k = 0;
            }
            else
            {
                str[k++] = ch;
            }
        }
        fclose(ptr1);

        printf("Before Sorting:");
        for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
        printf("\n\n");

        clock_gettime(CLOCK_MONOTONIC, &start);
        mergesort(ar, 0, ind - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        double elapsed = seconds * 1e9 + nanoseconds;

        printf("After Sorting:");
        for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
        printf("\n");
        printf("No Of Comparisons : %d\n", count);
        printf("Execution Time: %.0f ns\n", elapsed);
        break;
    }
    case 4:
        break;
    default:
        printf("Wrong Choice");
    }
    ptr2 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\outMerge.dat", "w");
    for (int i = 0; i < ind; i++)
        fprintf(ptr2, "%d ", ar[i]);
    fclose(ptr2);
    return 0;
}
