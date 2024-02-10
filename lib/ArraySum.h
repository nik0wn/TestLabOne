#include <vector>
#include <utility>
#ifndef LAB1_ARRAYSUM_H
#define LAB1_ARRAYSUM_H


class ArraySum {
public:
    ArraySum() = default;

    static std::pair<int, int> sumDigitsOfArrayElements(const std::vector<double>& array);

private:
    static int sumDigits(double number);
};


#endif
