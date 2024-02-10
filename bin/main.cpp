#include <iostream>
#include "ArraySum.h"

int main() {
    std::vector<double> array =  {-12.34, 56.78, 1.23, -4.56};
    std::pair<int, int> result = ArraySum::sumDigitsOfArrayElements(array);
    std::cout << "Сумма цифр положительных элементов: " << result.first << std::endl;
    std::cout << "Сумма цифр отрицательных элементов: " << result.second << std::endl;

    return 0;
}
