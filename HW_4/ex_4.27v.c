#include <stdio.h>
#include <math.h>

double calculate_pi(double epsilon) {
    double term = sqrt(2);
    double product = term / 2.0;
    double pi_inverse = product;
    int iteration = 1;

    while (fabs(1 - pi_inverse) > epsilon) {
        term = sqrt(2 + term);
        product *= term / 2.0;
        pi_inverse = product;
        iteration++;
    }

    printf("Кількість ітерацій: %d\n", iteration);
    return 2.0 / pi_inverse;
}

int main() {
    double epsilon;

    printf("Введіть точність ε > 0: ");
    scanf("%lf", &epsilon);

    if (epsilon <= 0) {
        printf("Точність повинна бути більшою за 0.\n");
        return 1;
    }

    double pi = calculate_pi(epsilon);
    printf("Обчислене значення π: %.15f\n", pi);

    return 0;
}
