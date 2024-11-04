#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE* ptr;
	char ch;
	int n=0;
	printf("Enter no of integers \n");
	scanf("%d",&n);
	int ar[n];
	char str[100];
	ptr = fopen("/home/divyshekhar/Desktop/cse10_DAA/lab1/file.txt", "r");
	int ind=0,k=0;
	while (ch != EOF)
	{
		ch = fgetc(ptr);
		if(ch==' ')
		{
			str[k++]='\0';
			ar[ind++]=atoi(str);
			k=0;
			if(ind==n)
			break;
		}
		else
		str[k++]=ch;
	}
	fclose(ptr);
	int i=0,j=0,t=0;
	printf("Contents of File :");
	for(i=0;i<n;i++)
	printf("%d ",ar[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ar[i]>ar[j])
			{
				t=ar[i];
				ar[i]=ar[j];
				ar[j]=t;
			}
		}
	}
	int count=0,max=0,x=0;
	i=0;
	while(i<n)
	{
		int c=0;
		j=i+1;
		while(j<n && ar[i]==ar[j])
		{
			c++;
			j++;
		}
		if(c>max)
		{
			max=c;
			x=ar[i];
		}
		i=j;
		if(c>0)
		count++;
	}
	printf("\nTotal number of duplicate values = %d\n",count);
	printf("The most repeating element in the array = %d",x);
	return 0;
}
