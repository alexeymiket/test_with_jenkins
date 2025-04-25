#include "mylib.h"
#include <stdexcept> // Для обработки исключений
#include <cmath> 

// Вычисление среднего
double Statistics::mean(const std::vector<double>& numbers) {
    if (numbers.empty()) { // Проверяем, пуст ли вектор
        throw std::invalid_argument("Список чисел пуст."); 
    }
    double sum = 0.0; 
    for (double num : numbers) { // Проходим по всем числам в векторе
        sum += num;
    }
    return sum / numbers.size(); // Возвращаем среднее значение
}

// Вычисление дисперсии
double Statistics::variance(const std::vector<double>& numbers) {
    if (numbers.empty()) { // Проверяем, пуст ли вектор
        throw std::invalid_argument("Список чисел пуст."); 
    }
    double avg = mean(numbers); // Вычисляем среднее
    double var_sum = 0.0; // Cумма квадратов отклонений
    for (double num : numbers) { 
        var_sum += (num - avg) * (num - avg); // Считаем квадрат отклонения от среднего
    }
    return var_sum / numbers.size(); // Возвращаем дисперсию
}

// Вычисление среднеквадратичного отклонения
double Statistics::standard_deviation(const std::vector<double>& numbers) {
    return std::sqrt(variance(numbers)); // Возвращаем квадратный корень из дисперсии
}