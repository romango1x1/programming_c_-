#ifndef INTERVALS_H
#define INTERVALS_H

#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

// Перерахування для типів інтервалів
enum IntervalType { FINITE, INFINITE_NEG, INFINITE_POS };

// Структура для інтервалу
struct Interval {
    IntervalType type_a, type_b;
    double a, b;

    Interval(IntervalType ta, double aa, IntervalType tb, double bb);
    void print(const std::string& label) const;

    static Interval intersect(const Interval& i1, const Interval& i2);
    static Interval unite(const Interval& i1, const Interval& i2);
    static std::vector<Interval> difference(const Interval& i1, const Interval& i2);
};

// Клас для множини інтервалів
struct SetIntervals {
    std::vector<Interval> intervals;

    void addInterval(const Interval& interval);
    double totalLength() const;
    void print() const;
};

// Перерахування для типів квадратних нерівностей
struct QuadraticInequality {
    double a, b, c;
    enum Relation { GREATER, LESS, EQUAL, NOT_EQUAL, GREATER_EQUAL, LESS_EQUAL } relation;

    QuadraticInequality(double aa, double bb, double cc, Relation rel);
    SetIntervals solve() const;
};

#endif // INTERVALS_H
