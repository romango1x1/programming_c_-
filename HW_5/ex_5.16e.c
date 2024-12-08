#include <stdio.h>
#include <math.h>

double calculate_sum(double x, double epsilon) {
    double S = 0.0;
    double term = 1.0;
    int k = 1;

    while (fabs(term) >= epsilon) {
        S += term;
        term *= -((double)(k + 1) * (k + 2) / 2) * x;
        k++;
    }

    return S;
}

int main() {
    double x, epsilon;

    printf("Введіть x (|x| < 1): ");
    scanf("%lf", &x);

    if (fabs(x) >= 1) {
        printf("Неправильне значення x. Має бути |x| < 1.\n");
        return 1;
    }

    printf("Введіть точність ε > 0: ");
    scanf("%lf", &epsilon);

    if (epsilon <= 0) {
        printf("Точність має бути більшою за 0.\n");
        return 1;
    }

    double result = calculate_sum(x, epsilon);
    printf("Обчислене значення y: %.15f\n", result);

    return 0;
}
