#include<stdio.h>
int main(){
    FILE * fptr;
    fptr = fopen("test.txt", "r");
    char n;
    fgets(n, 1, fptr);
    printf("%d", n);
    return 0;
}