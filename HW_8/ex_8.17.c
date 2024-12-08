#include <stdio.h>
#include <stdlib.h>

void rotate_blocks(int **matrix, int size) {
    int mid = size / 2;

    for (int layer = 0; layer < mid; layer++) {
        for (int i = layer; i < size - 1 - layer; i++) {
            int temp = matrix[layer][i]; // Верхній лівий елемент

            // Верхній лівий <- Нижній лівий
            matrix[layer][i] = matrix[size - 1 - i][layer];

            // Нижній лівий <- Нижній правий
            matrix[size - 1 - i][layer] = matrix[size - 1 - layer][size - 1 - i];

            // Нижній правий <- Верхній правий
            matrix[size - 1 - layer][size - 1 - i] = matrix[i][size - 1 - layer];

            // Верхній правий <- Верхній лівий
            matrix[i][size - 1 - layer] = temp;
        }
    }
}

// Функція для друку матриці
void print_matrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Введіть n (порядок матриці буде 2n + 1): ");
    scanf("%d", &n);

    int size = 2 * n + 1;
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Введіть елементи матриці %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nПочаткова матриця:\n");
    print_matrix(matrix, size);

    rotate_blocks(matrix, size);

    printf("\nМатриця після обертання блоків на 90 градусів:\n");
    print_matrix(matrix, size);

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
