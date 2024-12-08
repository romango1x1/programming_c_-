#include <stdio.h>
#include <math.h>

double median(double a, double b, double c) {
    return sqrt(2 * b * b + 2 * c * c - a * a) / 2;
}

double bisector(double a, double b, double c) {
    return (2 * sqrt(b * c * (b + c - a) * (b + c + a))) / (b + c);
}

double height(double a, double b, double c) {
    double s = (a + b + c) / 2; // Півпериметр
    double area = sqrt(s * (s - a) * (s - b) * (s - c)); // Площа за формулою Герона
    return (2 * area) / a;
}

int main() {
    double a, b, c;

    printf("Введіть довжину сторони a: ");
    scanf("%lf", &a);
    printf("Введіть довжину сторони b: ");
    scanf("%lf", &b);
    printf("Введіть довжину сторони c: ");
    scanf("%lf", &c);

    if (a + b > c && a + c > b && b + c > a) {
        printf("\nМедіани:\n");
        printf("Медіана до сторони a: %.2f\n", median(a, b, c));
        printf("Медіана до сторони b: %.2f\n", median(b, a, c));
        printf("Медіана до сторони c: %.2f\n", median(c, a, b));

        printf("\nБісектриси:\n");
        printf("Бісектриса до сторони a: %.2f\n", bisector(a, b, c));
        printf("Бісектриса до сторони b: %.2f\n", bisector(b, a, c));
        printf("Бісектриса до сторони c: %.2f\n", bisector(c, a, b));

        printf("\nВисоти:\n");
        printf("Висота до сторони a: %.2f\n", height(a, b, c));
        printf("Висота до сторони b: %.2f\n", height(b, a, c));
        printf("Висота до сторони c: %.2f\n", height(c, a, b));
    } else {
        printf("Трикутник з такими сторонами не існує.\n");
    }

    return 0;
}
