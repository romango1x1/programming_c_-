#include <stdio.h>

double leakyReLu(double x, double a) {
    return (x >= 0) ? x : a * x;
}

double leakyReLu_derivative(double x, double a) {
    return (x >= 0) ? 1 : a;
}

int main() {
    double x = -2.0;  // Точка для обчислення
    double a = 0.01;  // Параметр leakyReLu

    printf("leakyReLu(x, a) = %f\n", leakyReLu(x, a));
    printf("leakyReLu'(x, a) = %f\n", leakyReLu_derivative(x, a));

    return 0;
}
