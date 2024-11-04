#include<stdio.h>
void exchange(int *p,int *q)
{
	int t=0;
	t=*p;
	*p=*q;
	*q=t;
}
void rotate(int ar[],int n)
{
	for(int i=1;i<n;i++)
	{
		exchange(&ar[0],&ar[i]);
	}
}
int main()
{
	int n=0;
	printf("Enter size of array\n");
	scanf("%d",&n);
	int ar[n];
	int i=0,j=0,t=0,x=0;
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	printf("Given Array \n");
	for(i=0;i<n;i++)
	printf("%d ",ar[i]);
	printf("\nEnter no of elements to rotate\n");
	scanf("%d",&x);
	printf("\nOutput Array\n");
	rotate(ar,x);
	for(i=0;i<n;i++)
	printf("%d ",ar[i]);
	return 0;
}
