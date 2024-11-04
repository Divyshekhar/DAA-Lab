#include<stdio.h>
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
	printf("Given Array \n");
	for(i=0;i<n;i++)
	printf("%d ",ar[i]);
	int pref[n];
	printf("\nSum Array \n");
	int s=0;
	for(i=0;i<n;i++)
	{
		s=s+ar[i];
		pref[i]=s;
	}
	for(i=0;i<n;i++)
	printf("%d ",pref[i]);
	return 0;
}
