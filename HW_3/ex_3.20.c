#include <stdbool.h>
#include <stdio.h>

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool is_point_in_triangle(double x, double y,
                          double x1, double y1,
                          double x2, double y2,
                          double x3, double y3) {
    double total_area = triangle_area(x1, y1, x2, y2, x3, y3);

    // Площі трикутників із точкою всередині
    double area1 = triangle_area(x, y, x2, y2, x3, y3);
    double area2 = triangle_area(x1, y1, x, y, x3, y3);
    double area3 = triangle_area(x1, y1, x2, y2, x, y);

    return fabs(total_area - (area1 + area2 + area3));
}

int main() {
    // Координати вершин трикутника
    double x1 = 0, y1 = 0;
    double x2 = 5, y2 = 0;
    double x3 = 0, y3 = 5;

    // Координати точки
    double x = 2, y = 2;

    if (is_point_in_triangle(x, y, x1, y1, x2, y2, x3, y3)) {
        printf("Точка належить трикутнику.\n");
    } else {
        printf("Точка не належить трикутнику.\n");
    }

    return 0;
}
