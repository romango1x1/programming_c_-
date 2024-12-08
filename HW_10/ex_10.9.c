#include <stdio.h>

// Опис предмета
typedef struct {
    double mass;
    double volume;
} Item;

int findMaxDensityItem(const Item items[], int n) {
    int maxIndex = 0;
    double maxDensity = items[0].mass / items[0].volume;

    for (int i = 1; i < n; i++) {
        double density = items[i].mass / items[i].volume;
        if (density > maxDensity) {
            maxDensity = density;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int n;

    printf("Введіть кількість предметів: ");
    scanf("%d", &n);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Введіть масу та об'єм предмета %d: ", i + 1);
        scanf("%lf %lf", &items[i].mass, &items[i].volume);
    }

    int maxIndex = findMaxDensityItem(items, n);

    printf("Предмет з максимальною густиною:\n");
    printf("Маса: %.2lf, Об'єм: %.2lf, Густина: %.2lf\n",
           items[maxIndex].mass,
           items[maxIndex].volume,
           items[maxIndex].mass / items[maxIndex].volume);

    return 0;
}
