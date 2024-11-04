#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int main()
{
    FILE * ptr;
    char str[100];
    int n = 2;
	ptr = fopen("/home/divyshekhar/Desktop/cse10_DAA/lab1/file.txt", "r");
    char ch;
	int arr[n];
    int ind = 0;
    int k =0;
   while (ch != EOF)
	{
		ch = fgetc(ptr);
		if(ch==' ')
		{
			str[k++]=NULL;
			arr[ind++]=atoi(str);
			k=0;
			if(ind==n)
			break;
		}
		else
		str[k++]=ch;
	}
	fclose(ptr);
 
printf("the content of the file is:");
for(int i = 0; i < n; i++)
{
    printf("%d ", arr[i]);
}
printf("\nThe GCD of the above numbers are:%d", gcd(arr[0], arr[1]));
  return 0;
}