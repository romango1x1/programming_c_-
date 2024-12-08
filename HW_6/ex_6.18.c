#include <stdio.h>

int main() {
    unsigned char n;

    printf("Введіть натуральне однобайтове число (0-255): ");
    scanf("%hhu", &n);

    unsigned char shifted = (n << 1) | (n >> 7);

    printf("Результат циклічного зсуву: %hhu\n", shifted);

    return 0;
}
