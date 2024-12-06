#include "tests.h"

// Глобальный массив для хранения тестов
std::vector<std::function<bool()>> tests;

// Тесты для body_contains
bool test_body_contains_1() {
    Candle candle(10.0, 20.0, 5.0, 15.0); // Зеленая свеча
    return candle.body_contains(12.0);   // Цена внутри тела
}

bool test_body_contains_2() {
    Candle candle(15.0, 20.0, 5.0, 10.0); // Красная свеча
    return candle.body_contains(15.0);   // Граничный случай: равен open
}

bool test_body_contains_3() {
    Candle candle(10.0, 20.0, 5.0, 15.0); // Зеленая свеча
    return !candle.body_contains(5.0);   // Цена вне тела
}

// Функция для инициализации всех тестов
void initTests() {
    tests.push_back(test_body_contains_1);
    tests.push_back(test_body_contains_2);
    tests.push_back(test_body_contains_3);
}

int launchTests()
{
    int total = 0;
    int passed = 0;

    for (const auto& test : tests)
    {
        std::cout << "test #" << (total + 1);
        if (test())
        {
            passed += 1;
            std::cout << " passed\n";
        }
        else
        {
            std::cout << " failed\n";
        }
        total += 1;
    }

    std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

    return total - passed;
}
