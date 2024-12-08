#include <stdio.h>
#include <stdlib.h>

void process_matrix(int **matrix, int *rows, int *cols) {
    int valid;

    for (int i = 0; i < *rows; i++) {
        valid = 1;
        for (int j = 0; j < *cols; j++) {
            if (matrix[i][j] >= 1) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            for (int k = i; k < *rows - 1; k++) {
                for (int j = 0; j < *cols; j++) {
                    matrix[k][j] = matrix[k + 1][j];
                }
            }
            (*rows)--;
            i--;
        }
    }

    for (int j = 0; j < *cols; j++) {
        valid = 1;
        for (int i = 0; i < *rows; i++) {
            if (matrix[i][j] >= 1) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            for (int k = 0; k < *rows; k++) {
                for (int l = j; l < *cols - 1; l++) {
                    matrix[k][l] = matrix[k][l + 1];
                }
            }
            (*cols)--;
            j--;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **matrix;
    int rows, cols;

    printf("Введіть кількість рядків (N): ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців (M): ");
    scanf("%d", &cols);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Введіть елементи матриці (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nПочаткова матриця:\n");
    print_matrix(matrix, rows, cols);

    process_matrix(matrix, &rows, &cols);

    printf("\nМатриця після обробки:\n");
    print_matrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
