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

// Тесты для contains
bool test_contains_1() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.contains(15.0);  // Цена внутри
}

bool test_contains_2() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.contains(20.0);  // Граничный случай: равен high
}

bool test_contains_3() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return !candle.contains(21.0); // Цена выше high

// Тесты для full_size
bool test_full_size_1() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.full_size() == 15.0;  // Обычный случай
}

bool test_full_size_2() {
    Candle candle(10.0, 10.0, 10.0, 10.0);
    return candle.full_size() == 0.0;   // Граничный случай: все равны
}

bool test_full_size_3() {
    Candle candle(10.0, 25.0, -5.0, 15.0);
    return candle.full_size() == 30.0; // Свеча пересекает ноль

// Тесты для body_size
bool test_body_size_1() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.body_size() == 5.0;   // Обычный случай
}

bool test_body_size_2() {
    Candle candle(15.0, 20.0, 5.0, 15.0);
    return candle.body_size() == 0.0;   // Граничный случай: тело отсутствует
}

bool test_body_size_3() {
    Candle candle(20.0, 25.0, 15.0, 10.0);
    return candle.body_size() == 10.0;  // Красная свеча

// Тесты для is_red
bool test_is_red_1() {
    Candle candle(20.0, 25.0, 15.0, 10.0);
    return candle.is_red();  // Обычный случай
}

bool test_is_red_2() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return !candle.is_red(); // Зеленая свеча
}

bool test_is_red_3() {
    Candle candle(15.0, 15.0, 15.0, 15.0);
    return !candle.is_red(); // Граничный случай: равны

// Тесты для is_green
bool test_is_green_1() {
    Candle candle(10.0, 20.0, 5.0, 15.0);
    return candle.is_green(); // Обычный случай
}

bool test_is_green_2() {
    Candle candle(20.0, 25.0, 15.0, 10.0);
    return !candle.is_green(); // Красная свеча
}

bool test_is_green_3() {
    Candle candle(15.0, 15.0, 15.0, 15.0);
    return !candle.is_green(); // Граничный случай: равны

// Функция для инициализации всех тестов
void initTests() {
    tests.push_back(test_body_contains_1);
    tests.push_back(test_body_contains_2);
    tests.push_back(test_body_contains_3);

    tests.push_back(test_contains_1);
    tests.push_back(test_contains_2);
    tests.push_back(test_contains_3);

    tests.push_back(test_full_size_1);
    tests.push_back(test_full_size_2);
    tests.push_back(test_full_size_3);

    tests.push_back(test_body_size_1);
    tests.push_back(test_body_size_2);
    tests.push_back(test_body_size_3);

    tests.push_back(test_is_red_1);
    tests.push_back(test_is_red_2);
    tests.push_back(test_is_red_3);

    tests.push_back(test_is_green_1);
    tests.push_back(test_is_green_2);
    tests.push_back(test_is_green_3);
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
