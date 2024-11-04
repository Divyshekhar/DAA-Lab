#include <stdio.h>

struct item
{
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
    float fraction;
};
void swap(struct item *a, struct item *b)
{
    struct item tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(struct item arr[], int N, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left].profit_weight_ratio < arr[max].profit_weight_ratio)
        max = left;
    if (right < N && arr[right].profit_weight_ratio < arr[max].profit_weight_ratio)
        max = right;
    if (max != i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, N, max);
    }
}
void heapSort(struct item arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int n = 0, i = 0, max = 0, s = 0;
    float p = 0;
    printf("Enter no of items\n");
    scanf("%d", &n);
    struct item ar[n];
    for (i = 0; i < n; i++)
    {
        ar[i].item_id = i + 1;
        printf("Enter profit and weight of item no %d :", i + 1);
        scanf("%f%f", &ar[i].item_profit, &ar[i].item_weight);
        ar[i].profit_weight_ratio = ar[i].item_profit / ar[i].item_weight;
        ar[i].fraction = 0;
    }
    heapSort(ar, n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &max);
    for (i = 0; i < n; i++)
    {
        if (s + ar[i].item_weight <= max)
        {
            ar[i].fraction = 1;
            s += ar[i].item_weight;
            p += ar[i].item_profit;
        }
        else
        {
            ar[i].fraction = (max - s) / (ar[i].item_weight);
            p += ar[i].item_profit * (ar[i].fraction);
            s = max;
        }
        if (s == max)
            break;
    }
    printf("Item No     Profit   Weight   Fractional Amount\n");
    for (int i = 0; i < n; i++)
        printf("%d           %f   %f    %f\n", ar[i].item_id, ar[i].item_profit, ar[i].item_weight, ar[i].fraction);
    printf("Net Profit : %f", p);

    return 0;
}