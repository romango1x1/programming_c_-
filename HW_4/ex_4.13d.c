#include <stdio.h>
#include <math.h>

double calculate_y(int n, double x) {
    double y = 0.0; // Змінна для результату
    double one_minus_x = 1.0 - x;

    for (int k = 0; k <= n; ++k) {
        double term = k * pow(x, k) * pow(one_minus_x, n - k);
        y += term;
    }

    return y;
}

int main() {
    int n;
    double x;

    printf("Введіть натуральне число n (n >= 0): ");
    scanf("%d", &n);

    printf("Введіть число x (0 < x < 1): ");
    scanf("%lf", &x);

    if (n < 0 || x <= 0 || x >= 1) {
        printf("Неправильні вхідні дані. Перевірте, щоб n >= 0 і 0 < x < 1.\n");
        return 1;
    }

    double result = calculate_y(n, x);
    printf("Результат: y = %f\n", result);

    return 0;
}
