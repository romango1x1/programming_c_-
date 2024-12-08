#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, M;
    int **matrix;
    int *valid_columns;

    printf("Введіть кількість рядків (N): ");
    scanf("%d", &N);
    printf("Введіть кількість стовпців (M): ");
    scanf("%d", &M);

    matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }

    valid_columns = (int *)malloc(M * sizeof(int));

    printf("Виберіть спосіб заповнення матриці:\n");
    printf("1 - Заповнити випадковими числами\n");
    printf("2 - Ввести з консолі\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        srand(time(NULL));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = rand() % 20 - 10;
            }
        }
    } else if (choice == 2) {
        printf("Введіть елементи матриці (%dx%d):\n", N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
    } else {
        printf("Невірний вибір. Завершення програми.\n");
        return 0;
    }

    printf("\nПочаткова матриця:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    for (int j = 0; j < M; j++) {
        int is_valid = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] >= 1) {
                is_valid = 1;
                break;
            }
        }
        valid_columns[j] = is_valid;
    }

    printf("\nМатриця після видалення стовпців, де всі елементи менше 1:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (valid_columns[j]) {
                printf("%4d", matrix[i][j]);
            }
        }
        printf("\n");
    }


    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(valid_columns);

    return 0;
}
