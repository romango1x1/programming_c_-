#include <math.h>
#include <stdio.h>

// f(x) = tanh(x)
double th(double x) {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

// f'(x) = 1 - tanh(x)^2
double th_derivative(double x) {
    double tanh_x = th(x);
    return 1 - tanh_x * tanh_x;
}

int main() {
    double x = 1.0;
    printf("f(x) = th(x) = %f\n", th(x));
    printf("f'(x) = th_derivative(x) = %f\n", th_derivative(x));
    return 0;
}
