#include "interval.h"

#include <iostream>
#include <stdexcept>
#include <iomanip>

// Реалізація конструктора для Interval
Interval::Interval(IntervalType ta, double aa, IntervalType tb, double bb)
    : type_a(ta), a(aa), type_b(tb), b(bb) {
    if (type_a == FINITE && type_b == FINITE && a > b) {
        throw std::invalid_argument("Invalid interval: a must be less than or equal to b.");
    }
}

// Реалізація методу для виведення інтервалу
void Interval::print(const std::string& label) const {
    std::cout << label << ": ["
              << std::fixed << std::setprecision(6) // Встановлюємо точність до 6 знаків
              << (type_a == INFINITE_NEG ? "-inf" : std::to_string(a))
              << ", "
              << (type_b == INFINITE_POS ? "inf" : std::to_string(b))
              << "]\n";
}

// Реалізація перетину (множення) інтервалів
Interval Interval::intersect(const Interval& i1, const Interval& i2) {
    double new_a = std::max(i1.a, i2.a);
    double new_b = std::min(i1.b, i2.b);
    if (new_a > new_b) {
        throw std::invalid_argument("Intervals do not overlap.");
    }
    return Interval(FINITE, new_a, FINITE, new_b);
}

// Реалізація об'єднання (додавання) інтервалів
Interval Interval::unite(const Interval& i1, const Interval& i2) {
    double new_a = std::min(i1.a, i2.a);
    double new_b = std::max(i1.b, i2.b);
    return Interval(FINITE, new_a, FINITE, new_b);
}

// Реалізація різниці інтервалів
std::vector<Interval> Interval::difference(const Interval& i1, const Interval& i2) {
    if (i2.a > i1.b || i2.b < i1.a) {
        return {i1}; // Немає перетину
    }
    std::vector<Interval> result;
    if (i2.a > i1.a) {
        result.emplace_back(FINITE, i1.a, FINITE, i2.a);
    }
    if (i2.b < i1.b) {
        result.emplace_back(FINITE, i2.b, FINITE, i1.b);
    }
    return result;
}

// Реалізація методу для додавання інтервалів до SetIntervals
void SetIntervals::addInterval(const Interval& interval) {
    intervals.push_back(interval);
}

// Реалізація методу для обчислення довжини всіх інтервалів
double SetIntervals::totalLength() const {
    double length = 0;
    for (const auto& interval : intervals) {
        length += interval.b - interval.a;
    }
    return length;
}

// Реалізація методу для виведення інтервалів
void SetIntervals::print() const {
    for (size_t i = 0; i < intervals.size(); ++i) {
        intervals[i].print("Interval " + std::to_string(i + 1));
    }
}

// Конструктор для QuadraticInequality
QuadraticInequality::QuadraticInequality(double aa, double bb, double cc, Relation rel)
    : a(aa), b(bb), c(cc), relation(rel) {}

// Реалізація методу для розв'язання квадратної нерівності
SetIntervals QuadraticInequality::solve() const {
    double discriminant = b * b - 4 * a * c;
    SetIntervals result;

    if (discriminant < 0) {
        // Якщо дискримінант < 0, то нерівність не має дійсних коренів
        if (relation == GREATER || relation == GREATER_EQUAL) {
            result.addInterval(Interval(INFINITE_NEG, -std::numeric_limits<double>::infinity(), INFINITE_POS, std::numeric_limits<double>::infinity()));
        }
    } else if (discriminant == 0) {
        // Якщо дискримінант = 0, то є один корінь
        double root = -b / (2 * a);
        if (relation == GREATER || relation == GREATER_EQUAL) {
            result.addInterval(Interval(FINITE, root, INFINITE_POS, std::numeric_limits<double>::infinity()));
        } else if (relation == LESS || relation == LESS_EQUAL) {
            result.addInterval(Interval(INFINITE_NEG, -std::numeric_limits<double>::infinity(), FINITE, root));
        }
    } else {
        // Якщо дискримінант > 0, то є два корені
        double x1 = (-b - std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b + std::sqrt(discriminant)) / (2 * a);

        if (relation == GREATER || relation == GREATER_EQUAL) {
            result.addInterval(Interval(FINITE, x2, INFINITE_POS, std::numeric_limits<double>::infinity()));
        } else if (relation == LESS || relation == LESS_EQUAL) {
            result.addInterval(Interval(INFINITE_NEG, -std::numeric_limits<double>::infinity(), FINITE, x1));
        } else if (relation == EQUAL) {
            // Для рівності додаємо точку
            result.addInterval(Interval(FINITE, x1, FINITE, x1));
        }
    }

    return result;
}

int main() {
    Interval i1(FINITE, 1, FINITE, 5);
    Interval i2(FINITE, 3, FINITE, 7);

    // Виведення інтервалів
    i1.print("Interval 1");
    i2.print("Interval 2");

    // Перетин інтервалів
    try {
        Interval intersection = Interval::intersect(i1, i2);
        intersection.print("Intersection of intervals");
    } catch (const std::invalid_argument&) {
        std::cout << "Intervals do not intersect\n";
    }

    // Об'єднання інтервалів
    Interval unionInterval = Interval::unite(i1, i2);
    unionInterval.print("Union of intervals");

    // Різниця інтервалів
    std::vector<Interval> differenceIntervals = Interval::difference(i1, i2);
    if (!differenceIntervals.empty()) {
        for (size_t i = 0; i < differenceIntervals.size(); ++i) {
            differenceIntervals[i].print("Difference of intervals");
        }
    }

    // Множина інтервалів
    SetIntervals setIntervals;
    setIntervals.addInterval(i1);
    setIntervals.addInterval(i2);
    setIntervals.print();
    std::cout << "Total length of intervals: " << setIntervals.totalLength() << "\n";

    // Розв'язок квадратної нерівності
    QuadraticInequality qi(1, -3, 2, QuadraticInequality::GREATER);
    std::cout << "Solution to inequality: \n";
    SetIntervals solution = qi.solve();
    solution.print();

    return 0;
}
