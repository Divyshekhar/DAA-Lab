#include <stdio.h>
int convert_to_binary(int a)
{
    if (a > 1)
        convert_to_binary(a / 2);
    printf("%d", a % 2);
}

void store(int a){
    FILE *fptr = fopen("output.txt", "w");
    fprintf(fptr, convert_to_binary(a));

    fclose(fptr);

}

int main()
{
       store(12);
    // int a ;
    // printf("enter the number");
    // scanf("%d", &a);
    // convert_to_binary(a);

    return 0;
}

/*
#include <stdio.h>

// Function to convert a number to binary and store it in a string
void convert_to_binary(int a, char* binary_representation, int* index) {
    if (a > 1) {
        convert_to_binary(a / 2, binary_representation, index);
    }
    binary_representation[(*index)++] = (a % 2) + '0';
    binary_representation[*index] = '\0'; // Null-terminate the string
}

// Function to store the binary representation in a file
void store(int a) {
    FILE *fptr = fopen("output.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    char binary_representation[32] = {0}; // 32 bits max for an int
    int index = 0;
    convert_to_binary(a, binary_representation, &index);
    
    fprintf(fptr, "%s", binary_representation);
    fclose(fptr);
}

int main() {
    store(12);
    return 0;
}

*/