/* 
./program --help
./program --input data.txt --operation mean
./program --input data.txt --operation variance
./program --input data.txt --operation standard_deviation
*/

#include <iostream> 
#include <fstream>
#include <vector> 
#include <string> 
#include <cstdlib> // Для функций C, таких как exit                                                      
#include "mylib.h"

void print_help() {
    std::cout << "Использование: program --input <файл> --operation <операция>\n"; 
    std::cout << "Операции:\n";
    std::cout << "  mean                Вычисление среднего\n"; 
    std::cout << "  variance            Вычисление дисперсии\n"; 
    std::cout << "  standard_deviation  Вычисление среднеквадратичного отклонения\n"; 
    std::cout << "Ключ --help для отображения этой справки.\n"; 
}

// Функция для чтения чисел из файла
std::vector<double> read_numbers_from_file(const std::string& filename) { //Здесь filename передается по константной ссылке (const std::string&). Это делается для того, чтобы избежать копирования строки, что может быть неэффективно, особенно если строка длинная. Использование ссылки позволяет функции работать с оригинальной строкой, не создавая ее копию.
    std::vector<double> numbers; 
    std::ifstream infile(filename); // Открываем файл для чтения
    double number; // Переменная для временного хранения числа

    while (infile >> number) { // Читаем числа из файла
        if (numbers.size() < 100) { 
            numbers.push_back(number); // Добавляем число в вектор
        } else {
            std::cerr << "Превышено максимальное количество чисел (100).\n"; 
            break; 
        }
    }

    if (infile.fail() && !infile.eof()) { // Проверяем, произошла ли ошибка чтения
        std::cerr << "Ошибка чтения файла.\n"; 
    }

    return numbers; // Возвращаем вектор чисел
}

// Основная функция 
int main(int argc, char* argv[]) {
    if (argc < 5) { // Проверяем, достаточно ли аргументов
        std::cerr << "Недостаточно аргументов.\n"; 
        print_help(); 
        exit(0); // Завершаем программу с ошибкой
    }

    std::string input_file; // Переменная для хранения имени входного файла
    std::string operation; // Переменная для хранения операции

    // Обработка аргументов
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--input") { // Если аргумент --input
            if (i + 1 < argc) { // Проверяем, есть ли следующее значение
                input_file = argv[i + 1]; // Сохраняем имя файла
                i++; // Пропускаем следующее значение
            } else {
                std::cerr << "Не указано имя файла.\n"; 
                return EXIT_FAILURE; 
            }
        } else if (std::string(argv[i]) == "--operation") { // Если аргумент --operation
            if (i + 1 < argc) { // Проверяем, есть ли следующее значение
                operation = argv[i + 1]; // Сохраняем операцию
                i++; // Пропускаем следующее значение
            } else {
                std::cerr << "Не указана операция.\n"; 
                return EXIT_FAILURE;
            }
        } else if (std::string(argv[i]) == "--help") { // Если аргумент --help
            print_help(); 
            exit(0);
        }
    }

    // Чтение чисел из файла
    std::vector<double> numbers = read_numbers_from_file(input_file); // Загружаем числа из файла

    try {
        if (operation == "mean") { 
            std::cout << "Среднее: " << Statistics::mean(numbers) << std::endl; 
        } else if (operation == "variance") { 
            std::cout << "Дисперсия: " << Statistics::variance(numbers) << std::endl; 
        } else if (operation == "standard_deviation") { 
            std::cout << "Среднеквадратичное отклонение: " << Statistics::standard_deviation(numbers) << std::endl; 
        } else {
            std::cerr << "Неизвестная операция: " << operation << std::endl; 
            print_help(); 
            return EXIT_FAILURE; 
        }
    } catch (const std::invalid_argument &e) { 
        std::cerr << e.what() << std::endl; 
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS; 
}