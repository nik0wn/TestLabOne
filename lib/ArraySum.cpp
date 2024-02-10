#include "ArraySum.h"
#include <cmath>

int ArraySum::sumDigits(double number) {
    int sum = 0;
    number = fabs(number) * 100;

    int intPart = static_cast<int>(round(number));

    while (intPart > 0) {
        sum += intPart % 10;
        intPart /= 10;
    }

    return sum;
}

std::pair<int, int> ArraySum::sumDigitsOfArrayElements(const std::vector<double>& array) {
    int positiveSum = 0;
    int negativeSum = 0;

    for (double number : array) {
        if (number > 0) {
            positiveSum += sumDigits(number);
        } else if (number < 0) {
            negativeSum += sumDigits(number);
        }
    }

    return {positiveSum, negativeSum};
}
