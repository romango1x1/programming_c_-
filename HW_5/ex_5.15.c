#include <stdio.h>

int reverse_number(int n, int reversed) {
    if (n == 0) {
        return reversed;
    }
    int next_digit = n % 10;
    return reverse_number(n / 10, reversed * 10 + next_digit);
}

int main() {
    int n;

    printf("Введіть натуральне число: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Число має бути натуральним (n > 0).\n");
        return 1;
    }

    int reversed = reverse_number(n, 0);
    printf("Число у зворотному порядку: %d\n", reversed);

    return 0;
}
