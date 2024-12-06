#pragma once

#include <vector>
#include <functional>
#include <iostream>
#include "candle.h" // Для тестов с классом Candle

// Глобальный массив для хранения тестов
extern std::vector<std::function<bool()>> tests;

// Объявления всех тестов
bool test_body_contains_1();
bool test_body_contains_2();
bool test_body_contains_3();

bool test_contains_1();
bool test_contains_2();
bool test_contains_3();

bool test_full_size_1();
bool test_full_size_2();
bool test_full_size_3();

bool test_body_size_1();
bool test_body_size_2();
bool test_body_size_3();

bool test_is_red_1();
bool test_is_red_2();
bool test_is_red_3();

bool test_is_green_1();
bool test_is_green_2();
bool test_is_green_3();

// Функция для инициализации всех тестов
void initTests();

int launchTests();
