#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements of matrix (%d x %d):\n", rows, cols);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) {
    int sum[MAX][MAX];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Result of Addition:\n");
    displayMatrix(sum, rows, cols);
}

// Matrix Multiplication
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int r2, int c2) {
    if(c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }
    int product[MAX][MAX] = {0};
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            for(int k=0; k<c1; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Result of Multiplication:\n");
    displayMatrix(product, r1, c2);
}

// Transpose of a matrix
void transposeMatrix(int mat[MAX][MAX], int rows, int cols) {
    int trans[MAX][MAX];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    printf("Transpose of Matrix:\n");
    displayMatrix(trans, cols, rows);
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and cols of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(a, r1, c1);

    printf("Enter rows and cols of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(b, r2, c2);

    printf("\nMatrix A:\n");
    displayMatrix(a, r1, c1);

    printf("\nMatrix B:\n");
    displayMatrix(b, r2, c2);

    // Addition (only if dimensions match)
    if(r1 == r2 && c1 == c2) {
        addMatrix(a, b, r1, c1);
    } else {
        printf("Matrix addition not possible (dimension mismatch).\n");
    }

    // Multiplication
    multiplyMatrix(a, b, r1, c1, r2, c2);

    // Transpose
    printf("\nTranspose of Matrix A:\n");
    transposeMatrix(a, r1, c1);

    printf("\nTranspose of Matrix B:\n");
    transposeMatrix(b, r2, c2);

    return 0;
}
