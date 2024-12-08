#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Введіть натуральне число n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Число n має бути натуральним (n > 0).\n");
        return 1;
    }

    int arr[n];

    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k = (int)sqrt(n);
    int even_count = 0;

    for (int i = 0; i < k; i++) {
        int square = arr[i] * arr[i];
        if (square % 2 == 0) {
            even_count++;
        }
    }

    printf("Кількість парних квадратів серед перших %d елементів: %d\n", k, even_count);

    return 0;
}
