#ifndef MYLIB_H // Проверяем, определен ли MYLIB_H
#define MYLIB_H // Если не определен, определяем MYLIB_H

#include <vector>

// Определяем класс Statistics
class Statistics {
public:
    // Функция для вычисления среднего
    static double mean(const std::vector<double>& numbers);

    // Функция для вычисления дисперсии
    static double variance(const std::vector<double>& numbers);

    // Функция для вычисления среднеквадратичного отклонения
    static double standard_deviation(const std::vector<double>& numbers);
};

#endif 