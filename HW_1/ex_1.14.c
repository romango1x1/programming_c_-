#include <stdio.h>

int main() {
    double a, t, v;

    printf("Введіть прискорення (a): ");
    scanf("%lf", &a);

    printf("Введіть час (t): ");
    scanf("%lf", &t);

    printf("Введіть швидкість (v): ");
    scanf("%lf", &v);

    double s = 0.5 * a * t * t;
    printf("Відстань, яку пройде тіло за час t: %.2f м\n", s);

    double time_to_reach_v = v / a;
    printf("Час, за який тіло досягне швидкості v: %.2f с\n", time_to_reach_v);

    return 0;
}
