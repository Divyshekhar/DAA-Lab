#include <stdio.h>

int binarySearchLeftmost(int arr[], int size, int target, int *comparisons)
{
    int left = 0, right = size - 1;
    int result = -1; 

    *comparisons = 0; 

    while (left <= right)
    {
        (*comparisons)++; 
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;   
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {2, 3, 7, 7, 7, 11, 12, 12, 20, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int comparisonsLeft = 0;

    int leftmostIndex = binarySearchLeftmost(arr, size, target, &comparisonsLeft);
    if (leftmostIndex != -1)
    {
        printf("Leftmost occurrence of element %d is at index %d\n", target, leftmostIndex);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }
    printf("Number of comparisons made for leftmost search: %d\n", comparisonsLeft);

    return 0;
}

