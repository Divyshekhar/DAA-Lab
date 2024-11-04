#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

void quicksort(int ar[], int lb, int ub) {
    if (lb < ub) 
	{
        int pos = partition(ar, lb, ub);
        int mid=(lb+ub)/2;
        if(pos==lb || pos==ub)
        wc++;
        else if(pos==mid || pos==mid+1 ||pos==mid-1)
        bc++;
        quicksort(ar, lb, pos - 1);
        quicksort(ar, pos + 1, ub);
    }
}
int partition_desc(int ar[], int lb, int ub) {
    int pivot = ar[lb];
    int i = lb, j = ub;
    while (i < j) {
        while (ar[i] >= pivot) {
            i++;
            count++;
        }
        while (ar[j] < pivot) {
            j--;
            count++;
        }
        if (i < j) {
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[lb], &ar[j]);
    return j;
}

void quickrsort(int ar[], int lb, int ub) {
    if (lb < ub) {
        int pos = partition_desc(ar, lb, ub);
        int mid=(lb+ub)/2;
        if(pos==lb || pos==ub)
        wc++;
        else if(pos==mid || pos==mid+1 ||pos==mid-1)
        bc++;
        quickrsort(ar, lb, pos - 1);
        quickrsort(ar, pos + 1, ub);
    }
}

int main() {
    FILE *ptr1;
    FILE *ptr2;
    int ar[500];
    char str[100];
    int ch = 0, k = 0, ind = 0, x = 0;
    struct timespec start, end;
    printf("MAIN MENU (QUICK SORT)\n 1. Ascending Data\n 2. Descending Data\n 3. Random Data\n 4. ERROR (EXIT)\n\n");
    printf("Enter choice\n");
    scanf("%d", &x);

    switch (x) {
        case 1: {
            ptr1 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\inAsce.dat", "r");
            while ((ch = fgetc(ptr1)) != EOF) {    
                if (ch == ' ' || ch == '\n') {
                    str[k] = '\0';
                    ar[ind++] = atoi(str);
                    k = 0;
                } else {
                    str[k++] = ch;
                }
            }
            fclose(ptr1);
            ptr1 = NULL;

            printf("Before Sorting:");
            for (int i = 0; i < ind; i++)
                printf("%d ", ar[i]);
            printf("\n\n");
            clock_t t; 
    		t = clock();
			quicksort(ar, 0, ind - 1);  
    		t = clock() - t; 
    		double time_taken = ((double)t)/CLOCKS_PER_SEC;  
            printf("After Sorting:");
            for (int i = 0; i < ind; i++)
            printf("%d ", ar[i]);
            printf("\n");
            printf("No Of Comparisons : %d\n", count);
            printf("Execution Time: %.0lf ns\n", time_taken);
            break;
        }
        case 2: {
            ptr1 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\inDesc.dat", "r");

            while ((ch = fgetc(ptr1)) != EOF) {    
                if (ch == ' ' || ch == '\n') {
                    str[k] = '\0';
                    ar[ind++] = atoi(str);
                    k = 0;
                } else {
                    str[k++] = ch;
                }
            }
            fclose(ptr1);
            ptr1 = NULL;

            printf("Before Sorting:");
            for (int i = 0; i < ind; i++)
                printf("%d ", ar[i]);
            printf("\n\n");

            clock_gettime(CLOCK_MONOTONIC, &start);
            quickrsort(ar, 0, ind - 1);
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
        case 3: {
            ptr1 = fopen("C:\\Users\\KIIT\\OneDrive\\Desktop\\5th\\DAA\\DAA Lab\\Lab 3\\inRand.dat", "r");
            while ((ch = fgetc(ptr1)) != EOF) {    
                if (ch == ' ' || ch == '\n') {
                    str[k] = '\0';
                    ar[ind++] = atoi(str);
                    k = 0;
                } else {
                    str[k++] = ch;
                }
            }
            fclose(ptr1);
            ptr1 = NULL;

            printf("Before Sorting:");
            for (int i = 0; i < ind; i++)
                printf("%d ", ar[i]);
            printf("\n\n");

            clock_gettime(CLOCK_MONOTONIC, &start);
            quicksort(ar, 0, ind - 1);
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
    if (ptr2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    for (int i = 0; i < ind; i++)
        fprintf(ptr2, "%d ", ar[i]);
    fclose(ptr2);
    ptr2 = NULL;

    printf("Best-case partitions: %d\n", bc);
    printf("Worst-case partitions: %d\n", wc);

    if (bc > wc) {
        printf("This is a best-case scenario.\n");
    } else {
        printf("This is a worst-case scenario.\n");
    }
    return 0;
}

