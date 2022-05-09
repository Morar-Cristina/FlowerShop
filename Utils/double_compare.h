//
// Created by zaha on 5/9/22.
//

#include <cmath>

// why the fuck is this not in the standard library?

#ifndef MAIN_CPP_DOUBLE_COMPARE_H
#define MAIN_CPP_DOUBLE_COMPARE_H


class double_compare {
public:
    static bool equal(double a, double b) {
        return fabs(a - b) < 1e-6;
    }

    static bool not_equal(double a, double b) {
        return !equal(a, b);
    }

    static bool less(double a, double b) {
        return a < b && not_equal(a, b);
    }

    static bool less_or_equal(double a, double b) {
        return a < b || equal(a, b);
    }

    static bool greater(double a, double b) {
        return a > b && not_equal(a, b);
    }

    static bool greater_or_equal(double a, double b) {
        return a > b || equal(a, b);
    }
};


#endif //MAIN_CPP_DOUBLE_COMPARE_H
