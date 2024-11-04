#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesization
void printOptimalParens(int s[][100], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Matrix Chain Multiplication function
void matrixChainOrder(int p[], int n) {
    int m[100][100], s[100][100];

    // Initialize m table with 0 for diagonal elements
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                // Calculate q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Printing M-table
    printf("M Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j)
                printf("0 ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Printing S-table
    printf("S Table:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i > j)
                printf("0 ");
            else
                printf("%d ", s[i][j] + 1);
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    printOptimalParens(s, 0, n - 1);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[0][n - 1]);
}

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1]; 

    for (int i = 0; i < n; i++) {
        int r, c;
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &r, &c);
        p[i] = r;
        if (i == n - 1) {
            p[i + 1] = c;
        }
    }

    for (int i = 1; i < n; i++) {
        if (p[i] != p[i + 1 - 1]) {
            printf("Incompatible matrix dimensions at A%d and A%d\n", i, i + 1);
            return -1;
        }
    }

    matrixChainOrder(p, n);

    return 0;
}