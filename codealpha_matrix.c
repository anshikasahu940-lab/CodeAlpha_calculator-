#include <stdio.h>

#define MAX 10

void inputMatrix(int mat[MAX][MAX], int r, int c) {
    printf("Enter elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for(int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            trans[j][i] = mat[i][j];
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX], trans[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and cols for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(a, r1, c1);

    printf("\n1. Add\n2. Multiply\n3. Transpose of A\nChoice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter rows and cols for Matrix B: ");
        scanf("%d %d", &r2, &c2);
        if(r1!= r2 || c1!= c2) {
            printf("Addition not possible. Size mismatch.\n");
            return 0;
        }
        inputMatrix(b, r2, c2);
        addMatrix(a, b, res, r1, c1);
        printf("Result:\n");
        printMatrix(res, r1, c1);
    }
    else if(choice == 2) {
        printf("Enter rows and cols for Matrix B: ");
        scanf("%d %d", &r2, &c2);
        if(c1!= r2) {
            printf("Multiplication not possible. c1!= r2\n");
            return 0;
        }
        inputMatrix(b, r2, c2);
        multiplyMatrix(a, b, res, r1, c1, c2);
        printf("Result:\n");
        printMatrix(res, r1, r2);
    }
    else if(choice == 3) {
        transposeMatrix(a, trans, r1, c1);
        printf("Transpose:\n");
        printMatrix(trans, c1, r1);
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}
