#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int main()
{
	int n=0;
	printf("Enter size of array\n");
	scanf("%d",&n);
	int ar[n];
	int i=0,j=0,t=0;
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	if(n<2)
	printf("Invalid Input\n");
	else
	{
		int first,second;
		first=second=INT_MIN;
		for(int i=0;i<n;i++)
		{
			if(ar[i]>first)
			{
				second=first;
				first=ar[i];
			}
			else if(ar[i]>second && ar[i]!=first)
			second=ar[i];
		}
		if(second==INT_MIN)
		printf("No Second Max\n");
		else
		printf("2nd Largest : %d\n",second);
		first=second=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(ar[i]<first)
			{
				second=first;
				first=ar[i];
			}
			else if(ar[i]<second && ar[i]!=first)
			second=ar[i];
		}
		if(second==INT_MAX)
		printf("No Second Min\n");
		else
		printf("2nd Smallest : %d\n",second);
	}
	return 0;
}
