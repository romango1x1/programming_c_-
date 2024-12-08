#include <stdio.h>
#include <stdbool.h>

bool is_fibonacci(unsigned int num) {
    if (num == 0 || num == 1) return true;

    unsigned int a = 0, b = 1, fib = 0;

    while (fib < num) {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib == num;
}

int main() {
    int N;

    printf("Введіть розмір масиву (N): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Розмір масиву має бути додатнім числом.\n");
        return 1;
    }

    unsigned int arr[N];
    int count = 0;

    printf("Введіть %d натуральних чисел:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%u", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        if (is_fibonacci(arr[i])) {
            count++;
        }
    }

    printf("Кількість чисел Фібоначчі в масиві: %d\n", count);

    return 0;
}
