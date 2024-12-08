#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int age;
} Toy;

int compare_toys(const void *a, const void *b) {
    Toy *toy_a = (Toy *)a;
    Toy *toy_b = (Toy *)b;
    return strcmp(toy_a->name, toy_b->name);
}

int main() {
    Toy toys[] = {
        {"A", 300.0, 3},
        {"A", 250.0, 5},
        {"B", 60.0, 6},
        {"B", 22.0, 2},
        {"C", 150.0, 4}
    };

    size_t size = sizeof(toys) / sizeof(toys[0]);

    char search_name[50];
    printf("Введіть ім'я товару для пошуку: ");
    scanf("%s", search_name);

    qsort(toys, size, sizeof(Toy), compare_toys);

    Toy *max_price_toy = NULL;

    for (size_t i = 0; i < size; i++) {
        if (strcmp(toys[i].name, search_name) == 0) {
            if (max_price_toy == NULL || toys[i].price > max_price_toy->price) {
                max_price_toy = &toys[i];
            }
        }
    }

    if (max_price_toy != NULL) {
        printf("Найдорожча іграшка: Іграшка: %s, Ціна: %.2f, Вік: %d\n", max_price_toy->name, max_price_toy->price, max_price_toy->age);
    } else {
        printf("Іграшки з ім'ям %s не знайдено.\n", search_name);
    }

    return 0;
}