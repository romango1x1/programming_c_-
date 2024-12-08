#include <stdio.h>

int count_significant_bits(unsigned int n) {
    int count = 0;

    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }

    return count;
}

int main() {
    unsigned int n;

    printf("Введіть натуральне 32-бітне число: ");
    scanf("%u", &n);

    int significant_bits = count_significant_bits(n);

    printf("Кількість значущих бітів: %d\n", significant_bits);

    return 0;
}
