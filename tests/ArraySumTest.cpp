#include "ArraySum.h"
#include <gtest/gtest.h>
#include <vector>

// Тест на пустой массив
TEST(ArraySumTest, HandlesEmptyArray) {
    std::vector<double> array = {};
    auto [positiveSum, negativeSum] = ArraySum::sumDigitsOfArrayElements(array);
    EXPECT_EQ(positiveSum, 0);
    EXPECT_EQ(negativeSum, 0);
}

// Тест на массив с положительными числами
TEST(ArraySumTest, HandlesPositiveNumbers) {
    std::vector<double> array = {12.34, 56.78};
    auto [positiveSum, negativeSum] = ArraySum::sumDigitsOfArrayElements(array);
    EXPECT_EQ(positiveSum, 36);
    EXPECT_EQ(negativeSum, 0);
}

// Тест на массив с отрицательными числами
TEST(ArraySumTest, HandlesNegativeNumbers) {
    std::vector<double> array = {-12.34, -56.78};
    auto [positiveSum, negativeSum] = ArraySum::sumDigitsOfArrayElements(array);
    EXPECT_EQ(positiveSum, 0);
    EXPECT_EQ(negativeSum, 36); // 1+2+3+4 + 5+6+7+8 = 36
}

// Тест на массив с положительными и отрицательными числами
TEST(ArraySumTest, HandlesMixedNumbers) {
    std::vector<double> array = {-12.34, 56.78, 1.23, -4.56};
    auto [positiveSum, negativeSum] = ArraySum::sumDigitsOfArrayElements(array);
    EXPECT_EQ(positiveSum, 32); // 5+6+7+8 + 1+2+3 = 32
    EXPECT_EQ(negativeSum, 25); // 1+2+3+4 + 4+5+6 = 25
}

// Тест на массив с числами имеющими ноль в дробной части
TEST(ArraySumTest, HandlesZeroDecimalNumbers) {
    std::vector<double> array = {100.0, -200.0};
    auto [positiveSum, negativeSum] = ArraySum::sumDigitsOfArrayElements(array);
    EXPECT_EQ(positiveSum, 1); // 1+0+0 = 1
    EXPECT_EQ(negativeSum, 2); // 2+0+0 = 2
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}